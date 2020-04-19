#include <cstring>
#include <iostream>

//Chris Lu
//This code manages a videoDevice class, which houses
//a Linear linked list of videodevices.  Member functions includ
//adding, removing, and displaying content, the functions written here
//are written for the use of video's

struct device 
{
	device * next;
	char * deviceName;
};

class videoDevice
{
	public:
		videoDevice(); //default linear linked list constructor
		~videoDevice(); //default destructor
	private:
		device * head;
};

//get your node/class nomenclacutre clear
//id essential functions (add remove)
//get working constructor destructor
