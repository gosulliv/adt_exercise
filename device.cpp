#include "device.h"

//The purpose of this code is to implement member functions
//for the device class that manage the manages a dynamically 
//allocated array (devicename)

device::device() //This is the default constructor.
{
	deviceName = NULL;
}

device::~device() //This is the default destructor.
{
	if(deviceName) //We first check if it's safe to delete.
		delete [] deviceName;
}

char * device::get_data() { return deviceName; } //This is a getter that simply returns the member data.

device *& device::to_next() { return next;} //This getter returns the next node.

//COmpare returns 0 if deviceNames match.
int device::compare(const device & querent)
{
	if(strcmp(this->deviceName, querent.deviceName) == 0)
	{
		return 1;
	}
	return 0;
}

//This version of compare takes a char array, but is identical otherwise.
int device::compare(char * deviceName)
{
	if(strcmp(this->deviceName, deviceName) == 0)
	{
		return 1;
	}
	return 0;
}

//add returns 0 if the arguement is null, but otherwise 
//copies the arguement into a string, that string is assingned to deviceName.
int device::add(char deviceName_toadd[])
{
	if(!deviceName_toadd) return 0;
	deviceName = new char[strlen(deviceName_toadd) + 1];
		strcpy(deviceName, deviceName_toadd);

	return 1;
}

//This add is a wrapper of the previous function, it's argument
//by passing in the data member from its arguement into the add above.
int device::add(const device & new_device)
{
	return add(new_device.deviceName);
}

//This display function displays the member day, returns 0 on failure.
int device::display()
{
	if(deviceName)
	{	
		std::cout << deviceName << std::endl;
	return 1;
	}	
	return 0;
}

