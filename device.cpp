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

char * device::get_data() { return deviceName; }

device *& device::to_next() { return next;} 

int device::compare(const device & querent) // ithink this might should be a deviceList method
{
	if(strcmp(this->deviceName, querent.deviceName) == 0)
	{
		return 1;
	}
	return 0;
}

int device::compare(char * deviceName)
{
	if(strcmp(this->deviceName, deviceName) == 0)
	{
		return 1;
	}
	return 0;
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
	if(deviceName)	//seg
	{	
		std::cout << deviceName << std::endl;
	return 1;
	}	
	return 0;
}

