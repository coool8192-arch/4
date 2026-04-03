#include <iostream>
using namespace std;

template<typename T>
class Graph
{
	struct Node
	{
		T data;
		Node* next;

		Node(T data, Node* link = nullptr)
		{
			this->data = data;

			next = link;
		}
	};

	int size;
	int count;
	int capacity;
	T* vertex;
	Node** list;

public:
	Graph()
	{
		size = 0;
		count = 0;
		capacity = 0;

		vertex = nullptr;
		list = nullptr;
	}

	void resize(int newSize)
	{
		capacity = newSize;

		T* temporary = new T[capacity];

		for (int i = 0; i < capacity; i++)
		{
			temporary[i] = NULL;
		}

		for (int i = 0; i < size; i++)
		{
			temporary[i] = vertex[i];
		}

		delete[] vertex;

		vertex = temporary;
	}

	void push(T data)
	{
		if (capacity <= 0)
		{
			resize(1);
		}
		else if (size >= capacity)
		{
			resize(capacity * 2);
		}

		vertex[size++] = data;
	}

	void edge(int i, int j)
	{
		if (size <= 0)
		{
			cout << "adjacency list is empty" << endl;
		}
		else if (i >= size || j >= size)
		{
			cout << "index out of range" << endl;
		}
		else
		{
			if (list == nullptr)
			{
				list = new Node * [size];

				for (int i = 0; i < size; i++)
				{
					list[i] = nullptr;
				}

				count = size;
			}
			else if (count < size)
			{
				resize();
			}

			list[i] = new Node(vertex[j], list[i]);
			list[j] = new Node(vertex[i], list[j]);
		}
	}

	void resize()
	{
		Node** newList = new Node * [size];

		for (int i = 0; i < size; i++)
		{
			newList[i] = nullptr;
		}

		for (int i = 0; i < count; i++)
		{
			newList[i] = list[i];
		}

		delete[] list;

		list = newList;

		count = size;
	}

	void render()
};

int main()
{
	Graph<char> graph;

	graph.push('A');
	graph.push('B');
	graph.push('C');
	graph.push('D');

	graph.edge(1, 2);
	graph.edge(1, 3);

return 0;
}

