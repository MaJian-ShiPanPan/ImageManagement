#include "XCNImageManagement.h"
#include "IXImageManagementDBManagementFacade.h"
#include "XImageManagementDBManagementFactory.h"

CXCNImageManagement::CXCNImageManagement()
{
	this->Initialize();
}

CXCNImageManagement::~CXCNImageManagement()
{
	this->finalization();
}

int CXCNImageManagement::Initialize()
{
	CXImageManagementDBManagementFactory* pDBManagementFactory = new CXImageManagementDBManagementFactory();
	std::shared_ptr<IXImageManagementDBManagementFacade> pDBManagement = pDBManagementFactory->CreateDBManagement();
	this->DBconn = pDBManagement->DBConnection();
	return 0;
}

int CXCNImageManagement::finalization()
{
	return 0;
}
