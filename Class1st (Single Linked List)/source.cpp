#include <iostream>

using namespace std;

template<typename T>
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

	void push_front(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		if (head == nullptr)
		{
			head = newNode;
			newNode->next = nullptr;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
		size++;
	}

	void pop_front()
	{
		if (head == nullptr)
		{
			cout << "List No Data" << endl;
			return;
		}

		Node* deleteNode = head;

		head = deleteNode->next;

		delete deleteNode;

		size--;
	}

	void push_back(T data)
	{
		Node* newNode = new Node;

		newNode->data = data;

		newNode->next = nullptr;

		if (head == nullptr)
		{
			head = newNode;
			newNode->next = nullptr;
		}
		else
		{
			Node* currentNode = head;

			while (currentNode->next != nullptr)
			{
				currentNode = currentNode->next;
			}
			currentNode->next = newNode;
		}
		size++;
	}

	const bool& empty()
	{
		return (head == nullptr);
	}

	void pop_back()
	{
		if (head == nullptr)
		{
			cout << "List No Data" << endl;
			return;
		}
		else
		{
			Node* deleteNode = head;
			Node* previousNode = nullptr;
			if (size == 1)
			{
				head = deleteNode->next;
			}
			else
			{
				while (deleteNode->next != nullptr)
				{
					previousNode = deleteNode;
					deleteNode = deleteNode->next;
				}
				previousNode->next = deleteNode->next;
			}
			delete deleteNode;
		}
	}

	~List()
	{
		while (head != nullptr)
		{
			pop_front();
		}
	}
};


int main()
{
	List<int> list;

	list.push_front(10);
	list.push_front(13);
	list.push_back(16);
	list.pop_front();
	list.pop_front();
	list.pop_back();
	cout << list.empty() << endl;
	return 0;
}

