#include <iostream>
using namespace std;
//Structure for node
struct node
{
	int data;
	node *next;
	node *prev;
};
//class to do operations on the list
//NOTE By mutual linakge between 1 and 2, i mean that 1's next node is 2 and 2's previous node is 1
class list
{
	private:
	node *head, *tail;
	
	
	public:
	
	list()//default constructor
	{
		head=NULL;
		tail=NULL;
	}
	
	void insert(int val)//inserting node at the end of the list
	{
		node *temp=new node;
		temp->data=val;
			temp->next=NULL;
			temp->prev=NULL;//a new node with next and prev declared to be null
		
		if(head==NULL)
		{
			head=temp;
			tail=temp;
		            
			
		}
		else
		{
			tail->next=temp;
			temp->prev=tail;
			temp->next=NULL;
			tail=temp;//temp is made the next element of tail by mutual linkage and temp is made as tail
			
		}
		
	}
	void insertat(int pos, int val)
	{
		node *bravo=new node;
		node *charlie=new node;
		node *alpha=new node;
		bravo->data=val;
		bravo->next=NULL;
		bravo->prev=NULL;//a new node
		if(pos==1)
		{
			head->prev=bravo;
			bravo->prev=NULL;
			bravo->next=head;
			head=bravo;//bravo is linked to head by mutual linkage and bravo is made as head
		}
		else
		{
		charlie=head;
		for(int i=1;i<pos;i++)
		{
			charlie=charlie->next;
			
		}
	           alpha=charlie->prev;
	           alpha->next=bravo;
	           bravo->prev=alpha;
	           bravo->next=charlie;
	           charlie->prev=bravo;//mutual linakge between alpha and charlie is removed
			               //new link between alpha and bravo
			               //new link between bravo and charlie
		}
	}
	void deletee()
	{
		node *tango=new node;
		tango=tail->prev;
		tango->next=NULL;
		tail=tango;
		
	}//tango is made as tails previous node and the tail element is removed . tango is made as the tail
	
	void deleteat(int pos)
	{
		node *delta=new node;
		node *echo=new node;
		node *foxtrot=new node;
		echo=head;
		
		if(pos==1)
		{
			delta=echo;//delta is made as head
			echo=echo->next;//echo is delta's next
			echo->prev=NULL;
			delta->next==NULL;
			head=echo;
			delete delta;//mutual link is deleted between echo and delta and echo is made as head. delta is deletd
		}
		else
		{
		for(int i=1;i<pos;i++)
		{
			echo=echo->next;
		}
		cout<< echo->data<<"\n";
		delta=echo->prev;
		foxtrot=echo->next;
		delta->next=foxtrot;
		foxtrot->prev=delta;
		echo->next=NULL;//mutual link bwtween delta and echo && echo and foxtrot is removed
			        //a new mutual link is created between delta and foxtrot
		echo->prev=NULL;
		delete echo;//echo is deleted
		}
		
	}
	
	int countitems()
	{
		int i=0;
		node *mike=new node;
		mike=head;
		while(mike!=NULL)
		{
			i++;
			mike=mike->next;
		}
		
		return i;//counting elements from head to tail and returning the value
	}
	
	void display()
	{
		node *temp=new node;
		temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"-->";
			temp=temp->next;
		}
		cout<<"NULL\n";
	}
	
};
int main()
{
	list a;
	int n=0,m=0,i1=0,pos=0,data=0,india=0,juliet=0;
	cout<<"\n Do you have the initial list? \nif yes press 1\nif not press 2";
	cin>>i1;
	switch(i1)
	{
	case 1:
	cout<<"\n enter the no of elements in list ";
	cin>>m;
	cout<<"\n enter the elements";
	 for(int i=1;i<=m;i++)
	{
		cin>>n;
		a.insert(n);
	}
	break;
	
	case 2:
	break;
	}
	
	cout<<"\n the linked list is \n";
	a.display();
	do
	{
	cout<<"\nDo you want to insert a node?\n If yes press 1 \n If no press 2";
	cin>>i1;
	switch(i1)
	{
		case 1:
		cout<<"enter the position to enter and the data";
		cin>>pos>>data;
		if(pos==a.countitems())
		{
			a.insert(data);
		}
		else
		{
			a.insertat(pos,data);
			break;
		}
		case 2:
		break;
	}
	cout<<"\n";
	a.display();
	cout<<"\nDo you want to delete a node?\n If yes press 1 \n If no press 2";
	cin>>i1;
	switch(i1)
	{
		case 1:
		cout<<"\n the position to delete";
		cin>>pos;
		juliet=a.countitems();
		if(pos==juliet)
		a.deletee();
		else
		a.deleteat(pos);
		
		case 2:
		break;
	}
	cout<<"\n";
	a.display();
	
	cout<<"\n Do you want to repeat any operation?\n If yes press 1 \n If no press 0";
	cin>>india;
	}while(india);
	return 0;
}


