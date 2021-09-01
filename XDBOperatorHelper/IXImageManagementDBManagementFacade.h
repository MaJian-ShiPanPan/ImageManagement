#ifndef XDBOPERATORHELPER_IXIMAGEMANAGEMENTDBMANAGEMENTFACADE_H
#define XDBOPERATORHELPER_IXIMAGEMANAGEMENTDBMANAGEMENTFACADE_H

#include <libpq-fe.h>

class IXImageManagementDBManagementFacade
{
public:
	IXImageManagementDBManagementFacade() = default;
	virtual ~IXImageManagementDBManagementFacade() = default;

	virtual PGconn* DBConnection() = 0;
};
#endif
