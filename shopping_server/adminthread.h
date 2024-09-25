#ifndef _ADMINTHREAD_
#define _ADMINTHREAD_

#include "mythread.h"
#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include "sqlifconfig.h"
#include <cstring>

#include "admin.h"

class adminthread : public Mythread
{
private:
    /* data */
public:
    virtual void thread_start(ret_client param);
};

#endif // !_ADMINTHREAD_