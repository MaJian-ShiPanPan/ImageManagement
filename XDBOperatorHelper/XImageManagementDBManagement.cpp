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
		std::cout << PQerrorMessage(conn) << std::endl; // ��ӡ���Ӵ�����Ϣ
		PQfinish(conn); // ��������
	}
	else
	{
		std::cout << "success" << std::endl; // ��ӡ�ɹ���Ϣ
	}
	return 0;
}
