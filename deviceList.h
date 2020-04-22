#include <cstring>
#include <iostream>
#include <cstdlib>
#include "device.h"

//Chris Lu
//CS163
//Project #1
//deviceList.h

//This code manages a deviceList class, which houses
//a Linear linked list of deviceNodes.  deviceNodes house
//a device class, have methods foradding, removing, and 
//displaying contents within the the device class.

class deviceList
{
	public:
		deviceList(); //default linear linked list constructor
		~deviceList(); //default destructor
	
		int length(); //calculates number of nodes in the list
	
		//This pair of add functions createa a device node with the arguements, inserting them into the list.
		int add(char * device);	//this version takes a char string
		int add(const device & new_device);	//this version takes a node 
	
		//All of these searches are based on positional removal.
		int remove(int pos); //positional removal	
		int remove(const device & target_device); //Searches through the linked list for a match.
		int remove(char * deviceName);//This version is identical except it takes a char array.
		int displayAll();//Iterates through the list, calling each device's display function.
	private:
		device * head; //This class houses and shields a linear linked list of video devices.
};

