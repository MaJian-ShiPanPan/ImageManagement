#ifndef XCNIMAGEMANAGEMENT_XCNIMAGEMANAGEMENT_H
#define XCNIMAGEMANAGEMENT_XCNIMAGEMANAGEMENT_H

#ifndef XIMAGEMANAGEMENTDBMANAGEMENT_EXPORT
#define XIMAGEMANAGEMENTDBMANAGEMENT_EXPORT
#endif // !XIMAGEMANAGEMENTDBMANAGEMENT_EXPORT

#include <libpq-fe.h>

class CXCNImageManagement
{
public:
	CXCNImageManagement();
	~CXCNImageManagement();
	
	int Initialize();
	int finalization();

private:
	PGconn* DBconn;
};

#endif // XCNIMAGEMANAGEMENT_XCNIMAGEMANAGEMENT_H
