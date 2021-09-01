#include <iostream>
#include "XCNImageManagement.h"

int main()
{
	std::cout << "Hello World" << std::endl;
	CXCNImageManagement* CNImageManagement = new CXCNImageManagement();

	CNImageManagement->DelLay();
	return EXIT_SUCCESS;
}