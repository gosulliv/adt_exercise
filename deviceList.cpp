//This is the implementation of the constructor, destructor, add, and remove functions specific to the linear linked list of video devices that are housed within the video class.
#include "deviceList.h"

deviceList::deviceList()
{
	head = NULL; 
}

deviceList::~deviceList()
{
	if(this->head != NULL)
	{
		device * curr = head;
		device * next = NULL;
		while(curr != NULL)
		{
			next = curr->next;
			delete curr;
			curr = next;
		}
	}
	head = NULL;
}

int deviceList::length()
{
	device * curr = head;
	int size = 0;
	while(curr)
	{
		size++;
		curr = curr->next;
	}
	return size;
}

//add by direct injection or by data cretaion?
//int deviceList::add(const device & new_device)
//{
//	device * temp = new device;
//	if (!temp) return 0;
//	temp->
//
//
////we need to go from reference to * pointer	
//	
//	//	int pos = this->length();
//	
//	//44-47 is logic i stripped from eol insert.  THis is the first part, I think this is all we need,
//	//but we need to check for the following things
//	//1. other cases, this single naive add might not suffice for our needs
//	//2. if we're going EOL we need to transpile the rest of it.
//	//3. Basically, we're borrowing from a body of midrash without a very clear high-level about how we want to approach this
//	device * to_copy = & new_device;	
//	to_copy->next = head;
//	head = to_copy;
//	
//	//device * prev = NULL:
//	//int count = 0;
//	//while(curr != NULL && count < pos) //iterate to the end
//	//{
//	//prev = curr;
//	//curr = curr->next;
//	//count++
//	//}
//	//if (prev == NULL)					//if we are at the very top of the list
//	//{
//	//	to_copy->next = head;			//put to_copy before head
//	//	head = to_copy;					//put to_copy at the head
//	//}
//
//}



//int deviceList::remove(const device & target_device){}
//int deviceList::displayAll(){}

//{
//	node * curr = head;
//	while(curr)
//	{
//		curr = curr->next;
//	}
//
//}
