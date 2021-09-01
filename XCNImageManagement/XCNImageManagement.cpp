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
	m_pDBManagementFactory = new CXImageManagementDBManagementFactory();
	m_pDBManagement = m_pDBManagementFactory->CreateDBManagement();
	this->DBconn = m_pDBManagement->DBConnection();
	return 0;
}

int CXCNImageManagement::finalization()
{
	return 0;
}

int CXCNImageManagement::DelLay()
{
	m_pDBManagement->InsertSingleImage("\'ASB//SB\'", 1, "\'2001-07-13\'");
	return 0;
}
