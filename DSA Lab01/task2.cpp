#include <iostream>
using namespace std;
template <class T>
class myList
{
protected:
	T *arr;
	int maxSize;
	int currentSize;
public:
	myList()
	{
		maxSize = 5;
		arr = new T[maxSize];
		currentSize = -1;
	}
	myList(int size)
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
			arr[currentSize-1] = data;
			cerr << "Array is full Last entry is overwritten with your new data i.e " <<data <<endl;
		}
		else
		{
			arr[currentSize] = data;
			currentSize++;
		}
	}
	void insertAtIndex(T data, int index)
	{
		if (index > 0 && index < maxSize)
		{
			arr[index] = data;
		}
	}
	int size()
	{
		return currentSize;
	}
	bool empty()
	{
		if (currentSize == -1)
			return true;
		return false;
	}
	bool full()
	{
		if (currentSize == maxSize)
			return true;
		return false;
	}
	myList(const myList &obj)
	{
		for (int i = 0; i < currentSize; i++)
		{
			this->arr[i] = obj->arr[i];
		}
	}
	~myList()
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
	myList<int> l1;
	if (l1.empty())
	{
		cout << "list is empty \n";
	}
	l1.inset(3);
	l1.inset(4);
	l1.inset(2);
	l1.display();
	cout << "Size of the arrayList is " << l1.size() << endl;
	l1.insertAtFirst(50);
	l1.display();
	cout << "Size of the arrayList is " << l1.size() << endl;
	l1.inserAtLast(500);
	l1.inserAtLast(5800);
	l1.display();
	cout << "Size of the arrayList is " << l1.size() << endl;
	if (l1.full())
	{
		cout << "List is full \n";
	}
	l1.insertAtIndex(12345, 3);
	l1.display();
	myList<int> l2;
	l2 = l1;
	l2.display();
	system("pause");
	return 0;
}