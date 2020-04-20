#include "device.h"

//The purpose of this code is to implement member functions
//for the device class that manage the manages a dynamically 
//allocated array (devicename)


/* My data members:
	char * deviceName;
*/

device::device()
{
	deviceName = NULL;
}

device::~device()
{
	if(deviceName)
		delete [] deviceName;
}

int device::add(char deviceName_toadd[])
{
	if(!deviceName_toadd) return 0;
	deviceName = new char[strlen(deviceName_toadd) + 1];
		strcpy(deviceName, deviceName_toadd);

	return 1;
}

int device::add(const device & new_device)
{
	return add(new_device.deviceName);
}

int device::display()
{
	if(deviceName)	
	{	
		std::cout << deviceName << std::endl;
	return 1;
	}	
	else
		return 0;
}
