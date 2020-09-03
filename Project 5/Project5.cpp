#include <iostream>
#include <queue> 

/*
Project 5
Andrew Skalicky
May 1, 2017
*/

using namespace std;

/*
Project 5
Andrew Skalicky
May 1, 2017

This class is the bit matrix class that holds matrix of parent and node relations.
*/
class BitMatrixGraph
{
protected:
	//local variable that is our matrix for relations
	unsigned char** bitAdjacencyMatrix;
	//number of nodes in the graph
	int n;
	//size of the graph
	int size;
	
public:
	//default constructor
	BitMatrixGraph()
	{
		bitAdjacencyMatrix = new unsigned char* ();
		n = 0;
	}

	//constructor taking in number of nodes, initializing n
	BitMatrixGraph(int numNodes)
	{
		//set number of nodes
		n = numNodes;

		//formating size for matrix
		if (n % 8 == 0)
		{
			size = n / 8;
		}
		else
		{
			size = (int) ceil(n / 8) + 1;
		}

		//initializing matrix
		bitAdjacencyMatrix = new unsigned char*[n];

		//initializing matrix components
		for (int i = 0; i < n; ++i)
		{
			bitAdjacencyMatrix[i] = new unsigned char[size];
		}

		//initializing individual matrix components
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				bitAdjacencyMatrix[i][j] = 0x00 << 8;
			}
		}
	}

	//constructor setting new item to given item
	BitMatrixGraph(BitMatrixGraph& otherGraph)
	{
		n = otherGraph.numNodes();

		size = otherGraph.getSize();

		bitAdjacencyMatrix = otherGraph.bitAdjacencyMatrix;
	}

	//destructor
	~BitMatrixGraph()
	{
		n = NULL;
		size = NULL;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				bitAdjacencyMatrix[i][j] = NULL;
			}
			
			bitAdjacencyMatrix[i] = NULL;
		}

		delete bitAdjacencyMatrix;
	}

	//establishes == operator for class
	bool operator == (BitMatrixGraph& part)
	{
		for (int i = 0; i < n; ++i)
		{
			if (bitAdjacencyMatrix[i] != part.bitAdjacencyMatrix[i])
			{
				return false;
			}
		}

		return true;
	}

	//establishes the '<<' operator for Partition objects
	friend ostream& operator << (ostream& s, BitMatrixGraph& graph)
	{
		graph.display();
		return s;
	}

	//returns number of nodes
	int numNodes()
	{
		return n;
	}

	//returns size of matrix
	int getSize()
	{
		return size;
	}

	//displays class item
	void display()
	{
		for (int i = 0; i < n; ++i)
		{
			cout << i + 1 << ". ";

			if (i + 1 < 10)
			{
				cout << " ";
			}

			for (int j = 0; j < size; ++j)
			{
				printBits(bitAdjacencyMatrix[i][j]);
			}
			cout << endl;
		}

		//triggers Breadth First Search
		cout << "\nBreadth First Search Parent Array: <Parent, Node>" << endl;
		BreadthFirstSearch(bitAdjacencyMatrix, 0);

		cout << endl;

		//triggers Depth First Search
		cout << "\nDepth First Search Parent Array: <Parent, Node>" << endl;
		DepthFirstSearch(bitAdjacencyMatrix, 0);
		
	}

	//adds an edge between nodes
	void addEdge(int u, int v)
	{
		bitAdjacencyMatrix[u][(int) ceil(v/8)]  |= 1 << (7 - (v % 8));
		bitAdjacencyMatrix[v][(int) ceil(u/8)] |= 1 << (7 - (u % 8));
	}

	//checks if there is an edge between nodes
	bool isAnEdge(int u, int v)
	{
		if (bitAdjacencyMatrix[u][(int) ceil(v/8)] & 1 << (7 - (v % 8))) 
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	//outputs bits from each matrix location
	void printBits(unsigned char s)
	{
		//print the bit pattern
		for (int i = 0; i < 8; i++)
		{
			if (s & (1 << (7 - i)))
			{
				cout << 1;
			}
			else
			{
				cout << 0;
			}
			cout << " ";
		}
	}
	
	//helper method for Depth First Search, recursive
	void DFS(bool* visited, int* parent, int p, unsigned char** graph)
	{

		visited[p] = true;

		for (int i = 0; i < n; ++i)
		{
			if (visited[i] == false)
			{
				if (this->isAnEdge(p, i))
				{
					parent[i] = p;
					visited[i] = true;
					cout << "<" << i << ", " << p << "> ";
					DFS(visited, parent, i, graph);
				}
			}
		}
	}

	//traverses the matrix in Depth First Search form
	void DepthFirstSearch(unsigned char** graph, int p)
	{
		bool* visited = new bool[n]();
		queue<int>* DFS = new queue<int>();
		int* parent = new int[n]();
		int* traversal = new int[n]();
		int index = 0;

		for (int i = 0; i < n; ++i)
		{
			parent[i] = -1;
			visited[i] = 0;
			traversal[i] = -1;
		}

		this->DFS(visited, parent, p, graph);
	}

	//traverses the matrix in Breadth First Search form
	void BreadthFirstSearch(unsigned char** graph, int p)
	{
		int* parent = new int[n]();
		int* traversal = new int[n]();
		int index = 0;
		int v;

		queue<int>* BFS = new queue<int>();

		bool* visited = new bool[n]();

		for (int i = 0; i < n; ++i)
		{
			visited[i] = 0;
			parent[i] = -1;
			traversal[i] = -1;
		}

		BFS->push(p);
		visited[p] = true;

		while (!BFS->empty())
		{
			v = BFS->front();
			traversal[index] = v;
			++index;
			BFS->pop();

			for (int i = 0; i < n; ++i)
			{
				if (visited[i] == false)
				{
					if (this->isAnEdge(v, i))
					{
						parent[i] = v;
						visited[i] = true;
						BFS->push(i);
					}
				}
			}
		}

		for (int i = 0; i < n; ++i)
		{
			if (i % 10 == 0 && i != 0)
			{
				cout << endl;
			}
			cout << "<" << i << ", " << parent[i] << "> ";
		}

		cout << "\n\nBreadth First Node Traversal:" << endl;

		for (int i = 0; i < index; ++i)
		{
			if (i != index - 1)
			{
				cout << traversal[i] << " > ";
			}

			else
			{
				cout << traversal[i];
			}
		}
	}
};

/*

Project 5
Andrew Skalicky
May 1, 2017

Main class that performs given functions.
*/
void main()
{
	int n, u, v;
	BitMatrixGraph* graph = new BitMatrixGraph();

	cin >> n;

	graph = new BitMatrixGraph(n);

	while (!cin.eof())
	{
		cin >> u >> v;
		cout << u << " " << v << endl;

		graph->addEdge(u, v);
	}

	cout << "\n" << *graph << endl;
};