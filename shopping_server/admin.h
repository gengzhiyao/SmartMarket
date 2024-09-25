#ifndef _ADMIN_
#define _ADMIN_

#include<iostream>
#include<string.h>
#include <unistd.h>
#include<pthread.h>
#include <sstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#include "sqlifconfig.h"
#include"mythread.h"

using namespace std;
void* admin_thread_function(void * myarg);



class Myadmin
{

  
public:
    Myadmin(ret_client* socket);
    ~Myadmin();
  
  void get_start_meb(); //0
  void get_start_shop(); //1
  void m_register(std::string str);   //注册
  void m_rech(std::string str);       //充值 
  void m_select(std::string str);         //查询
  void m_logout(std::string str);       //注销
  void m_stop();        //全删除
  void add_shopp(std::string str);     //添加商品
  void rm_shopp(std::string str);      //删除商品
  void m_textedit();    //记录
  void shopp_Init();   
  void meb_Init();

  void set_send_rizhi(std::string str);
  bool iszhuce(std::string id);

  int get_socket();
  int read_operate(std::string & str);
private:
  int m_socket;
  SQLifconfig m_sql; 
  struct sigaction sig_meb={0};
  struct sigaction sig_shopp={0};
};



#endif