#ifndef _ANDROID_
#define _ANDROID_

#include<iostream>
#include<string>
#include <unistd.h>
#include<pthread.h>
#include <sstream>

#include"mythread.h"
using namespace std;

class Myandroid
{ 
public:
    Myandroid(ret_client*  client);
    ~Myandroid();
    int read_operate(std::string & str);
    
    void get_data();
    void get_text(std::string numb);
    void denglu(std::string str);
    void send_gps(std::string str);
private:

  int m_socket;
  SQLifconfig m_sql; 
};





#endif