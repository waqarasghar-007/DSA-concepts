#include <iostream>
using namespace std;
template <class T>
class list
{
protected:
	T *arr;
	int maxSize;
	int currentSize;
public:
	list()
	{
		maxSize = 5;
		arr = new T[maxSize];
		currentSize = -1;
	}
	list(int size)
	{
		maxSize = size;
		arr = new T[maxSize];
		currentSize = -1;
	}
	void inset(T data)
	{
		if (currentSize == maxSize)
		{
			cerr << "ArrayList is full \n";
		}
		else if (currentSize == -1)
		{
			currentSize = 0;
			arr[currentSize] = data;
			currentSize++;
		}
		else if (currentSize < maxSize)
		{
			arr[currentSize] = data;
			currentSize++;
		}
	}
	void insertAtFirst(T data)
	{
		if (currentSize == -1)
		{
			currentSize = 0;
			arr[currentSize] = data;
			currentSize++;
		}
		else
		{
			arr[0] = data;
		}

	}
	void inserAtLast(T data)
	{
		if (currentSize == -1)
		{
			currentSize = 0;
			arr[currentSize] = data;
			currentSize++;
		}
		else if (currentSize == maxSize)
		{
			arr[currentSize - 1] = data;
			cerr << "Array is full Last entry is overwritten with your new data i.e " << data << endl;
		}
		else
		{
			arr[currentSize] = data;
			currentSize++;
		}
	}
	list(const list &obj)
	{
		for (int i = 0; i < currentSize; i++)
		{
			this->arr[i] = obj->arr[i];
		}
	}
	~list()
	{
		delete arr;
	}
	void display()
	{
		for (int i = 0; i <currentSize; i++)
		{
			cout << arr[i] << " , ";
		}
		cout << endl;
	}
};


int main()
{
	list<int> l1;
	l1.inset(3);
	l1.inset(4);
	l1.inset(2);
	l1.display();
	l1.insertAtFirst(50);
	l1.display();
	l1.inserAtLast(500);
	l1.inserAtLast(5800);
	l1.display();
	list<int> l2;
	l2 = l1;
	l2.display();
	system("pause");
	return 0;
}