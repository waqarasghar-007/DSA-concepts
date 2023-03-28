#include "arrayList.h"
#include "Node.h"


class linkedList
{
private:
	Node* head;
	Node* tail;
public:
	linkedList()
	{
		head = NULL;
		tail = head;
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
			tail->setNext(head);
			
		}
	}
	bool search(int key)
	{
		if (!isEmpty())
		{
			Node* traverse = head;
			do
			{
				if (traverse->getData() == key)
				{
					return true;
				}
				traverse = traverse->getNext();
			} while (traverse != head);
			
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
			do
			{
				if (traverse->getData() == old)
				{
					traverse->setData(New);
					break;
				}
				traverse = traverse->getNext();
			} while (traverse != head);


		}
		else
		{
			cout << "Not found \n";
		}
	}
	bool deleteNode(int key)
	{
		bool ret = false;
		if (search(key))
		{
			if (head->getData() == key)
			{
				Node* temp = head;
				head = temp->getNext();
				head->setPrevious(NULL); //
				delete temp;
				ret = true;
				return ret;
			}
			else
			{
				Node* previous = head;
				Node* traverse = head->getNext();
				do
				{
					if (traverse->getData() == key && traverse == tail)
					{
						//delete it and attach tail with previous
						previous->setNext(traverse->getNext());
						tail = previous;
						tail->setNext(NULL);
						delete traverse;
						ret = true;
						return ret;
						break;
					}
					else if (traverse->getData() == key)
					{
						//delete it
						previous->setNext(traverse->getNext());
						traverse->getNext()->setPrevious(previous);
						delete traverse;
						ret = true;
						return ret;
						break;
					}
					else
					{
						previous = traverse;
						traverse = traverse->getNext();
					}
				} while (traverse != head);

			}

		}
		return ret;
	}
	int frequency(int key)
	{
		if (search(key))
		{
			int freq = 0;
			Node* traverse = head;
			do
			{
				if (traverse->getData() == key)
				{
					freq++;
				}
				traverse = traverse->getNext();
			} while (traverse != head);
			return freq;
			
		}
		else
		{
			cout << "Not found \n";
		}
		return 0;
	}
	bool insertAtFront(int data)
	{
		bool ret = false;
		if (!isEmpty())
		{
			Node* newNode = new Node(data);
			head->setPrevious(newNode);
			newNode->setNext(head);
			head = newNode;
			tail->setNext(head);
			ret = true;
			return ret;
		}
		else
		{
			//first data
			Node* newNode = new Node(data);
			head = newNode;
			tail = head;
			ret = true;
			return ret;
		}
		return ret;
	}
	bool insertAtEnd(int data)
	{
		bool ret = false;
		if (!isEmpty())
		{
			Node* newNode = new Node(data);
			tail->setNext(newNode);
			newNode->setPrevious(tail);
			tail = newNode;
			tail->setNext(head);
			ret = true;
			return ret;

		}
		else
		{
			Node* newNode = new Node(data);
			head = newNode;
			tail = head;
			ret = true;
			return ret;
		}
		return ret;
	}
	bool insertAfter(int key, int data)
	{
		bool ret = false;
		
		if (!isEmpty())
		{
			if (search(key))
			{
				Node* newNode = new Node(data);
				Node* traverse = head;
				do
				{
					if (traverse->getData() == key && traverse == tail)
					{
						insertAtEnd(data);
						ret = true;
						return ret;
						break;
					}
					else if (traverse->getData() == key)
					{
						traverse->getNext()->setPrevious(newNode);
						newNode->setNext(traverse->getNext());
						traverse->setNext(newNode);
						newNode->setPrevious(traverse);
						ret = true;
						return ret;
						break;
					}
					else
					{

						traverse = traverse->getNext();
					}
				} while (traverse != head);
				
			}
			return ret;

		}
		return ret;
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
			do
			{
				cout << traverse->getData() << " , ";
				traverse = traverse->getNext();
			} while (traverse != head);
			
			cout << endl;
		}
		else
		{
			cout << "Empty \n";
		}

	}
	bool sort(linkedList& list)
	{
		bool ret = false;
		if (!isEmpty())
		{
			Node* traverse = head;
			Node* temp = NULL;
			do
			{
				temp = traverse->getNext();
				do
				{

					if (traverse->getData() > temp->getData())
					{
						//swap them
						int swap;
						swap = traverse->getData();
						traverse->setData(temp->getData());
						temp->setData(swap);
						ret = true;
					}
					temp = temp->getNext();
					
				} while (traverse!=head); //there are some extra iterations, we need to execute this loop till total size of list minus number of elements sorted;
				traverse = traverse->getNext();
			} while (traverse != head);
			
			
		}
		return ret;
	}
	Node* getHead()
	{
		return head;
	}
	int sizeOf(linkedList& list )
	{
		int size = 0;
		if (!isEmpty())
		{
			Node* traverse = head;
			do
			{
				size++;
				traverse = traverse->getNext();
			} while (traverse != head);
			return size;
		}
		return -1;
	}
	int size()
	{

		int size = 0;
		if (!isEmpty())
		{
			Node* traverse = head;
			do
			{
				size++;
				traverse = traverse->getNext();
			} while (traverse != head);
			return size;
		}
		return -1;
	}
	linkedList convertArrayListToLinkedList(arrayList<int> array1)
	{
		
		linkedList list;
		for (int i = 0; i < array1.getSize(); i++)
		{
			list.insert(array1.get(i));
		}
		return list;
		
	}
	bool addAll(linkedList& list)
	{
		bool ret = false;
		Node* temp = list.getHead();
		do
		{
			this->insert(temp->getData());
			temp = temp->getNext();
			ret = true;
		} while (temp != head);
		return ret;
	}

};
/*
void rDisplay(Node* temp)
{
	if (temp == NULL)
		return;
	cout << temp->getData() << " , ";
	rDisplay(temp->getNext());

}
*/
int main()
{
	//insertion
											
	linkedList list;
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(12);
	/*							Working
	list.display();
	int key = 112;
	if (list.search(key)) { cout << key << " found successfully \n"; }
	else { cout << key << " does not found \n"; }
	int old = 12, New = 500;
	list.update(old, New);
	cout << "list is updated , " << old << " by " << New << endl; list.display();
	key = 3;
	if (list.deleteNode(key)) { cout << key << " has successfully been deleted \n"; }
	else { cout <<key <<" does not exist \n"; }
	list.display();
	key = 1000;
	if (list.insertAtFront(key)) { cout << key << " inserted at front \n"; }
	else { cout << key << " could not be inserted \n"; } list.display();
	key = 11000;
	if (list.insertAtFront(key)) { cout << key << " inserted at front \n"; }
	else { cout << key << " could not be inserted \n"; } list.display();
	key = 5000;
	if (list.insertAtEnd(key)) { cout << key << " inserted at end \n"; }
	else { cout << key << " could not be inserted \n"; } list.display();
	key = 1, New = 48;
	cout << "Inserting " << New << " after " << key << " in "; list.display();
	if (list.insertAfter(key, New)) { cout << New << " inserted after " << key << endl; }
	else { cout << key << " does not exist \n"; } list.display();
	//rDisplay(list.getHead());
	//cout << endl;
	key = 12, New = 480;
	cout << "Inserting " << New << " after " << key << " in "; list.display();
	if (list.insertAfter(key, New)) { cout << New << " inserted after " << key << endl; }
	else { cout << key << " does not exist \n"; } list.display();
	
	cout << " Total elements in the given list are : " << list.size() << endl;
	

	
								//Not Working
	if (list.sort(list)) { cout << "List is sorted in accending order : "; list.display(); }
	else { cout << "List is empty \n"; }
	

	arrayList<int> array1;
	for (int i = 1; i <= 10; i++)
	{
		array1.insert(i * 50);
	}
	*/
	linkedList list2;
	//list2 = list2.convertArrayListToLinkedList(array1);
	//list2.display();
	list2.insert(10);
	list2.insert(20);
	list2.insert(30);
	list2.insert(40);
	if (list.addAll(list2)) { cout << " list 2 added to list 1 \n"; list.display(); }
	else { cout << " Operation failed \n"; }

	system("pause");
	return 0;
}