#ifndef XDBOPERATORHELPER_XIMAGEMANAGEMENTDBMANAGEMENT_H
#define XDBOPERATORHELPER_XIMAGEMANAGEMENTDBMANAGEMENT_H

#include <string>
#include <libpq-fe.h>

class CXImageManagementDBManagement
{
public:
	CXImageManagementDBManagement() = default;
	~CXImageManagementDBManagement() = default;

	PGconn* GetDBConn();
	std::string GetSingImage();
	bool InsertSingleImage(std::string imagePath, int storeType, std::string storeData);

private:
	int DBConnection();

	PGconn* conn;
};
#endif