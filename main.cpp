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
	int choice;
	video a_video;

		cout << "Programming assignment #1"
		<< endl << "#1: Create a video:"
		<< endl << "#2 List all videos" 
		<< endl << "#3: add a device to a video"
		<< endl << "#4: remove a device a video"
		<< endl << "#5: display devices needed for a video"
		<< endl << "0 to Exit" << endl;
		cin >> choice;	
		cin.ignore(100,'\n');
	do{
		if(choice == 1)	
		{
			cout << "#1: Create a video" << endl;
			cout << "video name 1:";
			cin.get(vidName1, 20, '\n');
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
			
			cout <<"teacher:";
			cin >> teacher1;
			cin.ignore(100, '\n');
			
			a_list.addVideo(time1, vidName1, teacher1, topic1, length1);

		cout << "Programming assignment #1"
		<< endl << "#1: Create a video:"
		<< endl << "#2 List all videos"
		<< endl << "#3: add a device to a video"
		<< endl << "#4: remove a device a video"
		<< endl << "#5: display devices needed for a video"
		<< endl << "0 to Exit" << endl;
		cin >> choice;
		cin.ignore(100, '\n');	
		cout << endl;	
		}
		else if (choice == 2)
	{
		cout <<"#2: List all Videos" << endl;
		a_list.displayVideos();

		cout << endl << "Programming assignment #1"
		<< endl << "#1: Create a video:"
		<< endl << "#2 List all videos"
		<< endl << "#3: add a device to a video"
		<< endl << "#4: remove a device a video"
		<< endl << "#5: display devices needed for a video"
		<< endl << "0 to Exit" << endl;
		cin >> choice;
		cin.ignore(100, '\n');	
	
	}
		else if(choice == 3)
	{
		char deviceName[30];
		char videoName[30];
		cout <<"#3: Add a device to a video" << endl;
		a_list.displayVideos();
		cout << endl << "Select a video:" << endl;
		cin >> videoName;
		cin.ignore(100,'\n');
		cout << "create a device for the video" << endl;
		cin >> deviceName;
		cin.ignore(100,'\n');
		int s = a_list.addDevice( deviceName, videoName);
		if(s == 0) cout << "fail" << endl;

		cout << endl;	
		cout << "Programming assignment #1"
		<< endl << "#1: Create a video:"
		<< endl << "#2 List all videos"
		<< endl << "#3: add a device to a video"
		<< endl << "#4: remove a device a video"
		<< endl << "#5: display devices needed for a video"
		<< endl << "0 to Exit" << endl;
		cin >> choice;
		cin.ignore(100, '\n');	
	}
	else if(choice == 4)
	{
		char deviceName[30];	
		char videoName[30];
		cout << "#4: Remove a device from a video";
		a_list.displayVideos();	
		cout << "Select a video" << endl;
		cin >> videoName;
		cin.ignore(100,'\n');
		cout << "select a device from a video to remove" << endl;
		a_list.displayDevices(videoName);
		cout << endl;
		cin >> deviceName; 
		cin.ignore(100, '\n');
		int s =	a_list.removeDevice(deviceName, videoName);
		if(s == 0) cout << "fail" << endl;	
		
		cout << endl;	
		cout << "Programming assignment #1"
		<< endl << "#1: Create a video:"
		<< endl << "#2 List all videos"
		<< endl << "#3: add a device to a video"
		<< endl << "#4: remove a device a video"
		<< endl << "#5: display devices needed for a video"
		<< endl << "0 to Exit" << endl;
		cin >> choice;
		cin.ignore(100, '\n');	
	}
	else if(choice == 5)
	{
		char videoName[30];
		cout << "#5: Display devices for video";
		a_list.displayVideos();	
		cout << endl << "Select a video: " << endl;
		cin >> videoName;
		cin.ignore(100,'\n');
		cout << videoName << " devices: " << endl;
		a_list.displayDevices(videoName);	

		cout << endl;	
		cout << "Programming assignment #1"
		<< endl << "#1: Create a video:"
		<< endl << "#2 List all videos"
		<< endl << "#3: add a device to a video"
		<< endl << "#4: remove a device a video"
		<< endl << "#5: display devices needed for a video"
		<< endl << "0 to Exit" << endl;
		cin >> choice;
		cin.ignore(100, '\n');	
	}

	}
	while(choice != 0);
	cout << "exiting" << endl;
	
	return 0;
}
