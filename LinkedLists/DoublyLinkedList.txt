#include <iostream>
using namespace std;

class Node
{
private:
	Node* next;
	Node* previous;
	int data; //make it template later, an object may be or an array list 
public:
	Node()
	{
		next = NULL;
		previous = NULL;
		data = 0;
	}
	Node(int data)
	{
		this->data = data;
		next = NULL;
		previous = NULL;
	}
	void setNext(Node* next)
	{
		this->next = next;
	}
	Node* getNext()
	{
		return next;
	}
	void setPrevious(Node* previous)
	{
		this->previous = previous;
	}
	Node* getPrevious()
	{
		return previous;
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
			newNode->setPrevious(tail);
			tail = newNode;
			/*
			Node* traverse = head;
			while (traverse->getNext() != NULL)
			{
				traverse = traverse->getNext();
			}
			

			//traverse = newNode;
			traverse->setNext(newNode);
			//cout << "Working \n";
			*/
		}
	}
	bool search(int key)
	{
		if (!isEmpty())
		{
			Node* traverse = head;
			while (traverse != NULL)
			{
				if (traverse->getData() == key)
				{
					return true;
				}
				traverse = traverse->getNext();
			}
		}
		else
		{
			cout << "Empty \n";
		}
		return false;
	}
	void update(int old, int New)
	{
		if (search(old))
		{
			Node* traverse = head;
			while (traverse != NULL)
			{
				if (traverse->getData() == old)
				{
					traverse->setData(New);
					break;
				}
				traverse = traverse->getNext();
			}
		}
		else
		{
			cout << "Not found \n";
		}
	}
	
	void deleteNode(int key)
	{
		if (search(key))
		{
			if (head->getData() == key)
			{
				Node* temp = head;
				head = temp->getNext();
				head->setPrevious(NULL); //
				delete temp;
			}
			else
			{
				Node* previous = head;
				Node* traverse = head->getNext();
				while (traverse != NULL)
				{
					if (traverse->getData() == key && traverse==tail)
					{
						//delete it and attach tail with previous
						previous->setNext(traverse->getNext());
						tail = previous;
						tail->setNext(NULL);
						delete traverse;
						break;
					}
					else if (traverse->getData() == key)
					{
						//delete it
						previous->setNext(traverse->getNext());
						traverse->getNext()->setPrevious(previous);
						delete traverse;
						break;
					}
					else
					{
						previous = traverse;
						traverse = traverse->getNext();
					}

				}
			}
			
		}
		else
		{
			cout << "Not found \n";
		}
	}
	int frequency(int key)
	{
		if (search(key))
		{
			int freq = 0;
			Node* traverse = head;
			while (traverse != NULL)
			{
				if (traverse->getData() == key)
				{
					freq++;
					
				}
				traverse = traverse->getNext();
			}
			return freq;
		}
		else
		{
			cout << "Not found \n";
		}
		return 0;
	}
	void insertAtFront(int data)
	{
		if (!isEmpty())
		{
			Node* newNode = new Node(data);
			head->setPrevious(newNode);
			newNode->setNext(head);
			head = newNode;
		}
		else
		{
			//first data
			Node* newNode = new Node(data);
			head = newNode;
			tail = newNode;
		}
	}
	void insetAtEnd(int data)
	{
		if (!isEmpty())
		{
			Node* newNode = new Node(data);
			tail->setNext(newNode);
			newNode->setPrevious(tail);
			tail = newNode;
		}
		else
		{
			Node* newNode = new Node(data);
			head = newNode;
			tail = newNode;
		}
	}
	bool isEmpty()
	{
		if (head->getNext() == NULL)
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
	list.insert(3);
	list.insert(12);
	list.display();
	//cout << list.search(112) <<endl;
	//list.update(12, 500);
	//list.display();
	//list.deleteNode(3);
	//list.display();
	//list.insertAtFront(1000);
	//list.display();
	//list.insertAtFront(11000);
	//list.display();
	//list.insetAtEnd(5000);
	//list.display();
	system("pause");
	return 0;
}