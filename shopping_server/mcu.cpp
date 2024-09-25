#include "mcu.h"

extern int RES;              // 定义于main.cpp，默认值为34
extern Myandroid *P_android; // 定义于android.cpp
extern Mycust *cust;         // 定义于cust.cpp

Mymcu *mcu = NULL;

Mymcu::Mymcu(ret_client *client)
{
  m_socket = client->client_socket;
  m_sql = client->my_sql;
  mcu = this;
}

void Mymcu::send_mcutext()
{
  write(m_socket, "123\r\n", 10); // 将指定数量的字节从buf写入Filehandle
}

int Mymcu::getsocket()
{
  return m_socket;
}

int Mymcu::read_operate(std::string &str)
{
  char buf[200] = {0};
  if (read(m_socket, buf, sizeof(buf)) <= 0) // 从连接到的socket中读取流，存到buf中，如果没有收到就返回0
  {
    return 0;
  }
  cout << "收到MCU:" << buf << endl;
  std::string str1, str2;
  str2 = buf;             // 将字符数组buf转换为string类型赋值给str2
  str = str2.erase(0, 1); // str被裁剪到只剩卡号
  /**
   * abc.c文件 -> 单片机中的程序：Serial_Printf("1%02X%02X%02X%02X", cardID[0], cardID[1], cardID[2], cardID[3]);
   * 1是一个字符，会被直接输出；%02X表示将整数值格式化转换为两位16进制数
   * str2.erase(0, 1);表示从str2中删除第一个字符并赋值给str
   */
  str1 += buf[0]; // 从buf中提取第一个字符，这个字符是前导字符，用于在thread中判断是发送什么
  int num = 0;
  std::istringstream ss(str1); // 将字符串转换为流，并将其解析为整数赋值给num
  ss >> num;

  return num;
}

void Mymcu::send_singal(std::string str)
{
  if (RES == 34 && cust == NULL)
    return;

  sig_val.sival_int = 0;                   // 伴随数据
  sig_val.sival_ptr = (void *)str.c_str(); // 伴随数据

  // sigqueue是一个系统调用，用于向某个进程发送信号，并可以附带一些数据
  // getpid 获取当前进程的ID，信号发送给当前进程
  if (sigqueue(getpid(), RES, sig_val) == -1)
  {
    perror("send sig error");
    return;
  }
}

void Mymcu::send_wunshidu(std::string str)
{
  if (cust == NULL)
    return;
  cust->send_wunshidu(str);
}

void Mymcu::send_gps(std::string str)
{
  if (P_android == NULL)
    return;
  P_android->send_gps(str);
}
Mymcu::~Mymcu()
{
  if (mcu == NULL)
    return;
  mcu = NULL;
}
