#include <cstring>
#include <cctype>
#include <iostream>

//Chris Lu,
//The code will manage a video class which allows applications
//to create a video, add a new video, display all video contents,
//and display video name.  The functions written here are intended to be used
//as setters and getters for the node class

class video
{
	public:
	video(); //default constructor, initializes data members to empty
	~video(); //deallocate any dynamic memory and reset

	int add(int dateAndTimeAdded, char videoName[], char teacher[], char topic[], int length);

	//still need to figure out 	
	//remove a video
	//add a required item to a video
	//remove an item for a video
	//display all items needed for a video
	//display all videos that need to be watched
	//release all dynamic memory
	private:
		int * dateAndTimeAdded; //we're storing sequentially based on this val
		char * videoName; //dyn arr
		char * teacher; //dynamic arr
		char * topic; //dyn arr
		int * length;
		//have a list of devices for watching video
};
