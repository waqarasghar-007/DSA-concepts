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
	void insertAtFront(int data)
	{
		Node* newNode = new Node(data);
		newNode->setNext(head);
		head = newNode;
	}
	void insertAtEnd(int data)
	{
		Node* newNode = new Node(data);
		tail->setNext(newNode);
		tail = newNode;
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
	void insertAfter(int key, int  data)
	{
		if (search(key))
		{
			Node* newNode = new Node(data);
			if (head->getData() == key)
			{
				newNode->setNext(head->getNext());
				head->setNext(newNode);
			}
			else if (tail->getData() == key)
			{
				insertAtEnd(data);
			}
			else
			{
				Node* temp = head;
				while (true)
				{
					if (temp->getData() == key)
					{
						newNode->setNext(temp->getNext());
						temp->setNext(newNode);
						break;
					}

					temp = temp->getNext();
				}
			}


		}
		else
		{
			cerr << "0.0000";
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
			else if (tail->getData() == key)
			{
				Node* temp = head;
				while (true)
				{
					if (temp->getNext()== tail)
					{
						tail = temp;
						delete temp;
						break;
					}
					temp = temp->getNext();
				}
			}
			else
			{
				Node* previous = head;
				Node* traverse = head->getNext();
				while (traverse != NULL)
				{
					if (traverse->getData() == key && traverse == tail)
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
	void deleteTail()
	{
		Node* temp = head;
		while (temp->getNext()!=tail)
		{
			temp = temp->getNext();
		}
		tail = temp;
		tail->setNext(NULL);
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
	int getHeadData()
	{
		return head->getData();
	}
	int getTailData()
	{
		return tail->getData();
	}
	Node* getHead()
	{
		return head;
	}
	Node* getTail()
	{
		return tail;
	}
};

int main()
{
	linkedList list;
	int choice = -100 , val,key;
	cout << "Input the linked list \n Press -1 to finish \n";
	do
	{
		
		cout << "Enter value: ";
		cin >> val;
		if (val == -1)
		{
			break;
		}
		else
		{
			list.insert(val);
		}
	} while (choice != -1);
	
	cout << "Before Rotations : \n ";
	list.display();

	cout << "Enter the key to apply rotations \n";
	cin >> key;
	
	for (int i = 0; i < key; i++)
	{
		list.insertAtFront(list.getTailData());
		list.deleteTail();
		
	}

	cout << "After Rotations : \n ";
	list.display();

	system("pause");
	return 0;
}