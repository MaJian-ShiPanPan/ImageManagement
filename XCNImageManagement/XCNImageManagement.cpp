#include <vector>
#include <string>
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
	std::vector<std::string> vecImagePath;
	m_pDBManagement->InsertSingleImage("majian.png", "C:ASB/SB", 1, "2001-07-13");
	std::string imageName = "majian.png";
	m_pDBManagement->GetPicPathAccordPicName(imageName, vecImagePath);
	for (auto it = vecImagePath.begin(); it != vecImagePath.end(); ++it)
	{
		std::cout << *it << "\t";
	}
	std::cout << std::endl;

	imageName = "majian.png";
	m_pDBManagement->DeletePicPathAccordPicName(imageName);
	return 0;
}
