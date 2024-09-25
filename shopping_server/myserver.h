#ifndef _MYSERVER_
#define _MYSERVER_


#include <sys/types.h>        
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include "mythread.h"

using namespace std;

class Myserver
{
public:
     Myserver(int __domain, int __type, int __protocol);
     ~Myserver();
     void server_start(std::string ip,int port,int family);
     ret_client  client_socket();
     std::string readbuf();
private:
   int m_socket;
   struct sockaddr_in ser_addr;
   int m_client_socket;
   socklen_t len=sizeof(ser_addr);
};

#endif 
