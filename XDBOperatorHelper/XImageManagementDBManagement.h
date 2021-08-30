#ifndef XDBOPERATORHELPER_XIMAGEMANAGEMENTDBMANAGEMENT_H
#define XDBOPERATORHELPER_XIMAGEMANAGEMENTDBMANAGEMENT_H

#include <libpq-fe.h>

class CXImageManagementDBManagement
{
public:
	CXImageManagementDBManagement() = default;
	~CXImageManagementDBManagement() = default;

	PGconn* GetDBConn();

private:
	int DBConnection();

	PGconn* conn;
};
#endif