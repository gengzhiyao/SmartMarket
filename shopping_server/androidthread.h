#ifndef _ANDROIDTHREAD_
#define _ANDROIDTHREAD_

#include"mythread.h"
#include<iostream>
#include<string>
#include <unistd.h>
#include<pthread.h>
#include "sqlifconfig.h"


#include"android.h"

class androidthread : public Mythread
{
private:
    /* data */
public:
  virtual void thread_start(ret_client param);

};




#endif // !_ANDROIDTHREAD_