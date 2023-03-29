#include <iostream>
using namespace std;

class Node
{
private:
	Node* next;
	int data;
public:
	Node()
	{
		next = NULL;
		data = 0;
	}
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
	void setNext(Node* next)
	{
		this->next = next;
	}
	Node* getNext()
	{
		return next;
	}
	void setData(int data)
	{
		this->data = data;
	}
	int getData()
	{
		return data;
	}

};


class linkedList
{
private:
	Node* head;
	Node* tail;
public:
	linkedList()
	{
		head = NULL;
		tail = NULL;
	}
	void insert(int data)
	{
		Node* newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->setNext(newNode);
			tail = tail->getNext();


			
		}
	}
	bool isEmpty()
	{
		if (head == NULL)
		{
			return true;
		}
		return false;
	}
	void display()
	{
		if (!isEmpty())
		{
			Node* traverse = head;
			while (traverse != NULL)
			{
				cout << traverse->getData() << " , ";
				traverse = traverse->getNext();
			}
			cout << endl;
		}
		else
		{
			cout << "Empty \n";
		}

	}

};

int main()
{
	//insertion
	linkedList list;
	list.insert(1);
	list.insert(2);
	list.insert(1);
	list.insert(12);
	list.display();
	cout << endl;


	system("pause");
	return 0;
}