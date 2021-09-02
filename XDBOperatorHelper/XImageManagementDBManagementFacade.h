#ifndef XDBOPERATORHELPER_XIMAGEMANAGEMENTDBMANAGEMENTFACADE_H
#define XDBOPERATORHELPER_XIMAGEMANAGEMENTDBMANAGEMENTFACADE_H

#include <libpq-fe.h>
#include "IXImageManagementDBManagementFacade.h"

class CXImageManagementDBManagement;

class CXImageManagementDBManagementFacade
	:public IXImageManagementDBManagementFacade
{
public:
	CXImageManagementDBManagementFacade();
	~CXImageManagementDBManagementFacade();

	int Initialization();
	int Finalization();
	PGconn* DBConnection() override;
	bool InsertSingleImage(std::string imageName, std::string imagePath, int storeType, std::string storeData) override;
	bool GetPicPathAccordPicName(std::string& imageName, std::vector<std::string>& vecImagePath) override;
	bool DeletePicPathAccordPicName(std::string& imageName) override;

private:
	CXImageManagementDBManagement* m_pXImageManagementDBManagement;
};
#endif
