//#include "video.h"
#include "deviceList.h"

using namespace std;

int main()
{
	//Testing for deviceList class
	char deviceName[30];
	char devName[30];	
	deviceList devList;
	device devtoo;
	device devicee;
	cout << "Gimme a device:";
	cin.get(deviceName, 30, '\n');
	cin.ignore(100, '\n');

	cout << "another!:";
	cin.get(devName, 30, '\n');
	cin.ignore(100, '\n');
	
	devtoo.add(devName);
	devicee.add(deviceName);
	cout << devicee.get_data() << endl;

	devList.add(devicee);
	devList.add(devtoo);
	devList.displayAll();	
	
	//Testing for the Device Class
	//char deviceName[30];
	//device one_device;
	//device two_device;	
	//cout << "Gimme a device:";
	//cin.get(deviceName, 30, '\n');
	//cin.ignore(100, '\n');
	//one_device.add(deviceName);
	//two_device.add(one_device);	
	//two_device.display():

	//Testing for the Video Class
	//video video;
	//char topic[15];
	//char videoName[15];
	//char teacher[15];
	//int timestamp;
	//int length;

	//cout << "Gimme the topic: ";
	//cin.get(topic, 15, '\n');
	//cin.ignore(100, '\n');

	//cout << "Video name: ";
	//cin.get(videoName, 15, '\n');
	//cin.ignore(100, '\n');

	//cout <<"Teacher name: ";
	//cin.get(teacher, 15, '\n');
	//cin.ignore(100, '\n');
	//
	//cout <<"Length: ";
	//cin >> length;
	//cin.ignore(100, '\n');

	//cout <<"Timestampe: ";
	//cin >> timestamp;
	//cin.ignore(100, '\n');

	//video.add(timestamp, videoName, teacher, topic, length);
	//video.display();	
	
	//testing list::display, but not video::display in main
	//construct a buffer video, put a shallow copy of it into a list
	//list.add(video)
	return 0;
}
