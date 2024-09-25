#include "android.h"

extern int RES;
Myandroid *P_android = NULL;

Myandroid::Myandroid(ret_client *client)
{
   P_android = this;
   m_socket = client->client_socket;
   m_sql = client->my_sql;
}

Myandroid::~Myandroid()
{
   P_android = NULL;
}

void Myandroid::get_data()
{
   std::string ret = m_sql.Dql_sql("select* from me ");
   ret.insert(0, "3\n");
   write(m_socket, ret.c_str(), ret.size());
}

void Myandroid::send_gps(std::string str)
{
   str.insert(0, "5\n");
   write(m_socket, str.c_str(), str.size());
   usleep(20000); // 防止粘包
}

void Myandroid::get_text(std::string numb)
{

   char buf[1024];
   sprintf(buf, "select text  from users where phone='%s'", numb.c_str());
   std::string ret = m_sql.Dql_sql(buf);
   ret.insert(0, "4\n");
   write(m_socket, ret.c_str(), ret.size());
}

void Myandroid::denglu(std::string str)
{
   int x = str.find('#');
   std::string name = str.substr(0, x);
   std::string numbr = str.substr(x + 1, std::string::npos);
   //
   // users(id,phone,name,balance)
   //
   char buf[1024];
   sprintf(buf, "select name from users where phone='%s'", numbr.c_str());
   std::string ret = m_sql.Dql_sql(buf);
   ret.erase(ret.end() - 1);
   if (ret == "0")
   {
      write(m_socket, "2\n", 4);
   }
   else
   {
      if (ret != name)
      {
         write(m_socket, "2\n", 4); // 登录失败
      }
      else
      {
         write(m_socket, "1\n", 4); // 登录成功
      }
   }
}

int Myandroid::read_operate(std::string &str)
{
   char buf[200] = {0};
   if (read(m_socket, buf, sizeof(buf)) <= 0)
   {
      return 0;
   }
   std::string str1, str2;
   str2 = buf;
   str = str2.erase(0, 1);

   str1 += buf[0];
   int num = 0;
   std::istringstream ss(str1);
   ss >> num;

   return num;
}