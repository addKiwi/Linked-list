#include <cstdlib>
#include <iostream>

using namespace std;

class list
{
private:
	typedef struct node
	{
		int data;
		node * next;
	}*nodePtr;

	nodePtr head;
	nodePtr curr;
	nodePtr temp;

public:
	list();
	void addhead(int addData);
	void addmiddle(int addData, int pos);
	void addTail(int addData);
	void deleteNode(int delData);
	void printNode();
	void length();
};

list::list()
{
	head = NULL;
	curr = NULL;
	temp = NULL;
}
void list::addhead(int addData)
{
	nodePtr n = new node;
	n->next = NULL;
	n->data = addData;

	temp = head;
	curr = head;
	n->next = temp;
	head = n;
	cout << addData << " was added in the list \n";
}
void list::addmiddle(int addData, int pos)
{
	int h = 0;
	nodePtr n = new node;
	n->data = addData;
	n->next = NULL;
	temp = head;
	curr = head;
	
	while (curr != NULL)
	{
		curr = curr->next;
		h++;
	}
	curr = head;
	if (curr == NULL)
	{
		head = n;
		cout << addData << " was added in the list \n";
	}
	else if (pos!=1 && pos<=h) {
		
			for (int i = 0; i < pos - 1; i++)
			{
				temp = curr;
				curr = curr->next;
			}
			temp->next = n;
			n->next = curr;
			cout << addData << " was added in the list \n";	
	}
	else
	{
		cout << "Wrong position\n";
	}
}


void list::addTail(int addData)
{
	nodePtr n = new node;
	n->data = addData;
	n->next = NULL;
	curr = head;
	if (head != NULL)
	{
		curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = n;
		
		cout << addData << " was added in the list \n";
	}
	else
	{
		head = n;
		cout << addData << " was added in the list \n";
	}
}


void list::deleteNode(int delData)
{
	nodePtr delPtr = NULL;
	temp = head;
	curr = head;
	while (curr != NULL && curr->data != delData)
	{
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL)
	{
		cout << delData << " Was not in the list\n";
		delete delPtr;
	}
	else
	{
		delPtr = curr;
		curr = curr->next;
		temp->next = curr;
		if (delPtr == head)
		{
			head = head->next;
			temp = NULL;
		}
		delete delPtr;
		cout << "The value " << delData << " was deleted\n";
	}
}

void list::printNode()
{
	curr = head;
	cout << endl;
	while (curr != NULL)
	{
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}

void list::length()
{
	int h = 0;
	curr = head;
	cout << endl;
	while (curr != NULL)
	{
		curr = curr->next;
		h++;
	}
	cout << h << " Lenght of the list \n" << endl;
}

int menu()
{
	cout << " 1 : Add in the head \n";
	cout << " 2 : Add in the middle \n";
	cout << " 3 : Add in the tail \n";
	cout << " 4 : Show List \n";
	cout << " 5 : Delete element \n";
	cout << " 6 : Length of the list \n";
	cout << " 7 : Exit \n";
	return 0;
}


int main()
{
	int a, p, v, d;
	int ex = 20202;
	
	list Node;
	do
	{
		menu();
		cout << " Enter you choice\n";
		cin >> a;
		switch (a)
		{
		case 1: cout << "Enter Value of new element\n ";
			cin >> v;
			Node.addhead(v);
			break;

		case 2: cout << "Enter Value of new element\n ";
			cin >> v;
			cout << "Enter position\n";
			cin >> p;
			Node.addmiddle(v, p);
			break;

		case 3: cout << "Enter Value of new element\n ";
			cin >> v;
			Node.addTail(v);
			break;

		case 4:
			Node.printNode();
			break;

		case 5:
			cout << "Enter removable elevent \n";
			cin >> d;
			Node.deleteNode(d);
			break;

		case 6: Node.length();
			break;

		case 7: 
			a= ex; exit;
			break;
		default: cout << "Bad choise! Enter you choice\n";
			break;
		}
	} while (a != ex);
		return 0;
	
}