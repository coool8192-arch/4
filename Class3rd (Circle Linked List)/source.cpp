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
			if (head->next == head)
			{
				head = nullptr;
			}
			else
			{
				Node* currentNode = head->next;
				Node* deleteNode = head;

				while (currentNode->next != head) // for (int i = 0; i < size - 1; i++)
				{
					currentNode = currentNode->next;
				}

				currentNode->next = head->next;

				head = currentNode;

				delete deleteNode;
			}
			size--;
		}
	}

	void push_front(T data)
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
		}
		size++;
	}

	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "List No Data" << endl;
		}
		else
		{
			if (head->next == head)
			{
				head = nullptr;
			}
			else
			{
				Node* deleteNode = head->next;

				head->next = deleteNode->next;

				delete deleteNode;
			}
			size--;
		}

	}

	const bool& empty()
	{
		return head == nullptr;
	}

	~List()
	{
		while (!empty())
		{
			pop_front();
		}
	}
};

int main()
{
	List<int> list;

	list.push_back(15);
	list.push_back(19);
	list.push_front(23);
	list.push_front(12);

	list.pop_back();
	list.pop_back();
	list.pop_front();
	list.pop_front();
	list.pop_front();
	return 0;
}

