
#include "sqlifconfig.h"

#include "myserver.h"

#include "adminthread.h"
#include "mcuthread.h"
#include "androidthread.h"
#include "custthread.h"
#include "mythread.h"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int RES = 34;

#define host "127.0.0.1"
#define user "root"
#define pwd "20021209"
#define dbname "shopping"
#define MY_IP "10.0.16.12"
#define MY_PORT 8888

int main(void)
{

    // 数据库初始化
    SQLifconfig sql_typ;
    sql_typ.SQL_init(host, user, pwd, dbname);
    sql_typ.Dql_sql("SELECT * FROM me"); // me为一个数据库表名称

    // server初始化
    ret_client myret;

    Myserver server(AF_INET, SOCK_STREAM, 0);
    server.server_start(MY_IP, MY_PORT, AF_INET);

    while (1)
    {
        myret = server.client_socket();
        myret.my_sql = sql_typ;

        std::cout << "new connect !!" << std::endl;
        std::string str = server.readbuf();

        int num;
        istringstream a(str);
        a >> num;

        switch (num)
        {
            case 100001:
            {
                Mythread *android_thread = new androidthread; //
                android_thread->thread_start(myret);
                std::cout << "安卓客户端连接成功" << std::endl;
            }
            break;
            case 100101:
            {
                Mythread *admin_thread = new adminthread; //
                admin_thread->thread_start(myret);
                std::cout << "PC客户端连接成功" << std::endl;
            }
            break;
            case 100111:
            {
                Mythread *cust_thread = new custthread; //
                cust_thread->thread_start(myret);
                std::cout << "ARM客户端连接成功" << std::endl;
            }
            break;
            case 101001:
            {
                Mythread *mcu_thread = new mcuthread; //     std::cout<<"STM32客户端连接成功"<<std::endl;
                mcu_thread->thread_start(myret);
                std::cout << "STM32客户端连接成功" << std::endl;
            }
            break;
            default:
                std::cout << "未知的错误" << std::endl;
                break;
        }
    }
}