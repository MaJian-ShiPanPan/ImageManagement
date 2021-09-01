#include "XImageManagementDBManagementFacade.h"
#include "XImageManagementDBManagement.h"

CXImageManagementDBManagementFacade::CXImageManagementDBManagementFacade()
{
	this->Initialization();
}

CXImageManagementDBManagementFacade::~CXImageManagementDBManagementFacade()
{
	this->Finalization();
}

int CXImageManagementDBManagementFacade::Initialization()
{
	m_pXImageManagementDBManagement = new CXImageManagementDBManagement();
	return 0;
}

int CXImageManagementDBManagementFacade::Finalization()
{
	delete m_pXImageManagementDBManagement;
	return 0;
}

PGconn* CXImageManagementDBManagementFacade::DBConnection()
{
	return m_pXImageManagementDBManagement->GetDBConn();
}
