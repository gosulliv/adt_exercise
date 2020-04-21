#include "list.h"

using namespace std;
int main()
{
	char vidName1[20];
	char teacher1[20];
	char topic1[20];
	int time1;
	int length1;
	list a_list;
	//char vidName2[20];
	//char teacher2[20];
	//char topic2[20];
	//int time2;
	//int length2;
	
	//char vidName3[20];
	//char teacher3[20];
	//char topic3[20];
	//int time3;
	//int length3;
	
	cout <<"Video name 1:";
	cin.get(vidName1, 20, '\n');
	cin.ignore(100, '\n');

	cout <<"teacher name 1:";
	cin.get(teacher1, 20, '\n');
	cin.ignore(100, '\n');

	cout <<"topic  name 1:";
	cin.get(topic1, 20, '\n');
	cin.ignore(100, '\n');

	cout <<"time 1:";
	cin >> time1;
	cin.ignore(100, '\n');

	cout <<"length1:";
	cin >> length1;
	cin.ignore(100, '\n');

	a_list.addVideo(time1, vidName1, teacher1, topic1, length1);

	//Testing for deviceList class
	video a_video;
	char deviceName[30];
	char devName[30];	
	char thirdName[30];	
	deviceList devList;
	device devtoo;
	device devicee;
	device thirdD;	
	cout << "Gimme a device:";
	cin.get(deviceName, 30, '\n');
	cin.ignore(100, '\n');

	cout << "another!:";
	cin.get(devName, 30, '\n');
	cin.ignore(100, '\n');

	cout << "third:";
	cin.get(thirdName, 30, '\n');
	cin.ignore(100, '\n');

	thirdD.add(thirdName);
	devtoo.add(devName);
	devicee.add(deviceName);

	a_video.addDevice(devtoo);
	a_video.addDevice(thirdD);
	a_video.addDevice(devicee);	
	
	a_video.displayAll_Devices();	
	
	a_video.removeDevice(devicee);
	cout << endl;	
	a_video.displayAll_Devices();	
	//cout << devicee.get_data() << endl;
	
	//devList.add(thirdD);
	//devList.add(devicee);
	//devList.add(devtoo);

	//devList.displayAll();
	//devList.remove(devtoo);
	//devList.remove(thirdD);
	
	
	//cout << "once more" << endl;
	//devList.displayAll();
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
