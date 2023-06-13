/*
Source code by waqar asghar L1S21BSSE0119
DSA 
by Sir Zeeshan Khan
*/
#include <iostream>
#include <string>
using namespace std;

class Node
{
private:
	int key;
	string value;
	Node* right;
	Node* left;
public:
	Node()
	{
		key = 0;
		value = nullptr;
		left = right = NULL;
	}
	Node(int key,string value)
	{
		this->key = key;
		this->value = value;
		left = right = NULL;
	}
	void setKey(int key)
	{
		this->key = key;
	}
	void setRight(Node *right)
	{
		this->right = right;
	}
	void setLeft(Node* left)
	{
		this->left = left;
	}
	int getKey()
	{
		return key;
	}
	Node* getRight()
	{
		return right;
	}
	Node* getLeft()
	{
		return left;
	}
	void setValue(string value)
	{
		this->value = value;
	}
	string getValue()
	{
		return value;
	}
};


class symbolTable
{
private:
	Node* root;
public:
	symbolTable()
	{
		root = NULL;
	}
	void insert(int key,string value)
	{
		Node* N = new Node(key,value);

		if (root == NULL)
		{
			root = N;
		}
		else
		{
			Node *temp = root;
			while (true)
			{
				if (temp->getKey() < key)
				{
					if (temp->getRight() == NULL)
					{
						temp->setRight(N);
						break;
					}
					else
					{
						temp = temp->getRight();
					}
				}
				else if (temp->getKey() > key)
				{
					if (temp->getLeft() == NULL)
					{
						temp->setLeft(N);

						break;
					}
					else
					{
						temp = temp->getLeft();
					}
				}
				else
				{
					temp = N;
				}
			}
		}
	}
	void display(int select)
	{
		if (root == NULL)
		{
			cout << "Empty tree \n";
		}
		else
		{
			if (select == 1)
			{
				inorder(root);
			}
			else if (select == 2)
			{
				preOrder(root);
			}
			else if (select == 3)
			{
				postOrder(root);
			}

		}
	}
	void inorder(Node *temp)
	{
		if (temp == NULL)
			return;
		inorder(temp->getLeft());
		cout << temp->getKey() << " : " << temp->getValue() << endl;
		inorder(temp->getRight());
	}
	void preOrder(Node *temp)
	{
		if (temp == NULL)
			return;
		cout << temp->getKey() << " : " << temp->getValue() << endl;
		preOrder(temp->getLeft());
		preOrder(temp->getRight());
	}
	void postOrder(Node *temp)
	{
		if (temp == NULL)
			return;
		postOrder(temp->getLeft());
		postOrder(temp->getRight());
		cout << temp->getKey() << " : " << temp->getValue() <<endl;
	}
	Node* search(int key)
	{
		if (root == NULL)
		{
			return root;
		}
		else
		{
			Node* temp = root;
			while (temp != NULL)
			{
				if (temp->getKey() == key)
				{
					return temp;
				}
				else if (temp->getKey() > key)
				{
					temp = temp->getLeft();
				}
				else if (temp->getKey() < key)
				{
					temp = temp->getRight();
				}

			}
			return temp;

		}

	}
	Node* findMin(Node* temp)
	{
		if (temp == NULL)
		{
			return temp;
		}
		else
		{
			while (temp->getLeft() != NULL)
			{
				temp = temp->getLeft();
			}

			return temp;
		}
	}
	Node* findMax(Node* temp)
	{
		if (temp == NULL)
		{
			return temp;
		}
		else
		{
			while (temp->getRight() != NULL)
			{
				temp = temp->getRight();
			}

			return temp;
		}
	}
	Node* getRoot()
	{
		return root;
	}
	void deleteNode(int key, Node* root)
	{
		if (root == NULL)
		{
			cout << "Empty Tree \n";
		}
		else
		{
			if (root->getRight() == NULL && root->getLeft() == NULL && root->getKey() == key)
			{
				delete root;
				root = NULL;
			}
			else
			{
				Node* prev = NULL;
				Node* temp = root;
				bool flag;
				while (temp != NULL)
				{
					if (temp->getKey() > key)
					{
						prev = temp;
						temp = temp->getLeft();
						flag = false;
					}
					else if (temp->getKey()<key)
					{
						prev = temp;
						temp = temp->getRight();
						flag = true;
					}
					else
					{
						if (temp->getLeft() == NULL && temp->getRight() == NULL)
						{
							if (flag)
							{
								delete temp;
								temp = NULL;
								prev->setRight(NULL);
							}
							else
							{
								delete temp;
								temp = NULL;
								prev->setLeft(NULL);
							}
						}
						else if (temp->getLeft() != NULL && temp->getRight() != NULL)
						{
							Node* min = findMin(temp->getRight());
							temp->setKey(min->getKey());
							if (temp->getRight()->getLeft() == NULL && temp->getRight()->getLeft() == NULL)
							{
								delete temp->getRight();
								temp->setRight(NULL);
								break;
							}
							deleteNode(min->getKey(), temp->getRight());
						}
						else
						{
							if (flag)
							{
								if (temp->getRight() != NULL)
								{
									prev->setRight(temp->getRight());
									delete temp;
									temp = NULL;
								}
								else
								{
									prev->setRight(temp->getLeft());
									delete temp;
									temp = NULL;
								}

							}
							else
							{
								if (temp->getRight() != NULL)
								{
									prev->setLeft(temp->getRight());
									delete temp;
									temp = NULL;
								}
								else
								{
									prev->setLeft(temp->getLeft());
									delete temp;
									temp = NULL;
								}
							}
						}
					}
				}
			}
		}
	}

};

int main()
{
	symbolTable t1;
	t1.insert(10, "The number is 10");
	t1.insert(20, "The number is 20");
	t1.insert(30, "The number is 30");
	t1.insert(40, "The number is 40");
	t1.insert(50, "The number is 50");
	t1.insert(60, "The number is 60");
	t1.insert(70, "The number is 70");
	t1.insert(80, "The number is 80");
	t1.insert(90, "The number is 90");
	t1.deleteNode(30, t1.getRoot());
	t1.deleteNode(80, t1.getRoot());
	t1.deleteNode(50, t1.getRoot());


	t1.display(1);
	cout << endl;




	
	Node* min =  t1.findMin(t1.getRoot()) ;
	if (min == NULL)
	{
	cout << "Empty tree \n";
	}
	else
	{
	cout <<"Minimum : " <<min->getKey() <<" : " <<min->getValue() << endl;
	}

	
	Node* max = t1.findMax(t1.getRoot());
	if (max == NULL)
	{
	cout << "Empty tree \n";
	}
	else
	{
	cout << "Maximum : " << max->getKey() <<" : " <<max->getValue() << endl;
	}
	
	int num = 1;
	Node* sear = t1.search(num);
	cout << "Searching a node with value : " << num <<endl;
	if (sear != NULL)
	{
		cout << sear->getKey() << "found successfully \n" << endl;
	}
	else
	{
	cout << "Not found \n";
	}
	


	system("pause");
	return 0;
}