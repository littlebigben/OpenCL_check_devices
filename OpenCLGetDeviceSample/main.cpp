#include <iostream>
#include <cassert>

#include <CL/cl.hpp>

int main()
{
	std::vector<cl::Device> devices;
	cl_int error = CL_SUCCESS;

	//get patforms
	std::vector<cl::Platform> platforms;
	cl_int  status = cl::Platform::get(&platforms);
	if (CL_SUCCESS != status)
    {
        std::cout << "Can't get platforms" << std::endl;
		return EXIT_FAILURE;
    }
	
	//get devices
	error = platforms[0].getDevices(CL_DEVICE_TYPE_ALL, &devices);
	
	assert(CL_SUCCESS == error);

	//display devices name and OpenCL version
	for (unsigned int i = 0; i < devices.size(); ++i)
	{
		auto ret = devices[i].getInfo<CL_DEVICE_NAME>();
		std::cout << ret << std::endl;
		ret = devices[i].getInfo<CL_DEVICE_VERSION>();
		std::cout << ret << std::endl;
	}
	
	//wait input to stop the program execution
	std::string tmp;
	std::cin >> tmp;
}