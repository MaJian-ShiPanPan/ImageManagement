#include "XImageManagementDBManagementFactory.h"
#include "XImageManagementDBManagementFacade.h"

std::shared_ptr<IXImageManagementDBManagementFacade> CXImageManagementDBManagementFactory::CreateDBManagement()
{
	return std::shared_ptr<CXImageManagementDBManagementFacade>(new CXImageManagementDBManagementFacade());
}
