#include <iostream>
using namespace std;

template <class Type>
class Set
{
private:
	int size;
	int capacity;
	Type *arr;
public:
	Set()
	{
		capacity = 5;
		arr = new Type[capacity];
		size = 0;
	}
	~Set()
	{
		delete[]arr;
	}
	void add_member(Type elem)
	{
		if (!isFull())
		{
			bool duplicate = false;
			if (!isEmpty())
			{
				
				for (int i = 0; i < size; i++)
				{
					if (arr[i] == elem)
					{
						duplicate = true;
						break;
					}
				}

			}
			if (duplicate)
			{
				cerr << "error: Duplicate value \n";
			}
			else
			{
				arr[size] = elem;
				size++;
			}
			
		}
		else
		{
			cerr << "Full \n";
		}
	}
	void rm_member(Type elem)
	{
		if (!isEmpty())
		{
			if (find(elem))
			{
				for (int i = 0; i < size; i++)
				{
					if (arr[i] == elem)
					{
						for (int j = i+1; j < size-1; j++)
						{
							arr[i] = arr[j];
							i++;
						}
						arr[size - 1] = {};
						break;
					}
				}
			}
			else
			{
				cerr << elem << " does not exist \n";
			}

		}
		else
		{
			cerr << "Empty \n";
		}
	}
	bool isEmpty()
	{
		if (size == 0)
			return true;
		return false;
	}
	bool isFull()
	{
		if (size == capacity)
		{
			return true;
		}
		return false;
	}
	bool find(Type elem)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == elem)
				return true;
		}
		return false;
	}
	void display()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " , ";
		}
		cout << endl;
	}
	/*
	int commonElements(Type *array1, Set &obj2)
	{
		int count = 0;
		for (int i = 0; i <array1.size; i++)
		{
			for (int j = 0; j < obj2.size; j++)
			{
				if (obj1.arr[i] == obj2.arr[j])
				{
					count++;
				}

			}
		}
		return count;
	}
	*/
	void compute_union(const Set &obj)
	{
		int sizeOfs = this->size+obj.size;
		Type* s = new Type[sizeOfs];
		s = new Type[sizeOfs];
		/*
		if (this->isEmpty() && obj.isEmpty())
		{
			cerr < "Empty set \n";
		}
		else 
		*/
		/*
		if (!this->isEmpty() && !obj.isEmpty())
		{
		*/
			bool duplicate = false;
			int sizeOfUnionArray = 0;
			for (int i = 0; i < this->size; i++)
			{
				if (sizeOfs < this->size-1)
				{
					s[i] = this->arr[i];
					sizeOfUnionArray++;
				}
				/*
				else
				{
					//regrow
					
					Type* temp = new Type[sizeOfs * 2];
					for (int i = 0; i < sizeOfs; i++)
					{
						temp[i] = s[i];
					}
					delete s;
					s = temp;
					sizeOfs *= 2;
					s[sizeOfUnionArray] = this->arr[sizeOfUnionArray];
					sizeOfUnionArray++;
					
				}
			    */
			}
			for (int i = 0; i < sizeOfUnionArray; i++)
			{
				if (s[i] != obj.arr[i])
				{
					s[sizeOfUnionArray] = obj.arr[i];
					sizeOfUnionArray++;
				}
			}
		//}
			/*
		else if (this->isEmpty())
		{
			this->display();
		}
		else if (obj.isEmpty())
		{
			obj.display();
		}
		*/
		for (int i = 0; i < sizeOfs; i++)
		{
			cout << s[i] << ",";
		}
	}
	void compute_intersection(const Set &obj)
	{
		
	}
	void compute_difference(const Set &obj);
	
};

int main()
{
	Set<int> s1;
	s1.add_member(10);
	s1.display();  
	s1.add_member(20);
	s1.add_member(30);
	s1.add_member(40);
	s1.add_member(50);
	s1.add_member(160);
	s1.display();

	Set<int> s2;
	s2.add_member(10);
	s2.add_member(25);
	s2.add_member(36);
	s2.add_member(47);
	s2.add_member(50);
	s2.display();

	s1.compute_union(s2);
	

	system("pause");
	return 0;
}