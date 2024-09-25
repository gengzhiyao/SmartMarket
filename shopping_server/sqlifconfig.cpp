#include "sqlifconfig.h"

// 构造函数：mysql通常用于存储Mysql链接的句柄
// 安全初始化Mysql链接，在发生错误时提供反馈
SQLifconfig::SQLifconfig()
{
  mysql = nullptr;
  row = 0; // 初始化
  result = nullptr;
  field = nullptr;

  mysql = mysql_init(NULL); // 申请一块内存，返回首地址，初始化成功时会返回一个MySQL的指针，否则会返回NULL

  if (mysql == NULL) // 判断是否初始化成功
  {
    std::cout << "Error: " << mysql_error(mysql) << std::endl;
    exit(-1);
  }
}

// 用于执行数据库的DML操作：即：数据操作语言
// prama:接收一个SQL查询字符串
// 实现一个事务管理操作，确保在成功执行SQL查询之后进行提交
// mysql_query函数当返回0的时候表示成功，失败时通过调用mysql_error来获取错误信息
bool SQLifconfig::Dml_sql(std::string sqlstr)
{
  std::cout << "sql :" << sqlstr << std::endl; // 输出查询字符串，Debug用

  /**
   * 事务是一组操作，这些操作要么全部成功，要么全部失败，以确保数据的一致性和完整性。
   * BEGIN 开始事务 COMMIT 提交事务 ROLLBACK 回滚事务
   */
  if (mysql_query(mysql, "BEGIN")) // 开始事务
  {
    std::cout << "query_error:" << mysql_error(mysql) << std::endl;
    return false;
  }

  if (mysql_query(mysql, sqlstr.c_str()))
  {
    std::cout << "query_error:" << mysql_error(mysql) << std::endl;
    return false;
  }

  if (mysql_query(mysql, "COMMIT")) // 退出事务
  {
    std::cout << "query_error:" << mysql_error(mysql) << std::endl;
    return false;
  }

  return true; // 上述所有操作成功时才返回为true
}

// 用于执行SQL查询并返回结果，接收一个查询字符串，返回一个包含查询结果的字符串
std::string SQLifconfig::Dql_sql(std::string sqlstr)
{
  std::string str; // 用于返回查询结果，默认空字符串

  if (mysql_query(mysql, sqlstr.c_str()))
  {
    std::cout << "query_error:" << mysql_error(mysql) << std::endl;
    return "0";
  }
  else
  {
    result = mysql_store_result(mysql); // 查询成功，使用这个函数获取结果集，并获取所查询的字段数量fieldnum
    int fieldnum = mysql_num_fields(result);

    for (int i = 0; i < mysql_num_rows(result); i++)
    {
      row = mysql_fetch_row(result);
      if (row <= 0)
        break;
      for (int j = 0; j < fieldnum; j++)
      {
        str += row[j];
        str += "#";
      }
      str.resize(str.size() - 1);
      str += "\n";
      /**结果可能是这样
       * 苹果#18
       * 西瓜#4
       * 香蕉#12
       */
    }

    mysql_free_result(result);
  }
  if (!str.size())
  {
    return "0";
  }
  return str;
}

// 该函数尝试使用提供的参数链接到Mysql数据库，包括主机，用户名，密码，数据库名称，端口号
bool SQLifconfig::SQL_init(std::string host, std::string user, std::string pwd, std::string dbname)
{
  if (!mysql_real_connect(mysql, host.c_str(), user.c_str(), pwd.c_str(), dbname.c_str(), 3306, NULL, 0))
  {
    std::cout << "connect error:" << mysql_errno(mysql) << std::endl;
    exit(-1); // 连接失败，输出信息，程序终止
  }

  return true;
}

SQLifconfig::~SQLifconfig()
{
  if (!mysql)
  {
    mysql_close(mysql);
  }
}
