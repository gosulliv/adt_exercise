#include <cstring>
#include <iostream>

//Chris Lu
//CS163
//Project #1
//Device.h
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
		int display(); //couts the devicename, returns 0 on failure.
	
		//Both of these compares use strcmp and return 0 on a match of 
		//their deviceNames.	
		int compare(const device & a_device); //this version takes a node
		int compare(char * deviceName); //this version takes a char array
		char * get_data(); //a getter which returns deviceName.
		device * & to_next(); //a getter that returns the next pointer.	
	private:
		char * deviceName;
		device * next;
};
