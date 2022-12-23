#include <iostream>
using namespace std;

template <class T>
class queu
{
private:
	int front;
	T *ptr;
	int rear;
	int size;
public:
	queu()
	{
		size = 3;
		ptr = new T[size];
		front = rear = -1;
	}
	queu(int size)
	{
		this->size = size;
		ptr = new T[size];
		front = rear = -1;
	}
	void Enqueu(T data)
	{
		if (!isFull())
		{
			if (isEmpty())
			{
				front = rear = 0;
				ptr[rear] = data;
				rear++;
			}
			else
			{
				ptr[rear] = data;
				rear++;
			}
		}
		else
		{
			//regrow stack
			T *temp;
			temp = new T[size * 2];
			for (int i = 0; i < rear; i++)
			{
				temp[i] = ptr[i];
			}
			delete[]ptr;
			ptr = temp;
			size *= 2;
			Enqueu(data);
		}
		
	}
	bool isEmpty()
	{
		if (front == -1 && rear==-1)
		{
			return true;
		}
		return false;
	}
	bool isFull()
	{
		if (rear == size)
		{
			return true;
		}
		return false;
	}
	T Dequeu()
	{
		T temp;
		if (!isEmpty())
		{
			temp = ptr[front];
			for (int i = 0; i < rear; i++)
			{
				ptr[i] = ptr[i + 1];
			}
			rear--;
			return temp;
			
		}
		else
		{
			cout << "Empty Queu \n";
		}
	}
	T peek()
	{
		T temp;
		if (!isEmpty())
		{
			temp = ptr[front];
			return temp;

		}
		else
		{
			cout << "Empty Queu \n";
		}
	}
	void display()
	{
		if (!isEmpty())
		{
			cout << "Total Enteries: " << rear << endl;
			for (int i = 0; i < rear; i++)
			{
				cout << ptr[i] << ",";
			}
		
		}
		else
		{
			cout << "Empty Queu \n";
		}
	}

};
int main()
{
	//integer type 
	queu<int> s1;
	s1.display();
	cout << endl;
	s1.Enqueu(1);
	s1.Enqueu(3);
	s1.Enqueu(2);
	cout << "peek value : " << s1.peek() << endl;
	s1.display();
	cout << endl;
	cout << "Dequeud : " << s1.Dequeu() <<endl;
	s1.display();
	cout << endl;
	s1.Enqueu(3);
	s1.Enqueu(2);
	s1.display();
	cout << endl;
	cout << "peek value : " << s1.peek() << endl;



	system("pause");
	return 0;
}