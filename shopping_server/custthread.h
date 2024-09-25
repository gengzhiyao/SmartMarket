#ifndef _CUSTTHREAD_
#define _CUSTTHREAD_

#include"mythread.h"
#include<iostream>
#include<string>
#include <unistd.h>
#include<pthread.h>
#include "sqlifconfig.h"
#include"cust.h"

using namespace std;

class custthread :public Mythread
{
private:
    /* data */
public:
   virtual void thread_start(ret_client param);

};




#endif // !_CUSTTHREAD_

