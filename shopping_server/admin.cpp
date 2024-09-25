#include "admin.h"

extern int RES;
static Myadmin *admin = NULL;

void admin_sigal_functoin_meb(int sig, siginfo_t *info, void *sd) // 35
{
   if (admin == NULL)
      return;
   sigval_t sig_val = info->si_value;

   char buf[50] = {0};
   sprintf(buf, "1\n0\n%s", (char *)sig_val.sival_ptr);
   write(admin->get_socket(), buf, sizeof(buf));

   RES = 34; // 释放资源
}

void admin_sigal_functoin_shopp(int sig, siginfo_t *info, void *sd) // 36
{
   if (admin == NULL)
      return;
   sigval_t sig_val = info->si_value;

   char buf[50] = {0};
   sprintf(buf, "2\n0\n%s", (char *)sig_val.sival_ptr);
   write(admin->get_socket(), buf, sizeof(buf));
   RES = 34; // 释放资源
}

Myadmin::Myadmin(ret_client *client)
{

   m_socket = client->client_socket;
   m_sql = client->my_sql;
   admin = this;

   sig_meb.sa_sigaction = admin_sigal_functoin_meb;
   sig_meb.sa_flags = SA_SIGINFO;
   sigaction(35, &sig_meb, NULL);

   sig_shopp.sa_sigaction = admin_sigal_functoin_shopp;
   sig_shopp.sa_flags = SA_SIGINFO;
   sigaction(36, &sig_shopp, NULL);

   meb_Init();
   usleep(500000);
   shopp_Init();
}

Myadmin::~Myadmin()
{
   admin = NULL;
   if (RES == 35 || RES == 36) // 如果在占用状态退出,释放资源
   {
      RES = 34;
   }
}

int Myadmin::read_operate(std::string &str)
{
   char buf[200] = {0};
   if (read(m_socket, buf, sizeof(buf)) <= 0)
   {
      return 0;
   }

   std::string str1, str2;
   str2 = buf;
   str = str2.erase(0, 2);

   str1 += buf[0];
   str1 += buf[1];

   int num = 0;
   std::istringstream ss(str1);
   ss >> num;

   return num;
}

int Myadmin::get_socket()
{
   return m_socket;
}

void Myadmin::get_start_meb() // 0
{

   if (RES == 34) // 申请到资源
   {
      write(m_socket, "1\n1\n", 10);
      RES = 35;
   }
   else
   {
      write(m_socket, "10\n", 5); // 资源被占用
   }
}

void Myadmin::get_start_shop() // 1
{

   if (RES == 34) // 申请到资源
   {
      write(m_socket, "2\n1\n", 10);
      RES = 36;
   }
   else
   {
      write(m_socket, "10\n", 5); // 资源被占用
   }
}

void Myadmin::m_register(std::string str) // 注册
{
   std::string cod = str.substr(0, 8);

   if (iszhuce(cod))
   {
      write(m_socket, "3\n0\n", 10);
      return;
   }

   std::string number = str.substr(str.length() - 11, 11);
   std::string nname = str.substr(8, str.length() - 11 - 8);

   char buf[500] = {0};
   char text_buf[100] = {0};

   sprintf(buf, "insert INTO users(id,phone,name,balance) values  ('%s','%s','%s','0')", cod.c_str(), number.c_str(), nname.c_str());
   if (m_sql.Dml_sql(buf))
   {
      sprintf(text_buf, "用户:%s 号码:%s 卡号:%s 成功注册", nname.c_str(), number.c_str(), cod.c_str());
      set_send_rizhi(text_buf);

      write(m_socket, "3\n1\n", 10);
   }
   else
   {
      sprintf(text_buf, "用户:%s 号码:%s 注册失败,稍后再试", nname.c_str(), number.c_str());
      set_send_rizhi(text_buf);

      write(m_socket, "3\n0\n", 10);
   }
}

void Myadmin::m_rech(std::string str) // 充值
{
   std::string pid = str.substr(0, 8);
   std::string balance = str.substr(8, std::string::npos);

   char buf[500] = {0};
   char text_buf[100] = {0};

   int num = 0;
   std::istringstream ss(balance);
   ss >> num;

   sprintf(buf, "UPDATE users SET balance =balance+%d where id='%s' ", num, pid.c_str());

   if (m_sql.Dml_sql(buf))
   {
      char buf[500] = {0};
      sprintf(buf, "select id,name,phone,balance  from  users where id='%s' ", pid.c_str());
      std::string sendbuf = m_sql.Dql_sql(buf);
      sendbuf.insert(0, "4\n");

      sprintf(text_buf, "用户: %s 成功充值: %s", pid.c_str(), balance.c_str());
      set_send_rizhi(text_buf);

      write(m_socket, sendbuf.c_str(), sendbuf.size());
   }
   else
   {
      sprintf(text_buf, "用户: %s 充值失败", str.c_str());
      set_send_rizhi(text_buf);
   }
}

void Myadmin::m_select(string str) // 查询
{
   char buf[500] = {0};
   sprintf(buf, "select  id,name,phone,balance  from users where phone='%s' ", str.c_str());
   std::string ret = m_sql.Dql_sql(buf);

   if (ret == "0")
   {
      write(m_socket, "5\n1\n", 10);
   }
   else
   {
      std::string sendstr = ret.insert(0, "5\n0\n");
      write(m_socket, sendstr.c_str(), sendstr.size());
   }
}

void Myadmin::m_logout(std::string str) // 注销
{
   char buf[500] = {0};
   char text_buf[100] = {0};
   sprintf(buf, "DELETE FROM users WHERE id='%s' ", str.c_str());
   std::cout << buf << std::endl;
   if (m_sql.Dml_sql(buf))
   {
      sprintf(text_buf, "用户(卡号): %s 成功注销", str.c_str());
      set_send_rizhi(text_buf);
   }
   else
   {
      sprintf(text_buf, "用户(卡号): %s 注销失败", str.c_str());
      set_send_rizhi(text_buf);
   }
}
void Myadmin::m_stop() // 全删除
{
   if (m_sql.Dml_sql(" TRUNCATE TABLE users"))
   {
      set_send_rizhi("清空商品");
   }
}
void Myadmin::add_shopp(std::string str) // 添加商品
{
   std::string cod = str.substr(0, 8);

   if (iszhuce(cod))
   {
      write(m_socket, "6\n0\n", 10);
      return;
   }

   int a1 = str.find('$');
   int a2 = str.find('&');
   std::string name = str.substr(8, a1 - 8);
   std::string price = str.substr(a1 + 1, a2 - a1 - 1);
   std::string pp = str.substr(a2 + 1, std::string::npos);

   char buf[500] = {0};
   char text_buf[100] = {0};

   sprintf(buf, "insert INTO me(pid,pname,price,brand) values  ('%s','%s','%s','%s')", cod.c_str(), name.c_str(), price.c_str(), pp.c_str());
   if (m_sql.Dml_sql(buf))
   {
      sprintf(text_buf, "添加商品(卡号): %s    价格: %s", name.c_str(), price.c_str());
      set_send_rizhi(text_buf);

      write(m_socket, "6\n1\n", 10);
   }
   else
   {
      sprintf(text_buf, "添加商品(卡号): %s 失败", name.c_str());
      set_send_rizhi(text_buf);

      write(m_socket, "6\n0\n", 10);
   }
}

void Myadmin::rm_shopp(std::string str) // 删除商品
{

   char buf[500] = {0};
   sprintf(buf, "DELETE FROM me WHERE pid='%s' ", str.c_str());
   if (m_sql.Dml_sql(buf))
   {
      std::string str_buf = "删除商品(卡号): ";
      str_buf.append(str);
      set_send_rizhi(str_buf);
   }
   else
   {
      std::string str_buf = "删除商品失败";
      set_send_rizhi(str_buf);
   }
}

void Myadmin::m_textedit() // 记录
{
   int fd = open("./text.txt", O_RDWR | O_CREAT, S_IRWXU | S_IRGRP | S_IROTH);
   if (-1 == fd)
      return;
   off_t off = lseek(fd, 0, SEEK_SET);
   if (-1 == off)
      return;

   char buf[5000] = {0};
   size_t readsize = read(fd, buf, 5000);
   if (readsize == -1)
   {
      perror("read error");
      return;
   }
   else if (readsize == 0)
   {
      write(m_socket, "7\n暂无销售记录", 20);
   }
   else if (readsize > 0)
   {
      std::string sendbuf = "7\n";
      sendbuf.append(buf);
      write(m_socket, sendbuf.c_str(), sendbuf.size());
   }

   close(fd);
}

bool Myadmin::iszhuce(std::string id)
{
   char buf1[500] = {0};
   sprintf(buf1, "select pname from me where pid='%s' ", id.c_str());
   std::string ret1 = m_sql.Dql_sql(buf1);

   char buf2[500] = {0};
   sprintf(buf2, "select name from users where id='%s' ", id.c_str());
   std::string ret2 = m_sql.Dql_sql(buf2);

   if (ret1 == "0" && ret2 == "0")
   {
      return false;
   }
   else
   {
      return true;
   }
}

void Myadmin::shopp_Init()
{
   std::string ret = m_sql.Dql_sql("select * from me ");
   ret.insert(0, "9\n");
   write(m_socket, ret.c_str(), ret.size());
}

void Myadmin::set_send_rizhi(std::string str)
{
   char buf[200] = {0};
   sprintf(buf, "%s\r\n", str.c_str());

   time_t timep;
   time(&timep); // 获取从1970至今过了多少秒，存入time_t类型的timep
   // printf("%s", asctime(localtime(&timep)));//用localtime将秒数转化为struct tm结构体，再用asctime将结构体转化成字符串格式
   std::string sendbuf = "11\n";
   sendbuf.append(asctime(localtime(&timep)));
   sendbuf += buf;
   write(m_socket, sendbuf.c_str(), sendbuf.size());

   usleep(100000); // 防止粘包
}

void Myadmin::meb_Init()
{
   std::string ret = m_sql.Dql_sql("select id,name,phone,balance  from users");
   ret.insert(0, "8\n");
   cout << ret << endl;
   write(m_socket, ret.c_str(), ret.size());
}