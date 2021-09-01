#include <iostream>
#include "XImageManagementDBManagement.h"

PGconn* CXImageManagementDBManagement::GetDBConn()
{
	this->DBConnection();
	return conn;
}

int CXImageManagementDBManagement::DBConnection()
{
	conn = PQconnectdb("host=127.0.0.1 dbname==ImageManagement user=postgres password=majian");
	if (PQstatus(conn) == CONNECTION_BAD)
	{
		std::cout << PQerrorMessage(conn) << std::endl; // 打印连接错误信息
		PQfinish(conn); // 结束链接
	}
	else
	{
		std::cout << "success" << std::endl; // 打印成功信息
	}
	return 0;
}
