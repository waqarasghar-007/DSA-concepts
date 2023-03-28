#include <iostream>
using namespace std;

template <class T>
class arrayList
{
private:
	int capacity;
	T* arr;
	int size;
	void init()
	{
		for (int i = 0; i < capacity; i++)
		{
			arr[i] = -1;
		}
	}
	void init(int from)
	{
		for (int i = from; i < capacity; i++)
		{
			arr[i] = -1;
		}
	}
public:
	arrayList()
	{
		capacity = 3;
		arr = new T[capacity];
		size = -1;
		init();
	}
	arrayList(int capacity)
	{
		this->capacity = capacity;
		arr = new T[capacity];
		size = -1;
		init();
	}
	void insert(T data)
	{
		if (!isFull())
		{
			if (isEmpty())
			{
				size = 0;
				arr[size] = data;
				size++;
			}
			else
			{
				arr[size] = data;
				size++;
			}
		}
		else
		{
			T* temp;
			temp = new T[capacity * 2];
			for (int i = 0; i < size; i++)
			{
				temp[i] = arr[i];
			}
			delete[]arr;
			arr = temp;
			capacity *= 2;
			init(size);
			insert(data);
		}
	}
	void insertAtStart(T data)
	{
		if (isEmpty())
		{
			size = 0;
			arr[size] = data;
			size++;
		}
		else
		{
			cout << "Start index is occupied \n";
		}
	}
	void insertAtEnd(T data)
	{
		if (!isEmpty())
		{
			arr[size] = data;
			size++;
		}
		else
		{
			insertAtStart(data);
		}
	}
	bool insertAt(int index, T data)
	{
		bool ret = false;
		if (!isFull() && index >= 0 && index < size)
		{
			if (isVacant(index))
			{
				arr[index] = data;
				ret = true;
				return ret;
			}
			else
			{
				cerr << "Index occupied \n";
			}
		}
		else
		{
			cerr << "Full \n";
		}
		return ret;
	}
	bool isVacant(int index)
	{
		if (arr[index] == -1)
			return true;
		return false;
	}
	bool addAll(arrayList& list)
	{
		bool ret = false;
		for (int i = 0; i < list.getSize(); i++)
		{

			this->insert(list.arr[i]);
			ret = true;
		}
		orderAscending();
		return ret;
	}
	bool isFull()
	{
		if (size == capacity)
		{
			return true;
		}
		return false;
	}
	bool isEmpty()
	{
		if (size == -1)
		{
			return true;
		}
		return false;
	}
	int search(T key)
	{
		if (contains(key))
		{
			for (int i = 0; i < size; i++)
			{
				if (arr[i] == key)
				{
					return i;
				}
			}
		}

		return -1;
	}
	bool contains(T key)
	{
		if (!isEmpty())
		{
			for (int i = 0; i < size; i++)
			{
				if (arr[i] == key)
				{
					return true;
				}
			}
		}

		return false;
	}
	bool containsList(arrayList& obj)
	{
		bool ret = false;
		if (!isEmpty())
		{

			for (int i = 0; i < obj.getSize(); i++)
			{
				if (this->contains(obj.arr[i]))
				{
					ret = true;
				}
				else
				{
					ret = false;
					return ret;
				}
			}

		}
		return ret;
	}
	void display()
	{
		if (!isEmpty())
		{
			for (int i = 0; i < size; i++)
			{
				cout << arr[i] << " ";
			}
		}
		else
		{
			cerr << "Empty \n";
		}
		cout << endl;
	}
	void clear()
	{
		capacity = 3;
		arr = new T[capacity];
		size = -1;
	}
	bool Delete(T key)
	{
		int ret = false;
		int index = search(key);
		if (index == -1)
		{
			cout << "Data not found! \n";
			ret = false;
		}
		else
		{
			for (int i = index; i < size - 1; i++)
			{
				arr[i] = arr[i + 1];
			}
			size--;
			ret = true;
		}
		return ret;
	}
	void remove(int index)
	{
		arr[index] = -1;
	}
	void orderAscending()
	{
		for (int i = 0; i < this->getSize(); ++i)
		{
			for (int j = 0; j < (this->getSize() - i) - 1; ++j)
			{
				if (this->arr[j] > this->arr[j + 1])
				{
					T temp;
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;

				}


			}
		}
	}
	void orderItAscending(arrayList& list)
	{

		for (int i = 0; i < list.getSize(); ++i)
		{
			for (int j = 0; j < (list.getSize() - i) - 1; ++j)
			{
				if (list.arr[j] > list.arr[j + 1])
				{
					T temp;
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;

				}


			}
		}
	}
	void orderItDescending(arrayList& list)
	{
		for (int i = 0; i < list.getSize(); ++i)
		{
			for (int j = 0; j < (list.getSize() - i) - 1; ++j)
			{
				if (list.arr[j] < list.arr[j + 1])
				{
					T temp;
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
	bool update(T old, T New)
	{
		bool ret = false;
		int index = search(old);
		if (index != -1)
		{
			arr[index] = New;
			ret = true;
		}
		else
		{
			cout << old << " not found \n";
			ret = false;
		}
		return ret;
	}
	arrayList clone()
	{
		arrayList obj;
		for (int i = 0; i < size; i++)
		{
			obj.insert(arr[i]);
		}
		return obj;
	}
	int get(int index)
	{
		if (!isEmpty() && index < size)
		{
			return arr[index];
		}
		return -1;
	}
	int getSize()
	{
		return size;
	}
	int getCapacity()
	{
		return capacity;
	}
	bool removeAll(arrayList& obj)
	{
		bool ret = false;
		if (containsList(obj))
		{
			for (int i = 0; i < obj.getSize(); i++)
			{
				Delete(obj.arr[i]);
			}
			ret = true;
			return ret;
		}
		else
		{
			cerr << "List to be deleted does not exist in the actual list \n";
		}
		return ret;
	}
	arrayList subList(int startIndex, int endIndex)
	{
		arrayList sublist;
		if (!isEmpty() && (startIndex >= 0 && startIndex < size - 1) && endIndex < size)
		{
			for (int i = startIndex; i <= endIndex; i++)
			{

				sublist.insert(this->arr[i]);
			}
		}
		else if (!(startIndex >= 0 && startIndex < size - 1))
		{
			cerr << "Invalid start Index \n";
		}
		else if (endIndex >= size || endIndex <= startIndex)
		{
			cerr << "Invalid end index \n";
		}
		return sublist;
	}
	void trimToSize()
	{
		capacity = size;
	}
	void removeRange(int startIndex, int endIndex)
	{
		if (!isEmpty() && (startIndex >= 0 && startIndex < size - 1) && endIndex < size)
		{
			for (int i = startIndex; i <= endIndex; i++)
			{
				remove(i);
			}
		}
		else if (!(startIndex >= 0 && startIndex < size - 1))
		{
			cerr << "Invalid start Index \n";
		}
		else
		{
			cerr << "Invalid end index \n";
		}
		trim();
		orderAscending();


	}
	void trim()
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == -1)
			{
				for (int j = i + 1; j < size; j++)
				{
					arr[i] = arr[j];
				}
				size--;
			}
		}

	}

}; 
