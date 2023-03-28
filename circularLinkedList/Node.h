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