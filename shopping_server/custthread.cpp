#include "custthread.h"

extern int asd;
extern pthread_mutex_t mutex1;

void *cust_thread_function(void *myarga)
{
  ret_client *cli = (ret_client *)myarga;
  Mycust cust(cli);

  while (1)
  {
    std::string buf;
    switch (cust.read_operate(buf))
    {

    case 1:
      cust.get_start_rfid(buf);
      break;

    case 2:
      cust.delete_start_rfid();
      break;

    case 3:
      cust.addtest(buf);
      break;

    default:
      break;
    }
  }

  return NULL;
}

void custthread::thread_start(ret_client param)
{
  pthread_t tid;
  int res = pthread_create(&tid, NULL, cust_thread_function, (void *)&param);
  pthread_detach(res);
}
