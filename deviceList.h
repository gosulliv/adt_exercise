#include <cstring>
#include <iostream>
#include <cstdlib>
#include "device.h"


//Chris Lu
//This code manages a deviceList class, which houses
//a Linear linked list of deviceNodes.  deviceNodes house
//a device class, have methods foradding, removing, and 
//displaying contents within the the device class.

struct deviceNode
{
	deviceNode * next;
	device deviceData; //NOT a pointer
};

//do we need a dedicated device node classs godddd
class deviceList
{
	public:
		deviceList(); //default linear linked list constructor
		~deviceList(); //default destructor
	
		int length(); //RETURNS LENGTH
		int add(const device & new_device);	
		int remove(const device & target_device); //deviceNoOde?
		int displayAll();	
	private:
		deviceNode * head;
};

