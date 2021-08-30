#ifndef XDBOPERATORHELPER_XIMAGEMANAGEMENTDBMANAGEMENTFACADE_H
#define XDBOPERATORHELPER_XIMAGEMANAGEMENTDBMANAGEMENTFACADE_H

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
	int DBConnection() override;
private:
	CXImageManagementDBManagement* m_pXImageManagementDBManagement;
};
#endif
