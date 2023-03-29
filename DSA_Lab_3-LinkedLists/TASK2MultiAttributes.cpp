#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
	Node* next;
	int age;
	string name;
	unsigned long int cnic;

public:
	Node()
	{
		next = NULL;
		age = cnic  = 0;
		name = nullptr;
	}
	Node(char* name, int age,  unsigned long int cnic )
	{
		setName(name);
		setAge(age);
		setCnic(cnic);
		next = NULL;
	}
	void setName(string name)
	{
		this->name = name;
	}
	void setAge(int age)
	{
		if (age > 0)
			this->age = age;

	}
	void setCnic(unsigned long int cnic)
	{
		this->cnic = cnic;
	}
	void setNext(Node* next)
	{
		this->next = next;
	}

	Node* getNext()
	{
		return next;
	}
	int getAge()
	{
		return age;
	}
	unsigned long int getCnic()
	{
		return cnic;
	}
	string getName()
	{
		return name;
	}
	void display()
	{
		cout << "Name : " << name << endl;
		cout << "Age: " << age << endl;
		cout << "cnic : " << cnic << endl <<endl;
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
	void insert(char* name, int age, unsigned long int cnic)
	{
		Node* newNode = new Node(name,age,cnic);
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
	void insertAtEnd(char* name, int age, unsigned long int cnic)
	{
		Node* newNode = new Node(name, age, cnic);
		tail->setNext(newNode);
		tail = tail->getNext();
	}
	void insertAtBegin(char* name, int age, unsigned long int cnic)
	{
		Node* newNode = new Node(name, age, cnic);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			newNode->setNext(head);
			head = newNode;
		}
	}
	bool searchCnic(unsigned long int key)
	{
		if (!isEmpty())
		{
			Node* traverse = head;
			while (traverse != NULL)
			{
				if (traverse->getCnic() == key)
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
	bool searchAge(int key)
	{
		if (!isEmpty())
		{
			Node* traverse = head;
			while (traverse != NULL)
			{
				if (traverse->getAge() == key)
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
	bool searchName(string key)
	{
		if (!isEmpty())
		{
			Node* traverse = head;
			while (traverse != NULL)
			{
				if (traverse->getName() == key)
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


	void updateAge(int old, int New)
	{
		if (searchAge(old))
		{
			Node* traverse = head;
			while (traverse != NULL)
			{
				if (traverse->getAge() == old)
				{
					traverse->setAge(New);
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
	void updateName(string old, string New)
	{
		if (searchName(old))
		{
			Node* traverse = head;
			while (traverse != NULL)
			{
				if (traverse->getName() == old)
				{
					traverse->setName(New);
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
	void updateCnic(unsigned long int old, unsigned long int New)
	{
		if (searchCnic(old))
		{
			Node* traverse = head;
			while (traverse != NULL)
			{
				if (traverse->getCnic() == old)
				{
					traverse->setCnic(New);
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
	void deleteNodeByCnic(unsigned long int key)
	{
		if (searchCnic(key))
		{
			if (head->getCnic() == key)
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
					if (traverse->getCnic() == key && traverse == tail)
					{
						//delete it
						previous->setNext(traverse->getNext());
						tail = previous;
						delete traverse;
						break;
					}
					else if (traverse->getCnic() == key)
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
				traverse->display();
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
	list.insert("Ajmal1",85,3520148576523);
	list.insert("Ajmal2", 75, 3520148576524);
	list.insert("Ajmal3", 65, 3520148576525);
	list.insert("Ajmal4", 55, 3520148576526);
	list.insert("Ajmal5", 45, 3520148576527);
	list.insertAtBegin("Ajmal0", 95, 3520148576522);
	list.insertAtEnd("Ajmal6", 35, 3520148576528);
	cout << "Curreent List : \n"; list.display();
	cout << endl;
	
	//searching
	int age = 45;
	if (list.searchAge(age))
	{
		cout << age << " age perosn exists \n " ; 
	}

	
	//update
	int oldAge = 75, newAge = 77;
	list.updateAge(oldAge, newAge);
	cout << oldAge << " updated by " << newAge << endl;
	cout << "Updated List : \n";
	list.display();
	//deletion
	unsigned long int cnic = 3520148576525;
	list.deleteNodeByCnic(3520148576525);
	cout << cnic << " record is deleted \n";
	cout << "Updated List : \n";
	list.display();


	system("pause");
	return 0;
}