/*Name: Chinmay Gambhir
Class: SE2
Roll Number: 81
PRN Number: F24122008

Problem Statement
Department of Computer Engineering has student's club named
'pinnacle club’. Students of second, third and final year of department can be granted
membership on request. Similarly on may cancel the membership of club .First node is
reserved for the president of the club and last node is reserved for the secretary of club .write
C++ program to maintain club members information using singly linked list .store student PRN
and Name .Write function to:
a) Add and Delete the members as well as the president or even secretary.
b) Compute total numbers of members of club.
c) Display members.z
d) Display list in reverse order using recursion.zz
e) Two linked lists exizzsts for two divisions .Concatenate two lists. 
*/

#include <iostream>
#include <string.h>
using namespace std;

class node
{
	public:
		int prn;
		string name;
		node *next;
};

class list
{
	node *head,*temp;
	public:
		list()
		{
			head = NULL;
		}
		node* create(int val,string n);
		void insertbeg();
		void insertend();
		void insertat(int i);
		void deleteat(int i);
		int count();
		void reverse();
		void rev(node *t);
		void concatenate(list A,list B);
		void display();
		void op();
};

node* list::create(int val,string n)
{
	temp = new node;
	if(temp == NULL)
	{
		cout<<"Memory allocation failed";
		return 0;
	}
	else
	{
		temp->prn=val;
		temp->name=n;
		temp->next=NULL;
		return temp;
	}
}

void list::insertbeg()
{
	int val;
	string n;
	cout<<"Enter PRN "<<endl;
	cin>>val;
	cout<<"Enter Name "<<endl;
	cin>>n;
	node *newnode = create(val,n);
	temp=head;
	if(head==NULL)
	{
		head = newnode;
		head->next=NULL;
	}
	else
	{
		newnode->next=head;
		head=newnode;
		cout<<"We have a new President"<<endl;
	}
	
}

void list::insertend()
{
	int val;
	string n;
	cout<<"Enter PRN "<<endl;
	cin>>val;
	cout<<"Enter Name "<<endl;
	cin>>n;
	node *newnode = create(val,n);
	temp=head;
	if(head==NULL)
	{
		head = newnode;
		head->next=NULL;
	}
	else
	{
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next=newnode;
		newnode->next=NULL;
		cout<<"We have a new Secretory"<<endl;
	}
}

void list::insertat(int i)
{
	int val, pos = i-1,counter = 1;
	string n;
	node* ptr;
	temp=head;
	while(temp->next != NULL)
	{
		temp= temp->next;
		counter ++;
	}
	temp = head;
	if(i==1)
	{
		insertbeg();
	}else if(pos>counter || i<=0)
	{
		cout<<"Entered position is out of scope"<<endl;
	}
	else
	{
		cout<<"Enter PRN "<<endl;
		cin>>val;
		cout<<"Enter Name "<<endl;
		cin>>n;
		node *newnode = create(val,n);
		temp=head;
		while(pos--)
		{
			ptr= temp;
			temp= temp->next;
		}
		newnode->next=temp;
		ptr->next=newnode;
		cout<<"Member inserted at position :"<<i<<endl;
	}
}

void list::deleteat(int i)
{
	int pos = i-1,counter =1;
	node *left,*right;
	temp=head;
	while(temp->next!=NULL)
	{
		temp = temp->next;
		counter ++;
	}
	temp= head;
	if(i==1)
	{
		left = head;
		head = head->next;
		delete left;
	}
	else if(pos>counter || i<=0)
	{
		cout<<"Position doesn't exits"<<endl;
	}
	else
	{
		while(pos--)
		{
			left = temp;
			temp = temp->next;
			right = temp->next;
		}
		
		left->next=right;
		delete temp;
		cout<<"Member removed "<<endl;
	}
}
void list::display()
{
	temp=head;
	cout<<"President ";
	cout<<temp->prn<<" - "<<temp->name<<" -> ";
	if(temp->next!= NULL)
	{
		temp = temp->next;
	}
	while(temp->next != NULL)
	{
		cout<<temp->prn<<" - "<<temp->name<<" -> ";
		temp=temp->next;
	}
	cout<<"Secretory ";
	cout<<temp->prn<<" - "<<temp->name<<" -> ";
	cout<<" NULL "<<endl;
}

int list::count()
{
	int ct=0;
	temp=head;
	while(temp!=NULL)
	{
		ct ++;
		temp = temp->next;
	}
	return ct;
}

void list::concatenate(list A,list B)
{
	node *last;
	node *t = A.head;
	while(t!=NULL)
	{
		int val = t->prn;
		string n = t->name;
		temp = create(val,n);
		if(head==NULL)
		{
			head= temp;
			head->next= NULL;
			last = head;
		}
		else
		{
			last->next=temp;
			last = temp;
		}
		t = t->next;
	}
	last->next=B.head;
	t= B.head;
	while(t!=NULL)
	{
		int val = t->prn;
		string n = t->name;
		temp = create(val,n);
		last->next=temp;
		last = temp;
		t = t->next;
	}
	last->next = NULL;
}

void list::op()
{
	while(1)
	{
		int choice;
		cout<<"\nEnter: \n1. Add \n2. Delete \n3. Member's Count \n4. Display \n5. Reverse the List \n0. Prev Menu"<<endl;
  		cin>>choice;
  		switch(choice)
  		{
  			case 1:{
  				char c;
  				cout<<"\nEnter: \nA. Add President \nB. Add Secretary \nC. Add Member"<<endl;
				cin>>c;
				switch(c)
				{
					case 'a':
					case 'A':{
						insertbeg();
						break;
					}
					case 'b':
					case 'B':{
						insertend();
						break;
					}
					case 'c':
					case 'C':{					
						insertat(2);
						break;
					}
						
				}

				break;
			  }
			  
			  case 2:{
					  	char c;
						cout<<"\nEnter: \nA. Delete President \nB. Delete Secretary \nC. Delete Member"<<endl;
						cin>>c;
						switch(c) {
							case 'A': {
										deleteat(1);
										cout<<"Club must have a President. Enter Details"<<endl;
										insertbeg();
										break;
										}
							case 'B': {
								deleteat(count());
								cout<<"Club must have a Secretary. Enter Details"<<endl;
								insertend();
								break;
								}
							case 'C': {
								int j;
								cout<<"Enter Position for Deletion"<<endl;
								cin>>j;
								deleteat(j);
								break;
								}
							}

				break;
			  }
			  case 3:{
			  	cout<<"Count :"<<count()<<endl;
				break;
			  }
			  case 4:{
			  	if(head == NULL)
			  	{
			  		cout<<"NULL"<<endl;
				  }
				  else{
				  	display();
				  }
				break;
			  }
			  case 5:{
			  	reverse();
			  	
				break;
			  }
			  case 0:{
			  	
				return;
			  }
		  }

	}
}

void list::rev(node *t)
{
	if(t->next != NULL)
	{
		rev(t->next);
	}
	if(t==head)
	{
		cout<<"Secretary: "<<t -> prn<<" - "<<t -> name<<endl;
	
	}
	else if(t -> next == NULL){
		cout<<"President: "<<t -> prn<<" - "<<t -> name<<" -> ";
	}
	else{
		cout<<"Member: "<<t -> prn<<" - "<<t -> name<<" -> ";
	}
}

void list::reverse()
{
	rev(head);
}

int main()
{
	list X,Y,L;
	int c;
	while(1)
	{
		cout<<"Enter: \n1. List A \n2. List B \n3. Concatenate\n0. Exit"<<endl;
		cin>>c;
		switch(c) {
			case 1: cout<<"\nList A:"; X.op(); break;
			case 2: cout<<"\nList B:"; Y.op(); break;
			case 3: L.concatenate(X,Y); L.display(); break;
			case 0: return 0;
		}

	}
	
}
