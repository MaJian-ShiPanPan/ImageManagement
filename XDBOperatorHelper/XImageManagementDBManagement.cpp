#include <iostream>
#include "XImageManagementDBManagement.h"

PGconn* CXImageManagementDBManagement::GetDBConn()
{
	this->DBConnection();
	return conn;
}

bool CXImageManagementDBManagement::GetPicPathAccordPicName(std::string& imageName, std::vector<std::string>& vecImagePath)
{
	std::string sqlStr = "SELECT image_path FROM \"PicAddrMapTab\" WHERE image_name LIKE \'" + imageName + "\'";
	std::cout << sqlStr << std::endl;

	char* cSql = const_cast<char*>(sqlStr.c_str());

	PGresult* res = PQexec(conn, cSql);
	if (PGRES_TUPLES_OK != PQresultStatus(res))
	{
		std::cout << PQresultErrorMessage(res) << std::endl;
		PQclear(res);
		return false;
	}
	else
	{
		for (int i = 0; i < PQntuples(res); i++)
		{
			for (int j = 0; j < PQnfields(res); j++)
			{
				vecImagePath.push_back(std::string(PQgetvalue(res, i, j)) + "/" + imageName);
			}
		}
	}
	return true;
}

bool CXImageManagementDBManagement::InsertSingleImage(std::string imageName, std::string imagePath, int storeType, std::string storeData)
{
	std::string sqlStr = "INSERT INTO \"PicAddrMapTab\" (image_name, image_path, store_type, store_data) VALUES (\'" + imageName + "\', \'" + imagePath + "\', " + std::to_string(storeType) + ", \'" + storeData + "\');";
	std::cout << sqlStr << std::endl;
	char* cSql = const_cast<char*>(sqlStr.c_str());

	PGresult* res = PQexec(this->conn, cSql);

	if (PGRES_COMMAND_OK != PQresultStatus(res))
	{
		std::cout << PQresultStatus(res) << std::endl;
		std::cout << PQresultErrorMessage(res) << std::endl;
		PQclear(res);
		return true;
	}
	return false;
}

bool CXImageManagementDBManagement::DeletePicPathAccordPicName(std::string& imageName)
{
	std::string sqlStr = "DELETE FROM \"PicAddrMapTab\" WHERE image_name LIKE \'" + imageName + "\';";
	std::cout << sqlStr << std::endl;
	char* sql = const_cast<char*>(sqlStr.c_str());
	PGresult* res = PQexec(conn, sql);
	if (PGRES_COMMAND_OK != PQresultStatus(res))
	{
		std::cout << PQresultErrorMessage(res) << std::endl;
		PQclear(res);
		return false;
	}
	else
	{
		std::cout << "delete success!" << std::endl;
	}
	return true;
}

int CXImageManagementDBManagement::DBConnection()
{
	conn = PQconnectdb("host=127.0.0.1 dbname=ImageManagement user=postgres password=majian port=5432");
	// conn = PQsetdbLogin("127.0.0.1", "5432", NULL, NULL, "ImageManagement", "postgres", "majian"); // 也可以采用该方法链接数据库
	if (PQstatus(conn) == CONNECTION_BAD)
	{
		std::cout << PQerrorMessage(conn) << std::endl; // 打印连接错误信息
		PQfinish(conn); // 结束链接
	}
	else
	{
		std::cout << "链接数据库成功:" << PQstatus(conn) << std::endl; // 打印成功信息
	}
	return 0;
}
