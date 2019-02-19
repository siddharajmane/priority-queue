#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;



class node
{
	public:
	char name[20];
	int pri;
	node *next;
	node()
	{
		next=NULL;
	}
};

int n=0;
class queue
{
	public:
	node *front=NULL;
	node *rear=NULL;
	queue()
	{
		rear=front=NULL;
	}
	void enqueue()
	{
		int pri1;
		char name1[20];
	 	node *temp=new node;
	 	if(front==NULL)
		 {	
			 cout<<"\n enter the name and priority of patient";
				cin>>name1;
				cin>>pri1;
			 strcpy(temp->name,name1);
			 temp->pri=pri1;
			 rear=front=temp;
		 }
		 else
		 {
			 n=0;
			 cout<<"\n enter the name and priority of student";
			 cin>>name1;
			 cin>>pri1;
			 strcpy(temp->name,name1);
			 temp->pri=pri1;
			 node *p;
			 node *prev=NULL;
			 p=front;

			 while((p->next!=NULL)&&(temp->pri)<=(p->pri))
			 {
				 prev=p;
				 p=p->next;
				 
				 
			 }
			 if(p->next==NULL)
				 {
					 n=1;
					 if(p->pri>=temp->pri)
					 {
					 p->next=temp;
					 rear=rear->next;
					 }
					 else if(p->pri<=temp->pri)
					 {
						 if(p==front)
						 {
							temp->next=front;
							front=temp;
						 }
						 else
						{
							prev->next=temp;
							temp->next=p;
						}
						 	 
					 }
					 
				 }
				 if(p==front)
				 {
					 if(p->pri<=temp->pri)
					 {
						temp->next=front;
						front=temp;
					 }
				 }
				 if(n==0)
				 {
				 	node *pa,*pb;
				 	pa=front;
				 	while(pa->next!=NULL&&(temp->pri)<=(pa->pri))
				 	{
						pb=pa;
						pa=pa->next;	 
				 	}
				pb->next=temp;
				temp->next=pa;
				}
				 
				 
				 
				 
				 
			 }
		 
	 	
	 }
	 	
	 
	
	node* dequeue()
	{
		node *newn=new node;
		if(front==rear)
		{
			newn=front;
			front=rear=NULL;
			return newn;
			delete newn;
		}
		else
		{
			newn=front;
			front=front->next;
			return newn;
			delete newn;
		}
	
	}
	node* q_rear()
	{
		if(!isempty())
		{
			return rear;
		}
	}
	node* q_front()
	{
		if(!isempty())
		{
			return front;
		}
	}
	int isempty()
	{
		if(front==NULL&&rear==NULL)
		{
			return 1;
		}
		else
		{
		
			return 0;
		}
	
	}
	int isfull()
	{
		node *newn=new node;
		if(newn==NULL)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	void display()
	{
		node *temp;
		temp=front;
		cout<<"\n--------patient and their priority---------";
		cout<<"\n---------name---------priority-------";
		while(temp!=NULL)
		{
			cout<<"\n       "<<temp->name<<"        "<<temp->pri<<"        ";
			temp=temp->next;	
		}
	}
	
	

};




int main()
{
queue s1;
node *n=new node;
int ch,n4,data;
char name[20];
n4=1;
	while(n)
	{
		cout<<"\n 1.enqueue \n 2.dequeue \n 3.display";
		cout<<"\n enter the choice";
		cin>>ch;
		switch(ch)
		{
			case 1:
				s1.enqueue();
				break;
			case 2:if(!s1.isempty())
				{
				n=s1.dequeue();
				cout<<n->pri;
				}
				else
				{
					cout<<"queue is empty";
				}
				break;
			case 3:s1.display();
			break;
			default: cout<<"wrong choice";
		
		}
	
	}

}


