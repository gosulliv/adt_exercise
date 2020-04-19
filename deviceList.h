#include <cstring>
#include <iostream>
#include <cstdlib>
//#include "student.h"

//Chris Lu
//This code manages a deviceList class, which houses
//a Linear linked list of videodevices.  Member functions includ
//adding, removing, and displaying content, the functions written here
//are written for the use of video's

struct device 
{
	device * next;
	//device deviceDetails;
	char * deviceName;
};

//do we need a dedicated device node classs godddd
class deviceList
{
	public:
		deviceList(); //default linear linked list constructor
		~deviceList(); //default destructor
	
		int length(); //RETURNS LENGTH
		int add(const device & new_device);	
		int remove(const device & target_device);
		int displayAll();	
	private:
		device * head;
};

