#include <iostream>
using namespace std;

template<typename T>
class Graph
{
	int size;
	int count;
	int capacity;
	T* vertex;
	int** matrix;

public:
	Graph()
	{
		size = 0;
		count = 0;
		capacity = 0;

		vertex = nullptr;
		matrix = nullptr;
	}

	void resize(int newsize)
	{
		capacity = newsize;

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
			cout << "adjacency matrix is empty" << endl;
		}
		else if (i >= size || j >= size)
		{
			cout << "index out of range" << endl;
		}
		else
		{
			if (matrix == nullptr)
			{
				count = size;

				matrix = new int* [size];

				for (int k = 0; k < size; k++)
				{
					matrix[k] = new int[size];

					for (int l = 0; l < size; l++)
					{
						matrix[k][l] = 0;
					}
				}
			}
			else if (count < size)
			{
				resize();
			}

			matrix[i][j] = 1;
			matrix[j][i] = 1;
		}
	}

	void resize()
	{
		int** newMatrix = new int* [size];

		for (int i = 0; i < size; i++)
		{
			newMatrix[i] = new int[size] {0};
		}

		for (int i = 0; i < count; i++)
		{
			for (int j = 0; j < count; j++)
			{
				newMatrix[i][j] = matrix[i][j];
			}
		}

		for (int i = 0; i < count; i++)
		{
			delete[] matrix[i];
		}

		delete[] matrix;

		matrix = newMatrix;

		count = size;
	}

	void render()
	{
		cout << " ";

		for (int i = 0; i < count; i++)
		{
			cout << " " << vertex[i];
		}

		for (int i = 0; i < count; i++)
		{
			cout << endl << vertex[i];

			for (int j = 0; j < count; j++)
			{
				cout << " " << matrix[i][j];
			}
		}
	}

	~Graph()
	{
		for (int i = 0; i < count; i++)
		{
			delete[] matrix[i];
		}

		delete[] matrix;

		delete[] vertex;
	}
};

int main()
{
	//   A B C D
	// A 0 0 0 1
	// B 0 0 1 0
	// C 0 1 0 1
	// D 1 0 0 0

	Graph<char> graph;

	graph.push('A');
	graph.push('B');
	graph.push('C');

	graph.edge(0, 1);
	graph.edge(3, 4);

	graph.push('D');

	graph.edge(1, 3);

	graph.render();

	return 0;
}

