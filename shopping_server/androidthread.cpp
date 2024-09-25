#include "androidthread.h"


 void * android_thread_function(void *arg)
{
      ret_client *cli=(ret_client*)arg;
       Myandroid android(cli);
        
      while (1)
     {
        std::string buf;
 
        switch (android.read_operate(buf))
        {
        case 1:
        android.denglu(buf);
        break;
        
      case 2:
        android.get_data();
       break;

      case 3:
      android.get_text(buf);
       break;

    default:
        break;

        }

        }
   

}

void androidthread::thread_start(ret_client param)
{
   
    pthread_t tid;
    int res = pthread_create(&tid,NULL,android_thread_function,(void*)&param);
    pthread_detach(res);
}

