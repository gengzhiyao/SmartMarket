#ifndef _MCU_
#define _MCU_

#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include "mythread.h"
#include <sstream>
#include "android.h"
#include "cust.h"

using namespace std;

class Mymcu
{

public:
    Mymcu(ret_client *client);
    ~Mymcu();
    void send_singal(std::string str);
    int getsocket();
    int read_operate(std::string &str);
    void send_gps(std::string str);
    void send_wunshidu(std::string str);
    void send_mcutext();

private:
    int m_socket;
    SQLifconfig m_sql;
    sigval_t sig_val; // 这是一个联合体
};

#endif