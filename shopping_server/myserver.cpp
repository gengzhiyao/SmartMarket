#include "myserver.h"

/**
 * domain 套接字的地址，如AF_INET用于ipv4
 * type 套接字类型，SOCK_STREAM用于TCP SOCK_DGRAM用于UDP
 * protocol 制定协议，通常为0，默认
 */
Myserver::Myserver(int domain, int type, int protocol)
{
  m_socket = -1;                             // 尚未创建套接字
  m_socket = socket(domain, type, protocol); // 创建套接字
  if (m_socket == -1)
  {
    perror("socket create error:");
    exit(-1);
  }
}
void Myserver::server_start(std::string ip, int port, int family)
{
  // 初始化ip
  ser_addr.sin_addr.s_addr = inet_addr(ip.c_str());
  ser_addr.sin_family = family;
  ser_addr.sin_port = htons(port);

  /* 允许重复使用本地地址与套接字进行绑定 */
  int i = 1;
  setsockopt(m_socket, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(i));

  // 绑定
  if (bind(m_socket, (struct sockaddr *)&ser_addr, sizeof(struct sockaddr)) == -1)
  {
    perror("bind error:"); // C库中的打印错误的函数
    exit(-1);
  }

  // 监听
  if (listen(m_socket, 5) == -1) // 成功时返回0，失败时，返回-1
  {
    printf("listen error:");
    exit(-1);
  }
  else
  {
    std::cout << "listen......." << std::endl;
  }
}

std::string Myserver::readbuf()
{

  char buf[10] = {0};                       // 初始化数组
  int ret = read(m_client_socket, buf, 10); // ret 代表实际读取的字节数
  if (ret <= 0)
  {
    return "0";
  }
  return buf;
}

// 接收客户端链接请求，连接失败重新尝试
ret_client Myserver::client_socket()
{
reboot: // 定义一个标签，用于在代码中执行跳转操作
  ret_client ret;
  // accept返回一个新的套接字描述符，该套接字用于与客户端进行通信
  m_client_socket = accept(m_socket, (struct sockaddr *)&ret.client_struct, &len);

  if (m_client_socket == -1)
  {
    goto reboot;
  }

  ret.client_socket = m_client_socket;
  return ret;
}

Myserver::~Myserver()
{
  if (m_socket == -1)
  {
    return;
  }
  close(m_socket);
}
