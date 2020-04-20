#include <cstring>
#include <iostream>

//Chris Lu
//This is the base node class for our deviceList. This module
//houses the functionality that allows applications to create
//a device, add a new device, and display a device etc

class device
{
	public:
		device(); //default constructor
		~device(); //default destructor

		int add(char deviceName[]); //add a new device
		int add(const device & new_device); //add an entire device
		int display();
		//not sure if we need a remove here	
	private:
			char * deviceName;
};
