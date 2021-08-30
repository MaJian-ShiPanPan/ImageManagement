#ifndef XDBOPERATORHELPER_XIMAGEMANAGEMENTDBMANAGEMENTFACTORY_H
#define XDBOPERATORHELPER_XIMAGEMANAGEMENTDBMANAGEMENTFACTORY_H

#ifndef XIMAGEMANAGEMENTDBMANAGEMENT_EXPORT
#define XIMAGEMANAGEMENTDBMANAGEMENT_DEC _declspec(dllimport)
#else
#define XIMAGEMANAGEMENTDBMANAGEMENT_DEC _declspec(dllexport)
#endif

#include <iostream>
#include "IXImageManagementDBManagementFacade.h"

class CXImageManagementDBManagementFacade;

class XIMAGEMANAGEMENTDBMANAGEMENT_DEC CXImageManagementDBManagementFactory
{
public:
	CXImageManagementDBManagementFactory() = default;
	~CXImageManagementDBManagementFactory() = default;

	std::shared_ptr<IXImageManagementDBManagementFacade> CreateDBManagement();
};

#endif
