#ifndef _CUST_
#define _CUST_

#include<iostream>
#include<string>
#include <sstream>
#include <unistd.h>
#include<pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mcu.h"
#include "sqlifconfig.h"
#include"mythread.h"

using namespace std;

void* cust_thread_function(void * myarga);

class Mycust
{

public:
    Mycust(ret_client* client);
    ~Mycust();

   void get_start_rfid(std::string str); //1 释放资源
   void delete_start_rfid(); //2 释放资源

   void addshopp(std::string str);
   void addtest(std::string str);
   void checkout(std::string str); //3  结帐

   void setzeor();  
   void writetext(std::string str);
   int read_operate(std::string & str);
   void send_wunshidu(std::string str);

private:
   int m_money;
   int m_socket;
   SQLifconfig m_sql; 
   struct sigaction sig_add;
   struct sigaction sig_checkout;

};



#endif