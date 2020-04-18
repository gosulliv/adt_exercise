//#include "video.h"
#include "video.h"

using namespace std;

int main()
{
	//Test: List
	
	//constructor/destructor	
	video video;
	char topic[15];
	char videoName[15];
	char teacher[15];
	int timestamp;
	int length;

	cout << "Gimme the topic: ";
	cin.get(topic, 15, '\n');
	cin.ignore(100, '\n');

	cout << "Video name: ";
	cin.get(videoName, 15, '\n');
	cin.ignore(100, '\n');

	cout <<"Teacher name: ";
	cin.get(teacher, 15, '\n');
	cin.ignore(100, '\n');
	
	cout <<"Length: ";
	cin >> length;
	cin.ignore(100, '\n');

	cout <<"Timestampe: ";
	cin >> timestamp;
	cin.ignore(100, '\n');

	video.add(timestamp, videoName, teacher, topic, length);

	//construct a teacher, topic, and videoname
	//add those things to the video on ln 11.
	//gdb it afterwrds
	
	
	//testing list::display, but not video::display in main
	//construct a buffer video, put a shallow copy of it into a list
	
	//list.add(video)
	return 0;
}
