#ifndef XDBOPERATORHELPER_IXIMAGEMANAGEMENTDBMANAGEMENTFACADE_H
#define XDBOPERATORHELPER_IXIMAGEMANAGEMENTDBMANAGEMENTFACADE_H

#include <vector>
#include <string>
#include <libpq-fe.h>

class IXImageManagementDBManagementFacade
{
public:
	IXImageManagementDBManagementFacade() = default;
	virtual ~IXImageManagementDBManagementFacade() = default;

	virtual PGconn* DBConnection() = 0;
	virtual bool InsertSingleImage(std::string imageName, std::string imagePath, int storeType, std::string storeData) = 0;
	virtual bool GetPicPathAccordPicName(std::string& imageName, std::vector<std::string>& vecImagePath) = 0;
	virtual bool DeletePicPathAccordPicName(std::string& imageName) = 0;
};
#endif
