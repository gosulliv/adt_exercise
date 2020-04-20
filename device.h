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
		//we need an accessoAr? that we can use for find and searches
		char * get_data() const; //accessor	
	private:
			char * deviceName;
};
