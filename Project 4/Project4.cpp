#include <iostream>
#include <stack>
#include <cstdlib>
#include <vector>
#include <stack>

using namespace std;
/*
	Andrew Skalicky
	Project 4
	April 17, 2017
	V1

	This class holds the methods and constructors for Nodes of the BinaryTree
*/
template<class DataType>
class ArrayBTNode
{
public:
	//arbitrary DT to be placed in an array
	DataType* _info;
	//index of left ArrayBTNode
	int _left;
	//index of right ArrayBTNode
	int _right;

	//default constructor
	ArrayBTNode()
	{
		_left = -1;
		_right = -1;
		_info = new DataType();
	}

	//constructor taking in a root value
	ArrayBTNode(int root)
	{
		_left = -1;
		_right = -1;
		_info = new DataType(root);
	}

	//constructor taking in left and right values, as well as a DT
	ArrayBTNode(int left, int right, DataType& bt)
	{
		_left = left;
		_right = right;
		_info = bt;
	}

	//destructor for class type
	~ArrayBTNode()
	{
		_left = NULL;
		_right = NULL;
		_info = NULL;

		delete _info;
	}

	//returns the info class variable
	DataType* info()
	{
		return _info;
	}

	//returns the left index position
	int getLeft()
	{
		return _left;
	}

	//returns the right index position
	int getRight()
	{
		return _right;
	}

	//sets the left index position
	void setLeft(DataType left)
	{
		_left = left;
	}

	//sets the right index position
	void setRight(DataType right)
	{
		_right = right;
	}

	//finds the height of a binary tree
	int Height()
	{
		int height = 0;
		int leftheight;

		if (!isEmpty())
		{
			if (_left == NULL)
			{
				leftheight = 0;
			}
			else
			{
				leftheight = _left->Height();
			}

			if (_right == NULL)
			{
				height = 1 + leftheight;
			}
			else
			{
				height = 1 + max(leftHeight, _right->Height());
			}
		}

		return height;
	}

	//finds the size of a binary tree
	int Size()
	{
		int size = 0;
		int leftsize;

		if (!isEmpty())
		{
			leftsize = 0;
		}
		else
		{
			leftsize = _left->Size();
		}

		if (_right == NULL)
		{
			size = 1 + leftsize;
		}
		else
		{
			size = 1 + leftsize + _right->Size();
		}

		return size;
	}

	//gives parameters for the ">" operator
	bool operator > (DataType* o)
	{
		return (_info > o);
	}

	//gives parameters for the "<" operator
	bool operator < (DataType* o)
	{
		return (_info < o);
	}

	//gives parameters for the "==" operator
	bool operator == (DataType* o)
	{
		return (_info == o);
	}

	//gives parameters for the ">" operator
	bool operator != (DataType* o)
	{
		return (_info != o);
	}

	//gives parameters for the ">=" operator
	bool operator >= (DataType* o)
	{
		return (_info >= o);
	}

	//gives parameters for the ">=" operator
	bool operator <= (DataType* o)
	{
		return (_info <= o);
	}

	//gives parameters for the "<<" operator
	friend ostream& operator << (ostream& os, ArrayBTNode<DataType> ar)
	{
		ar.display(os);
		return os;
	}

	//display method for class items
	void display(ostream& os)
	{
		os << " Value: " << *info() << " Left Tree Location" << getLeft() << " Right Tree Location:" << getRight() << endl;
	}

};

/*
	Andrew Skalicky
	Project 4
	April 17, 2017
	V1

	This class is the basis for BinaryTree Arrays.
*/
template<class DataType>
class ArrayBT
{
public:
	//vector for storing ArrayBTNodes
	vector<ArrayBTNode<DataType>*>* myBinaryTree;

	//local variables that track locations of the root,
	//size of the array, number of nodes, 
	//and the display type
	int _root, _size, _noNodes, dis;

	//stack that keeps track of which 
	//locations have not been used in the vector
	stack<int>* freeLocations;

	//default class constructor
	ArrayBT()
	{
		_root = -1;
		_size = -1;
		_noNodes = 0;
		freeLocations = new stack<int>;
	}

	//class constructor that takes in a specific size
	ArrayBT(int size)
	{
		_size = size;

		ArrayBTNode* temp = new ArrayBTNode<DataType>[_size];
		delete myBinaryTree;
		myBinaryTree = temp;

		for (int i = size - 1; i >= 0; --i)
		{
			freeLocations->push(i);
			myBinaryTree[i] = ArrayBTNode<DataType>();
		}
	}

	//class destructor
	~ArrayBT()
	{
		while(freeLocations->top() != NULL)
		{
			freeLocations->pop();
		}

		_root = NULL;
		_size = NULL;
		_noNodes = NULL;
	}

	//returns a specific node in the array
	ArrayBTNode<DataType>* getNode(int pos)
	{
		return myBinaryTree->at(pos);
	}

	//returns the index of the root of the array
	DataType getRoot()
	{
		return _root;
	}

	//returns the number of nodes in the array
	int getNumNodes()
	{
		return _noNodes;
	}

	//tells if the BST is empty or not
	bool isEmpty()
	{
		return (_root == NULL);
	}

	//returns the root object in the vector
	DataType& rootData()
	{
		if (isEmpty())
		{
			throw BinaryTreeEmptyTree();
		}

		return *myBinaryTree->at(_root);
	}
	
	//returns the index of a particular value
	int indexOf(int data)
	{
		int loc = _root;
		int a, b, c;

		//recursave locating of value
		while (loc != -1)
		{
			a = *(myBinaryTree->at(loc)->info());
			b = myBinaryTree->at(loc)->getRight();
			c = myBinaryTree->at(loc)->getLeft();

			//object found
			if (a == data)
			{
				return loc;
			}
			//object to right
			else if (a < data)
			{
				//look to the right
				loc = b;

			}
			//object to left
			else if (a > data)
			{
				//look to the left
				loc = c;
			}

		}

		//object is never found
		return -1;
	}

	//display method that shows raw data of ArrayBT class objects
	void display(ostream& os)
	{

		for (int i = 0; i < binaryTree->getNumNodes(); ++i)
		{
			cout << "Position: " << i << binaryTree->getNode(i) << endl;
		}
	}


	//gives parameters for the "<<" operator
	friend ostream& operator << (ostream& os, DataType& s)
	{
		s->display(os);
		return os;
	}
};

/*
	Andrew Skalicky
	Project 4
	April 17, 2017
	V1
	
	This class provides is an extension of ArrayBT
	and allows for navigation of the BinaryTree.
*/
template<class DataType>
class ArrayBST : virtual public ArrayBT<DataType>
{
public:
	//default class object constructor
	ArrayBST()
	{
		_root = -1;
		_size = -1;
		_noNodes = 0;
		dis = 0;
		freeLocations = new stack<int>;
	}

	//constructor that takes in a specific size
	ArrayBST(int size)
	{
		_root = -1;
		_noNodes = 0;
		_size = size;
		dis = 0;

		vector<ArrayBTNode<DataType>*>* temp = new vector<ArrayBTNode<DataType>*>[_size];
		delete myBinaryTree;
		myBinaryTree = temp;

		for (int i = size - 1; i >= 0; --i)
		{
			myBinaryTree->push_back(new ArrayBTNode<DataType>());
			freeLocations->push(i);
		}
	}

	//inserts a DataType object into the vector
	void insert(DataType input)
	{
		//resizes the vector if all spaces are filled
		if (_noNodes >= _size)
		{
			resize(50);
		}

		//sets x to next free location
		int x = freeLocations->top();

		//sets the node at the position x in the vector to
		//a default node constructed with given value
		myBinaryTree->at(x) = new ArrayBTNode<DataType>(input);

		//sets a hold value for position that starts at the root
		int y = _root;

		//checks value of the new node
		int d = *(myBinaryTree->at(x)->info());

		//needed variables for further process
		int a, b, c;

		//if root is not -1, there is already a root
		if (_root != -1)
		{	
			//while loop that will run indefinately, without a break
			while (_root != -1)
			{
				//setting variables to the value of the current node
				//being focused on
				a = *(myBinaryTree->at(y)->info());
				//sets b and c to left and right index from current node
				b = myBinaryTree->at(y)->getRight();
				c = myBinaryTree->at(y)->getLeft();

				//if conditions are met, location for new node has been found,
				//which is on the right of another node
				if (a < d && b == -1)
				{
					//remove a freeLocation, as it is now used
					freeLocations->pop();
					//set focused node's relation to new node
					myBinaryTree->at(y)->setRight(x);
					//inc number of nodes
					_noNodes++;
					break;
				}
				//there is still a node on the right, so we keep going
				else if (a < d && b != -1)
				{
					//move to the right
					y = b;
				}
				//if conditions are met, location for new node has been found,
				//which is on the left of another node
				else if (a > d && c == -1)
				{
					//remove a freeLocation, as it is now used
					freeLocations->pop();
					//set focused node's relation to new node
					myBinaryTree->at(y)->setLeft(x);
					//inc number of nodes
					_noNodes++;
					break;
				}
				//there is still a node on the left, continue
				else if (a > d && c != -1)
				{
					//move left
					y = c;
				}
				//if no other conditions are met, node is already in array
				else
				{
					break;
				}
			}
		}
		//if root = -1, there is no initial root, so set new item location as root
		else
		{
			_root = x;
			freeLocations->pop();
			_noNodes++;
		}
	}

	//this is by far the worst class i've ever tried to implement
	//i am a quitter
	void remove(int data)
	{
		int loc = _root;
		int prevLoc2 = loc;
		int a, b, c, prevLoc;
		bool found = false;

		while (found == false)
		{
			a = *(myBinaryTree->at(loc)->info());
			b = myBinaryTree->at(loc)->getLeft();
			c = myBinaryTree->at(loc)->getRight();

			if (a < data)
			{
				if (*(myBinaryTree->at(c)->info()) == data)
				{
					//fix
					while (loc != -1)
					{
						prevLoc = loc;
						loc = myBinaryTree->at(loc)->getRight();

						if (loc != -1)
						{
							if (myBinaryTree->at(loc)->getLeft() == -1)
							{
								myBinaryTree->at(prevLoc2)->setRight(myBinaryTree->at(c)->getRight());
								myBinaryTree->at(c)->setLeft(-1);
								myBinaryTree->at(c)->setRight(-1);
								freeLocations->push(c);
								_noNodes--;
								found = true;
							}
							else
							{
								loc = myBinaryTree->at(loc)->getLeft();

								if (loc == -1)
								{
									loc = myBinaryTree->at(loc)->getRight();
								}
							}
						}
						else
						{
							loc = myBinaryTree->at(loc)->getLeft();
						}

						prevLoc2 = prevLoc;
					}
				}
				else
				{
					loc = c;
				}
			}
			else if (a > data)
			{
				if (*(myBinaryTree->at(b)->info()) == data)
				{
					//fix
					while (loc != -1)
					{
						prevLoc = loc;
						loc = myBinaryTree->at(b)->getRight();

						if (loc != -1)
						{
							if (myBinaryTree->at(loc)->getLeft() == -1)
							{
								myBinaryTree->at(prevLoc)->setRight(myBinaryTree->at(loc)->getRight());
								myBinaryTree->at(b)->setLeft(-1);
								myBinaryTree->at(b)->setRight(-1);
								freeLocations->push(b);
								found = true;
							}
							else
							{
								loc = myBinaryTree->at(loc)->getLeft();

								if (loc == -1)
								{
									loc = myBinaryTree->at(loc)->getRight();
								}
							}
						}

						prevLoc2 = prevLoc;
					}
				}
				else
				{
					loc = b;
				}
			}

		}

	}

	//set's the display medium
	void setDis(int i)
	{
		dis = i;
	}

	//resizes the vector to accomidate extra nodes
	void resize(int x)
	{
		vector<ArrayBTNode<DataType>*>* temp = new vector<ArrayBTNode<DataType>*>[_size + x];

		for (int i = 0; i < _size + x; ++i)
		{
			temp->push_back(new ArrayBTNode<DataType>());

			if (i >= _size)
			{
				freeLocations->push(i);
			}
		}

		for (int i = 0; i < _size; ++i)
		{
			temp->at(i) = myBinaryTree->at(i);
		}

		myBinaryTree = temp;
		_size += x;
	}

	//produces a vector composed of the inorder <left><root><right> node values
	//through recursion
	vector<DataType> inorder(vector<DataType> order, int index)
	{
		int temp = index;
		int a = myBinaryTree->at(index)->getLeft();
		int b = myBinaryTree->at(index)->getRight();

		//check all left first
		if (a != -1)
		{
			index = a;
			order = inorder(order, a);
		}

		//if no more left, add to vector
		order.push_back(*(myBinaryTree->at(temp)->info()));

		//check all right
		if (b != -1)
		{
			index = b;
			order = inorder(order, b);
		}

		//return vector for addition or more nodes, or finished vector
		return order;
	}

	//produces a vector composed of the preorder <root><left><right> node values
	//through recursion
	vector<DataType> preorder(vector<DataType> order, int index)
	{
		int temp = index;
		int a = myBinaryTree->at(index)->getLeft();
		int b = myBinaryTree->at(index)->getRight();

		//add root value to vector
		order.push_back(*(myBinaryTree->at(temp)->info()));

		//check all left values
		if (a != -1)
		{
			index = a;
			order = preorder(order, a);
		}

		//check all right values
		if (b != -1)
		{
			index = b;
			order = preorder(order, b);
		}

		//return vector for further adding of values, or finished vector
		return order;
	}

	//while it is unused, produces a vector composed of the postorder <left><right><root>
	//node values through recursion
	vector<DataType> postorder(vector<DataType> order, int index)
	{
		int temp = index;
		int a = myBinaryTree->at(index)->getLeft();
		int b = myBinaryTree->at(index)->getRight();
	
		//check all left values
		if (a != -1)
		{
			index = a;
			order = postorder(order, a);
		}

		//check all right values
		if (b != -1)
		{
			index = b;
			order = postorder(order, b);
		}

		//add root to vector
		order.push_back(*(myBinaryTree->at(temp)->info()));

		//return to add more values to recursive vectors
		return order;
	}

	//complex display method that calls alternate display methods, depending on
	//dis value
	void display(ostream& os)
	{
		if (dis == 0)
		{
			displayRaw(os);
		}
		else if (dis == 1)
		{
			displayPre(os);
		}
		else if (dis == -1)
		{
			displayIn(os);
		}
		else
		{
			displayPost(os);
		}
	}

	//method calls inorder to create a vector of inorder node values
	//and then outputs them
	void displayIn(ostream& os)
	{
		//create default vector, which is then made into a vector
		//of inorder node values
		vector<DataType> inorderNum;
		inorderNum = inorder(inorderNum, _root);

		//format of printing
		cout << "Inorder: ";
		for (unsigned int i = 0; i < inorderNum.size(); ++i)
		{
			cout << inorderNum[i] << " ";
		}
		cout << endl;
	}

	//method calls preorder to create a vector of preorder node values
	//and then outputs them
	void displayPre(ostream& os)
	{
		//create default vector, which is then made into a vector
		//of preorder node values
		vector<DataType> preorderNum;
		preorderNum = preorder(preorderNum, _root);

		//format of printing
		cout << "Preorder: ";
		for (unsigned int i = 0; i < preorderNum.size(); ++i)
		{
			cout << preorderNum[i] << " ";
		}
		cout << endl;
	} 

	//method calls preorder to create a vector of postorder node values
	//and then outputs them
	void displayPost(ostream& os)
	{
		//create default vector, which is then made into a vector
		//of postorder node values
		vector<DataType> postorderNum;
		postorderNum = postorder(postorderNum, _root);

		//format of printing
		cout << "Postorder: ";
		for (unsigned int i = 0; i < postorderNum.size(); ++i)
		{
			cout << postorderNum[i] << " ";
		}
		cout << endl;
	}

	//displays the raw value of the vector
	//with node positions and relations with indexes
	void displayRaw(ostream& os)
	{
		//default stack to temporarily hold values
		stack<int>* temp = new stack<int>;

		//prints information for all nodes in the vector
		for (unsigned int i = 0; i < myBinaryTree->size() - (myBinaryTree->size() - _noNodes); ++i)
		{
			cout << "Position: " << i << *(myBinaryTree->at(i)) << endl;
		}

		cout << "Locations Remaining: ";
		//arbitrary size value of the stack
		unsigned int size = freeLocations->size();

		//prints out available spaces, but also moving them to
		//another stack, so that each can be read
		for (unsigned int i = 0; i < size; ++i)
		{
			temp->push(freeLocations->top());
			cout << freeLocations->top() << " ";
			freeLocations->pop();
		}

		//moves values back to original stack
		for (unsigned int i = 0; i < size; ++i)
		{
			freeLocations->push(temp->top());
			temp->pop();
		}
		cout << endl;
	}

	//gives parameters for the "<<" operator
	friend ostream& operator << (ostream& os, ArrayBST<DataType>& s)
	{
		s.display(os);
		return os;
	}
};

/*
	Andrew Skalicky
	Project 4
	April 17, 2017
	V1

	This class is the main class which creates and calls all operations in the project.
*/
void main()
{
	//variables for storing input data
	int size, data;
	char operation;
	//tracker for number of items
	ArrayBST<int>* binaryTree;

	//pull in initial size and output value
	cin >> size;
	cout << size << endl;
	
	//create a ArrayBST of input size
	binaryTree = new ArrayBST<int>(size);

	//iterate throughout file
	while (!cin.eof())
	{
		//take in operation
		cin >> operation;
		cout << operation;

		//if the operation is O or  A, there is no need
		//to take in data
		if (operation != 'O' && operation != 'A')
		{
			//take in data
			cin >> data;
			cout << " " << data << endl;
		}
		else
		{
			cout << " " << endl;
		}

		//depending on the operation, perform specific actions
		switch (operation)
		{
			//output using DisplayRaw method
			case 'A':
			{
				binaryTree->setDis(0);
				cout << *binaryTree << "\n" << endl;
				break;
			}
			//search for a node with an info value of data
			case 'F':
			{
				int index = binaryTree->indexOf(data);
				if (index == -1)
				{
					cout << data << " Not Found" << endl;
				}
				else
				{
					cout << data << " Found at Location: " << index << endl;
				}
				cout << "\n" << endl;
				break;
			}
			//insert
			case 'I':
			{
				binaryTree->insert(data);
				break;
			}
			//output the tree using ostream operator
			case 'O':
			{
				if (binaryTree->getNumNodes() > 1)
				{
					//inorder
					binaryTree->setDis(-1);
					cout  << *binaryTree << endl;

					//preorder
					binaryTree->setDis(1);
					cout << *binaryTree << endl;
				}
				break;
			}
			/*
			case 'R':
			{
				int index = binaryTree->indexOf(data);

				if(index == -1)
				{
				cout << data << " Not Found in BinaryTree" << endl;
				}
				else
				{
				binaryTree->remove(data);
				cout << data << " Successfully Removed" << endl;
				}

				cout << "\n" << endl;
				break;
			}
			*/
			default:
			{
				cout << "Command not implemented" << endl;
				break;
			}
		}
	}

};