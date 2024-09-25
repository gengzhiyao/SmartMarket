#include "mcuthread.h"

/**
 * 这是一个线程函数，用于处理一个特定的客户端相关的操作
 * 其返回类型和*arg通常与POSIX线程库结合使用
 */
void *mcu_thread_function(void *arg)
{
  ret_client *cli = (ret_client *)arg;
  Mymcu mcu(cli);

  while (1)
  {
    std::string buf;

    //三者的最终流向：通向Socket，QT上位机界面进行接收
    switch (mcu.read_operate(buf))  //buf在read_operate函数中被裁剪，只剩卡号
    {
    case 1:
      mcu.send_singal(buf);
      break;
    case 2:
      mcu.send_gps(buf);
      break;
    case 3:
      mcu.send_wunshidu(buf);
      break;
    default:
      break;
    }
  }
}

void mcuthread::thread_start(ret_client param)
{
  pthread_t tid;

  int res = pthread_create(&tid, NULL, mcu_thread_function, (void *)&param);
  pthread_detach(res);
}
