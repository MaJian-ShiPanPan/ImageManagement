#ifndef XDBOPERATORHELPER_XIMAGEMANAGEMENTDBMANAGEMENT_H
#define XDBOPERATORHELPER_XIMAGEMANAGEMENTDBMANAGEMENT_H

#include <string>
#include <libpq-fe.h>
#include <vector>

class CXImageManagementDBManagement
{
public:
	CXImageManagementDBManagement() = default;
	~CXImageManagementDBManagement() = default;

	PGconn* GetDBConn();
	bool GetPicPathAccordPicName(std::string& imageName, std::vector<std::string>& vecImagePath);
	bool InsertSingleImage(std::string imageName, std::string imagePath, int storeType, std::string storeData);
	bool DeletePicPathAccordPicName(std::string& imageName);

private:
	int DBConnection();

	PGconn* conn;
};
#endif
