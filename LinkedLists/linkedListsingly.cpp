#include <iostream>
using namespace std;

class Node
{
private:
	Node* next;
	int data; //make it template later, an object may be or an array list 
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
						//delete it
						previous->setNext(traverse->getNext());
						tail = previous;
						delete traverse;
						break;
					}
					else if (traverse->getData() == key)
					{
						//delete it
						previous->setNext(traverse->getNext());
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

	//searching

	cout<<list.search(112) <<endl;
	
	//update
	list.update(12, 121);
	cout << "Update: ";
	list.display();

	//deletion
	list.deleteNode(121);
	list.display();
	list.insert(4564);
	list.display();
	/*
	list.insert(45);
	list.display();
	//frequency of a node
	int num = 121;
	cout << "Frequency of " << num << " : " << list.frequency(num) << endl;

	//insert in between
	*/
	system("pause");
	return 0;
}
