#ifndef XCNIMAGEMANAGEMENT_XCNIMAGEMANAGEMENT_H
#define XCNIMAGEMANAGEMENT_XCNIMAGEMANAGEMENT_H

#ifndef XIMAGEMANAGEMENTDBMANAGEMENT_EXPORT
#define XIMAGEMANAGEMENTDBMANAGEMENT_EXPORT
#endif // !XIMAGEMANAGEMENTDBMANAGEMENT_EXPORT

#include <iostream>
#include <libpq-fe.h>

class CXImageManagementDBManagementFactory;
class IXImageManagementDBManagementFacade;

class CXCNImageManagement
{
public:
	CXCNImageManagement();
	~CXCNImageManagement();
	
	int Initialize();
	int finalization();

	int DelLay();

private:
	PGconn* DBconn;
	CXImageManagementDBManagementFactory* m_pDBManagementFactory;
	std::shared_ptr<IXImageManagementDBManagementFacade> m_pDBManagement;
};

#endif // XCNIMAGEMANAGEMENT_XCNIMAGEMANAGEMENT_H
