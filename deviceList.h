#include <cstring>
#include <iostream>
#include <cstdlib>
#include "device.h"


//Chris Lu
//This code manages a deviceList class, which houses
//a Linear linked list of deviceNodes.  deviceNodes house
//a device class, have methods foradding, removing, and 
//displaying contents within the the device class.

class deviceList
{
	public:
		deviceList(); //default linear linked list constructor
		~deviceList(); //default destructor
	
		int length(); //RETURNS LENGTH
		device * find(device *);
		
		int add(char * device);	
		int add(const device & new_device);	
		
		int remove(int pos); //positional removal	
		int remove(const device & target_device); //deviceNoOde?
		int remove(char * deviceName);	
		int displayAll();	
	private:
		device * head;
};

