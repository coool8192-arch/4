#include <iostream>
using namespace std;

template<typename T>
class Graph
{
	int size;
	int count;
	int capacity;
	T* vertex;
	int** list;

	struct Node
	{
		T data;
		Node* next;
	};

public:
	Graph()
	{
		size = 0;
		count = 0;
		capacity = 0;

		vertex = nullptr;
		list = nullptr;
	}

	Node(T data, Node* link = nullptr)
	{

	}
};

int main()
{

return 0;
}

