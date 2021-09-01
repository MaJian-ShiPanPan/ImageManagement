#include <iostream>
#include "XImageManagementDBManagement.h"

PGconn* CXImageManagementDBManagement::GetDBConn()
{
	this->DBConnection();
	return conn;
}

std::string CXImageManagementDBManagement::GetSingImage()
{
	
	return "123";
}

bool CXImageManagementDBManagement::InsertSingleImage(std::string imagePath, int storeType, std::string storeData)
{
	std::string sqlStr = "INSERT INTO PicAddrMapTab (ImagePath, StoreType, StoreData) VALUES (" + imagePath + ", " + std::to_string(storeType) + ", " + storeData + ");";
	std::cout << sqlStr << std::endl;
	char* cSql = const_cast<char*>(sqlStr.c_str());

	PGresult* res = PQexec(this->conn, cSql);

	if (PGRES_COMMAND_OK != PQresultStatus(res))
	{
		std::cout << PQresultErrorMessage(res) << std::endl;
		PQclear(res);
		return true;
	}
	return false;
}

int CXImageManagementDBManagement::DBConnection()
{
	conn = PQconnectdb("host=127.0.0.1 dbname=ImageManagement user=postgres password=majian port=5432");
	// conn = PQsetdbLogin("127.0.0.1", "5432", NULL, NULL, "ImageManagement", "postgres", "majian"); // Ҳ���Բ��ø÷����������ݿ�
	if (PQstatus(conn) == CONNECTION_BAD)
	{
		std::cout << PQerrorMessage(conn) << std::endl; // ��ӡ���Ӵ�����Ϣ
		PQfinish(conn); // ��������
	}
	else
	{
		std::cout << "�������ݿ�ɹ�:" << PQstatus(conn) << std::endl; // ��ӡ�ɹ���Ϣ
	}
	return 0;
}
