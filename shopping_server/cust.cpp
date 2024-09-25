#include "cust.h"

/**
 * 下述所有代码中发出的带数组的信号都用于在QT客户端cust中读取出来用以执行不同的操作
 */

Mycust *cust = NULL;
extern Mymcu *mcu;
extern int RES;

//以下是两个信号处理函数，在本类的构造函数中与信号进行绑定
void cust_sigal_functoin_add(int sig, siginfo_t *info, void *sd) // 34
{
   if (cust == NULL)
      return;

   sigval_t sig_val = info->si_value;
   cust->addshopp((char *)sig_val.sival_ptr); // 商品添加
}

void cust_sigal_functoin_checkout(int sig, siginfo_t *info, void *sd) // 37
{
   if (cust == NULL)
      return;

   sigval_t sig_val = info->si_value;
   cust->checkout((char *)sig_val.sival_ptr); // 结帐函数调用
   cust->setzeor();

   RES = 34;
}

void Mycust::addshopp(std::string str)
{
   char buf[1024];
   sprintf(buf, "select * from me where pid='%s'", str.c_str());

   std::string ret = m_sql.Dql_sql(buf);
   if (ret == "0")
   {
      write(m_socket, "4\n", 4);
   }
   else
   {
      ret.insert(0, "1\n");
      write(m_socket, ret.c_str(), ret.size());
   }
}

void Mycust::setzeor()
{
   m_money = 0;
}

Mycust::Mycust(ret_client *client)
{
   cust = this; // 给全局变量赋值

   m_socket = client->client_socket;
   m_sql = client->my_sql;

   sig_add.sa_sigaction = cust_sigal_functoin_add;
   sig_add.sa_flags = SA_SIGINFO;
   sigaction(34, &sig_add, NULL); // 作用：将信号处理程序cust_sigal_functoin_add与34信号关联，程序将会等待接收信号

   sig_checkout.sa_sigaction = cust_sigal_functoin_checkout;
   sig_checkout.sa_flags = SA_SIGINFO;
   sigaction(37, &sig_checkout, NULL);
}

//服务器接收来自STM32的温湿度信息，这里将温湿度信息通过Socket发送给QT上位机界面
void Mycust::send_wunshidu(std::string str)
{
   str.insert(0, "7\n");   //原本为“hello”，插入后为“7\nhello”
   write(m_socket, str.c_str(), str.size());
   usleep(20000); // 防止粘包
}

int Mycust::read_operate(std::string &str)
{
   char buf[1000] = {0};
   if (read(m_socket, buf, sizeof(buf)) <= 0)
   {
      return 0;
   }

   std::string str1, str2;
   str2 = buf;
   /**
    * 从客户端的cust.pro工程中的widget.cpp文件中得到的
    * 当点击结账按钮时会发出一个标识符1，要求进行刷卡支付；在支付超时的情况下，会发出一个标识符2；没有标识符3
    */
   str = str2.erase(0, 1); 
   str1 += buf[0];
   int num = 0;
   std::istringstream ss(str1);
   ss >> num;

   return num;
}

Mycust::~Mycust()
{
   cust = NULL;
   if (RES == 37)
      RES = 34; // 如果在结帐状态退出,释放资源
}

void Mycust::addtest(std::string str)
{
   std::string number = str.substr(0, 11);
   std::string text = str.substr(11, std::string::npos);

   char buf[1024];
   sprintf(buf, "select text  from users where phone='%s'", number.c_str());
   std::string ret = m_sql.Dql_sql(buf);

   if (ret.append(text).size() > 1000) // 数据大小大于900清空
   {
      ret.clear();
      ret += text;
   }

   char buf1[1024] = {0};
   sprintf(buf1, "UPDATE users SET text='%s' where phone='%s' ", ret.c_str(), number.c_str());
   if (m_sql.Dml_sql(buf1)) // cout<<"添加text文本成功:"<<endl;
   {
      writetext(text); // 记录到服务器
   }
}

void Mycust::writetext(std::string str)
{

   int fd = open("./text.txt", O_RDWR | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH);
   if (-1 == fd)
      return;

   char readbuf[10000] = {0};

   off_t re_off = lseek(fd, 0, SEEK_SET);
   if (-1 == re_off)
      return;
   size_t ret_read = read(fd, readbuf, sizeof(readbuf));

   if (ret_read == -1)
   {
      close(fd);
      return;
   }
   else if (ret_read >= 0)
   {
      if (ret_read + str.size() > 10000)
      {
         if (0 > ftruncate(fd, 0))
         {
            perror("ftruncate error");
            close(fd);
         }
      }
      off_t wri_off = lseek(fd, 0, SEEK_END);
      if (-1 == wri_off)
         return;
      write(fd, str.c_str(), str.size());
      close(fd);
   }
}

void Mycust::get_start_rfid(std::string str) // 1 获取资源
{
   if (RES != 34)
   {
      //不为34表示读卡器正忙，将2发送至QT，界面上提示读卡器正忙
      write(m_socket, "2\n", 10);
      return;
   }

   std::istringstream ss(str);
   ss >> m_money;

   //等待刷卡支付
   RES = 37;
   write(m_socket, "6\n", 10);
}

void Mycust::delete_start_rfid() // 2 释放资源               支付完成释放资源
{
   if (RES == 37)
   {
      RES = 34;
   }
}

void Mycust::checkout(std::string str) // 3  结帐
{
   char buf[1024];
   sprintf(buf, "select name,phone,balance  from users where id='%s'", str.c_str());

   std::string ret = m_sql.Dql_sql(buf);

   if (ret == "0")
   {
      write(m_socket, "4\n", 5);
   }
   else
   {
      // 用户#电话#余额
      std::string name = ret.substr(0, ret.find('#'));
      std::string phone = ret.substr(ret.find('#') + 1, 11);
      std::string palance = ret.substr(ret.find('#') + 11 + 2, std::string::npos);

      int num = 0;
      std::istringstream ss(palance);
      ss >> num;
      //这个num代表卡内余额，m_money代表购物车中的价格
      if (num < m_money)
      {
         ret.insert(0, "5\n");
         write(m_socket, ret.c_str(), ret.size());
         return;
      }
      char buf_up[100] = {0};
      sprintf(buf_up, "UPDATE users SET balance =balance-%d where id='%s' ", m_money, str.c_str());
      m_sql.Dml_sql(buf_up);

      char sendbuf[100] = {0};

      sprintf(sendbuf, "3\n%s#%s#%s\n", name.c_str(), phone.c_str(), to_string(num - m_money).c_str());
      write(m_socket, sendbuf, sizeof(sendbuf));

      if (mcu != NULL)
         mcu->send_mcutext();
   }
   delete_start_rfid(); // 释放资源
}
