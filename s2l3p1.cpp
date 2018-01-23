#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
	node *prev;
};

class list
{
	private:
	node *head, *tail;
	
	
	public:
	
	list()
	{
		head=NULL;
		tail=NULL;
	}
	
	void insert(int val)
	{
		node *temp=new node;
		temp->data=val;
			temp->next=NULL;
			temp->prev=NULL;
		
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
			tail=temp;
			
		}
		
	}
	void insertat(int pos, int val)
	{
		node *bravo=new node;
		node *charlie=new node;
		node *alpha=new node;
		bravo->data=val;
		bravo->next=NULL;
		bravo->prev=NULL;
		if(pos==1)
		{
			head->prev=bravo;
			bravo->prev=NULL;
			bravo->next=head;
			head=bravo;
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
	           charlie->prev=bravo;
		}
	}
	void deletee()
	{
		node *tango=new node;
		tango=tail->prev;
		tango->next=NULL;
		tail=tango;
		
	}
	
	void deleteat(int pos)
	{
		node *delta=new node;
		node *echo=new node;
		node *foxtrot=new node;
		echo=head;
		
		if(pos==1)
		{
			delta=echo;
			echo=echo->next;
			echo->prev=NULL;
			delta->next==NULL;
			head=echo;
			delete delta;
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
		echo->next=NULL;
		echo->prev=NULL;
		delete echo;
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
		
		return i;
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


