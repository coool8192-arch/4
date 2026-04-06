#include <iostream>

using namespace std;

template <typename T>
class Set
{
    struct Node
    {
        T data;

        Node* left = nullptr;
        Node* right = nullptr;

        Node(T data)
        {
            this->data = data;
        }
    };

    Node* root;
public:
    Set()
    {
        root = nullptr;
    }

    void insert(T data)
    {
        if (root == nullptr)
        {
            root = new Node(data);
        }
        else
        {
            Node* currentNode = root;

            while (true)
            {
                if (data < currentNode->data)
                {
                    if (currentNode->left == nullptr)
                    {
                        currentNode->left = new Node(data);

                        break;
                    }
                    else
                    {
                        currentNode = currentNode->left;
                    }
                }
                else if (data > currentNode->data)
                {
                    if (currentNode->right == nullptr)
                    {
                        currentNode->right = new Node(data);

                        break;
                    }
                    else
                    {
                        currentNode = currentNode->right;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }

};

int main()
{
    Set<int> set;

    set.insert(10);
    set.insert(15);
    set.insert(6);
    set.insert(12);

    return 0;
}

