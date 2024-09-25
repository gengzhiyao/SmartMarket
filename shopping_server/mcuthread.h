#ifndef __MCUTHREAD_
#define __MCUTHREAD_

#include"mythread.h"
#include<iostream>
#include<string>
#include <unistd.h>
#include<pthread.h>
#include "sqlifconfig.h"
#include"mcu.h"

using namespace std;

class mcuthread :public Mythread
{
private:
    /* data */
public:

   virtual void thread_start(ret_client param);
};



#endif // !__MCUTHREAD_

