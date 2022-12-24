#include <iostream>
using namespace std;
template <class T>
class arrayList
{
	private:
		int size;
		T *arr;
		int total;
	public:
		arrayList()
		{
			size = 3;
			arr = new T[size];
			total = -1;
		}
		arrayList(int size)
		{
			this->size = size;
			arr = new T[size];
			total = -1;
		}
		void insert(T data)
		{
			if(!isFull())
			{
				if(isEmpty())
				{
					total = 0;
					arr[total] = data;
					total++;
				}
				else
				{
					arr[total] = data;
					total++;
				}
			}
			else
			{
				T *temp;
				temp = new T[size*2];
				for(int i=0;i<total;i++)
				{
					temp[i]=arr[i];
				}
				delete []arr;
				arr = temp;
				size*=2;
				insert(data);
			}
		}
		bool isFull()
		{
			if(total==size)
			{
				return true;
			}
			return false;
		}
		bool isEmpty()
		{
			if(total==-1)
			{
				return true;
			}
			return false;
		}
		int search(T key)
		{
			if(!isEmpty())
			{
				for(int i=0;i<total;i++)
				{
					if(arr[i]==key)
					{
						return i;
					}
				}
			}
			
			return -1;
		}
		void display()
		{
			if(!isEmpty())
			{
				for(int i=0;i<total;i++)
				{
					cout<<arr[i] <<" ";
				}
			}

		}
		void clear()
		{
			size = 3;
			arr = new T[size];
			total = -1;
		}
		void Delete(T key)
		{
			int index = search(key);
			if(index==-1)
			{
				cout<<"Datra not found! \n";
			}
			else
			{
				for(int i=index;i<total-1;i++)
				{
					arr[i] = arr[i+1];
				}
				total--;
			}
		}
		void update(T old,T New)
		{
			int index = search(old);
			if(index!=-1)
			{
				arr[index]=New;
			}
			else
			{
				cout<<"Data not found \n";
			}
		}
	
};
int main()
{
	
	arrayList<int> list;
	for(int i=1;i<=10;i++)
	{
		list.insert(3*i);
	}
	list.display();
	cout<<endl;
	int index =  list.search(5);
	if(index!=-1)
	{
		cout<<"Index : " <<index <<endl;
	}
	else
	{
		cout<<"Not found! \n";
	}
	list.Delete(30);
	list.display(); cout<<endl;
	list.update(15,51);
	list.display(); cout<<endl;
	list.update(50,15);
	list.display(); cout<<endl;
	list.clear();
	cout<<"After clear : \n";
	list.display(); cout<<endl;
	system("pause");
	return 0;
}
