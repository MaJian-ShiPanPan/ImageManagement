#include "XImageManagementDBManagementFacade.h"
#include "XImageManagementDBManagement.h"

CXImageManagementDBManagementFacade::CXImageManagementDBManagementFacade()
{

}

CXImageManagementDBManagementFacade::~CXImageManagementDBManagementFacade()
{

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

int CXImageManagementDBManagementFacade::DBConnection()
{
	return 0;
}
