#include "deviceList.h"
//Chris Lu
//cs 163
//project #1
//deviceList.cpp
//This is the implementation of the constructor, destructor, add, and remove functions specific to the linear linked list of video devices that are housed within the video class.

deviceList::deviceList() //This is our default constructor.
{
	head = NULL; 
}

deviceList::~deviceList() //This is our default destructor.
{
	if(this->head != NULL) //If there is a list, iterate through and delete everything.
	{
		device * curr = head;
		device * next = NULL;
		while(curr != NULL)
		{
			next = curr->to_next();
			delete curr;
			curr = next;
		}
	}
	head = NULL; //Also get rid of head.
}

int deviceList::length() //Sums the length of the list.
{
	device * curr = head;
	int size = 0;
	while(curr)
	{
		size++;
		curr = curr->to_next();
	}
	return size; //Returns the number of nodes counted.
}

int deviceList::add(const device & new_device) //Copies the argument's member values into a new node and positionally inserts it into the deviceList.
{
	device * temp = new device;
	if(!temp) return 0;
	temp->add(new_device);	//Add copies its argument into device's data member.
	temp->to_next() = NULL;

		int pos = this->length();
		int count = 0;
		device * curr = head;
		device * prev = NULL;
		while(curr && (count < pos))
		{
			prev = curr;
			curr = curr->to_next();
			count++;	
		}
		if (prev == NULL) //if the list is empty
		{
			temp->to_next() = head;	
			head = temp;
		}
		else if (curr == NULL)
		{
			prev->to_next() = temp;
		} 
		else //put it between prev and curr
		{
			temp->to_next() = curr;
			prev->to_next() = temp;
		}
	return 1;
}

int deviceList::add(char * devicename) //Identical to the function above, except it takes an array.
{
	device * temp = new device;
	if(!temp) return 0;
	temp->add(devicename);	
	temp->to_next() = NULL;

		int pos = this->length();
		int count = 0;
		device * curr = head;
		device * prev = NULL;
		while(curr && (count < pos))
		{
			prev = curr;
			curr = curr->to_next();
			count++;	
		}
		if (prev == NULL) //if the list is empty
		{
			temp->to_next() = head;	
			head = temp;
		}
		else if (curr == NULL)
		{
			prev->to_next() = temp;
		} 
		else				//put it between prev and curr
		{
			temp->to_next() = curr;
			prev->to_next() = temp;
		}
	return 1;
}

//DisplayAll iterates through the linked list, calling each node's display function.
int deviceList::displayAll()
{
	if(!head) return 1;	
	device * curr = head;
	while(curr)
	{
		curr->display(); //This function couts it's data member's value.
		curr = curr->to_next();
	}
	return 1;
}

//This positional removal function checks the arguement then iterates to the position 
//of the node in the list, connects previous to current deleting the target node.
int deviceList::remove(int pos)
{
	if(pos < 0 || pos >= this->length()) return 0; //guard against bad pos inputs
	device * prev = NULL;
	device * curr = head;

	if(pos == 0) 
	{
		curr = head;
		head = head->to_next();
		delete curr;
	}
	else
	{
		int count = 0;
		curr = head;
		while(count < pos)
		{
			prev = curr;
			curr = curr->to_next();
			count++;
		}
		prev->to_next() = curr->to_next();
		delete curr;
	}
	return 0;
}

//This is a wrapper function that takes a character array, iterates through 
//the the list for a matching value, then calls the positional deletion function created above.
int deviceList::remove(char * deviceName)
{
	device * curr = head;
	int pos = 0;
	while(curr)
	{
		if(curr->compare(deviceName)) //This comparison is a strcmp that returns 0 if there is a match.
		{
			remove(pos); //This is the positional removal on line 124.
		}
		pos++;
		curr = curr->to_next();
	}
	return 0;
}

//This function is identical to the one above, except it takes a node.
int deviceList::remove(const device & target_device)
{
	device * curr = head;
	int pos = 0;	
	while(curr)
	{
		if(curr->compare(target_device))
		{
		remove(pos);
		}
		pos++;		
		curr = curr->to_next();
	}
	return 0;
}
