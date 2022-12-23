#include <iostream>
using namespace std;

template <class T>
class stack
{
private:
	int top;
	T *ptr;
	int size;
public:
	stack()
	{
		size = 3;
		ptr = new T[size];
		top = -1;
	}
	stack(int size)
	{
		this->size = size;
		ptr = new T[size];
		top = -1;
	}
	void push(T data)
	{
		if (!isFull())
		{
			if (isEmpty())
			{
				top = 0;
				ptr[top] = data;
				top++;
			}
			else
			{
				ptr[top] = data;
				top++;
			}
		}
		else
		{
			cout << "Full stack \n";
		}
		
	}
	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		return false;
	}
	bool isFull()
	{
		if (top == size)
		{
			return true;
		}
		return false;
	}
	T pop()
	{
		T temp;
		if (!isEmpty())
		{
			temp = ptr[top-1];
			top--;
			return temp;
			
		}
		else
		{
			cout << "Empty stack \n";
		}
	}
	T peek()
	{
		T temp;
		if (!isEmpty())
		{
			temp = ptr[top - 1];
			return temp;

		}
		else
		{
			cout << "Empty stack \n";
		}
	}
	void display()
	{
		if (!isEmpty())
		{
			for (int i = 0; i < top; i++)
			{
				cout << ptr[i] << ",";
			}
		}
		else
		{
			cout << "Empty stack \n";
		}
	}

};
int main()
{
	stack<int> s1;
	s1.display();
	cout << endl;
	s1.push(1);
	s1.push(3);
	s1.push(2);
	cout << "peek value : " << s1.peek() << endl;
	s1.display();
	cout << endl;
	cout << "popped : " << s1.pop() <<endl;
	s1.display();
	cout << endl;
	s1.push(3);
	s1.push(2);
	s1.display();
	cout << endl;
	cout << "peek value : " << s1.peek() << endl;
	system("pause");
	return 0;
}