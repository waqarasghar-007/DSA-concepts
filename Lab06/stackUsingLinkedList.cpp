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
	int sizeOfList()
	{
		int count = 0;
		Node* temp = head;
		while (temp != NULL)
		{
			count++;
			temp = temp->getNext();
		}
		return count;
	}
	int getHeadData()
	{
		return head->getData();
	}
	Node* getHead()
	{
		return head;
	}
	void setHead(Node* head)
	{
		this->head = head;
	}
};



class stack
{
private:
	linkedList *ptr;
public:
	stack()
	{
		ptr = new linkedList;
	}
	void push(int data)
	{
		ptr->insertAtFront(data);

	}
	bool isEmpty()
	{
		return ptr->isEmpty();
	}
	int pop()
	{
		int popped = ptr->getHeadData();
		ptr->deleteNode(ptr->getHeadData());
		return popped;
	}
	int peek()
	{
		return ptr->getHeadData();
	}
	void display()
	{
		ptr->display();
	}
	int Size()
	{
		return ptr->sizeOfList();
	}

};
int main()
{
	//integer type 
	stack s1;
	s1.display();
	cout << endl;
	s1.push(1);
	s1.push(3);
	s1.push(2);
	cout << "peek value : " << s1.peek() << endl;
	s1.display();
	cout << endl;
	cout << "popped : " << s1.pop() << endl;
	s1.display();
	cout << endl;
	s1.push(3);
	s1.push(2);
	s1.display();
	cout << endl;
	cout << "peek value : " << s1.peek() << endl;
	cout << "Size of stack : " << s1.Size() << endl;


	system("pause");
	return 0;
}