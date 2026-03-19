#include <iostream>

using namespace std;

template <typename T>
class List
{
	struct Node
	{
		T data;
		Node* next;
	};
	int size;
	Node* head;

public:
	List()
	{
		size = 0;
		head = nullptr;
	}

	void push_back(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;

			newNode->next = head;
		}
		else
		{
			newNode->next = head->next;
			
			head->next = newNode;

			head = newNode;
		}
		size++;
	}

	void pop_back()
	{
		if (head == nullptr)
		{
			cout << "List No Data" << endl;
		}
		else
		{
			if (head->next = head)
			{
				head = nullptr;
			}
			else
			{
				Node* currentNode = head;

				while (currentNode->next != head)
				{
					currentNode = currentNode->next;
				}

				currentNode->next = head->next;

				delete head;

				head = currentNode;
			}
			size--;
		}
	}
};

int main()
{
	List<int> list;

	list.push_back(15);
	list.pop_back();
	list.pop_back();

	return 0;
}

