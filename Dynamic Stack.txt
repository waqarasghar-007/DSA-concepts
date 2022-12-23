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
			//regrow stack
			T *temp;
			temp = new T[size * 2];
			for (int i = 0; i < top; i++)
			{
				temp[i] = ptr[i];
			}
			delete[]ptr;
			ptr = temp;
			size *= 2;
			push(data);
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
			cout << "Total Enteries: " << top << endl;
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
	//integer type 
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