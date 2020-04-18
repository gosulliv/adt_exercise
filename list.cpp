#include "list.h"
//#include "video.h"
list::list()
{
	head = NULL; //statement Has no effect?
}

list::~list()
{
	if(this->head != NULL)
	{
		node * curr = head;
		node * next = NULL;
		while(curr != NULL)
		{
			next = curr->next;
			delete curr;
			curr = next;
		}
	}
}

//int list::displayAll()
//{
//	//usse video::display() here!
//	node * curr = head;
//	//curr->a_video.display();	
//	//guard against an empty list	
//	if(!curr) return 1; //how do I tell the user what error 1 is	
//	else				//display the entire list
//	{
//		//iterative while loop
//		while(curr)
//		{
//		//base case?
//			//cout << curr->videoListunit //then we need to tunnel into the video for the name	
//			curr = curr->next;
//		}
//	}
//	
//	return 0; //success!
//}
