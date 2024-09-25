#ifndef  _SQLIFCONFIG_
#define  _SQLIFCONFIG_

#include "sqlifconfig.h"
#include<mysql/mysql.h>
#include<iostream>
#include<string>
using namespace std;

class SQLifconfig
{
public:
    SQLifconfig();
    ~SQLifconfig(); 
    bool SQL_init(std::string host,std::string user,std::string pwd,std::string dbname);
    std::string Dql_sql(string sqlstr);
    bool Dml_sql(string sqlstr);
private:
	MYSQL* mysql;
	MYSQL_ROW row;
	MYSQL_RES* result;
	MYSQL_FIELD* field;
};




#endif // 