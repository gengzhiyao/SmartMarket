#include "adminthread.h"

void *admin_thread_function(void *myarga)
{
   ret_client *cli = (ret_client *)myarga;
   Myadmin admin(cli);

   while (1)
   {
      std::string buf;
      switch (admin.read_operate(buf))    //读操作的信息来源是admin.pro工程中widget.cpp文件，由socket发出的引导符
      {
      case 1:
         admin.get_start_shop();
         break;

      case 2:
         admin.m_register(buf);
         break;

      case 3:
         admin.m_rech(buf);
         break;

      case 4:
         admin.m_select(buf);
         break;

      case 5:
         admin.m_logout(buf);
         break;

      case 6:
         admin.m_stop();
         break;

      case 7:
         admin.add_shopp(buf);
         break;

      case 8:
         admin.rm_shopp(buf);
         break;

      case 9:
         admin.m_textedit();
         break;
      case 10:
         admin.shopp_Init();
         break;
      case 11:
         admin.meb_Init();
         break;
      case 12:
         admin.get_start_meb();
         break;
      default:
         break;
      }
   }

   return NULL;
}

void adminthread::thread_start(ret_client param)
{

   pthread_t tid;
   int res = pthread_create(&tid, NULL, admin_thread_function, (void *)&param);
   pthread_detach(res);
}
