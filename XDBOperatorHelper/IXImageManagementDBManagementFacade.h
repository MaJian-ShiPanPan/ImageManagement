#ifndef XDBOPERATORHELPER_IXIMAGEMANAGEMENTDBMANAGEMENTFACADE_H
#define XDBOPERATORHELPER_IXIMAGEMANAGEMENTDBMANAGEMENTFACADE_H

class IXImageManagementDBManagementFacade
{
public:
	IXImageManagementDBManagementFacade() = default;
	virtual ~IXImageManagementDBManagementFacade() = default;

	virtual int DBConnection() = 0;
};
#endif
