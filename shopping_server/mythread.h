#ifndef _MYTHREAD_
#define _MYTHREAD_

#include<iostream>
#include "sqlifconfig.h"
#include <sys/types.h>        
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

class ret_client
{
public:
   int client_socket;   //存储客户端的套接字，表示和客户端的网络连接
   struct sockaddr_in client_struct;   //存储客户端的地址信息，包括IP和端口
   SQLifconfig my_sql;  //封装好的Mysql对象，提供DML,DCL功能
};


class Mythread
{
private:
    /* data */
public:
   virtual void thread_start(ret_client param)=0;
 
};



#endif // !_MYTHREAD_