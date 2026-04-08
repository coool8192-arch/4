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

    void erase(T data)
    {
        Node* currentNode = root;
        Node* parentNode = nullptr;

        while (currentNode->data != data) // 지울 노드를 찾기
        {
            parentNode = currentNode;

            if (currentNode->data < data)
            {
                currentNode = currentNode->right;
            }
            else
            {
                currentNode = currentNode->left;
            }

            if (currentNode == nullptr) break;
        }

        if (currentNode == nullptr) // 일치하는 값의 노드가 없을 때
        {
            cout << "the data does not exist" << endl;
            return;
        }
        else if (currentNode->left == nullptr && currentNode->right == nullptr) // 지우려는 노드의 자식 노드가 없을 때
        {
            if (parentNode != nullptr)
            {
                if (currentNode == parentNode->right)
                {
                    parentNode->right = nullptr;
                }
                else
                {
                    parentNode->left = nullptr;
                }
            }
            else
            {
                root = nullptr;
            }

            delete currentNode;
        }
        else if (currentNode->left == nullptr || currentNode->right == nullptr) // 지우려는 노드의 자식 노드가 하나일 때
        {
            if (currentNode == root)
            {
                if (currentNode->right != nullptr)
                {
                    root = currentNode->right;
                }
                else
                {
                    root = currentNode->left;
                }
            }
            else
            {
                Node* childNode = nullptr;

                if (currentNode->right != nullptr)
                {
                    childNode = currentNode->right;
                }
                else
                {
                    childNode = currentNode->left;
                }

                if (currentNode == parentNode->right)
                {
                    parentNode->right = childNode;
                }
                else
                {
                    parentNode->left = childNode;
                }
            }
            delete currentNode;
        }
        else // 지우려는 노드의 자식 노드가 둘일 때
        {
            Node* childNode = currentNode->right;
            Node* traceNode = currentNode;

            while (childNode->left != nullptr)
            {
                traceNode = childNode;

                childNode = childNode->left;
            }

            if (traceNode == currentNode)
            {
                traceNode->right = childNode->right;
            }
            else
            {
                traceNode->left = childNode->right;
            }

            currentNode->data = childNode->data;

            delete childNode;
        }
    }

    void inorder(Node* root)
    {
        if (root != nullptr)
        {
            inorder(root->left);

            cout << root->data << " ";

            inorder(root->right);
        }
    }

    void render()
    {
        inorder(root);
    }

    void release(Node* root)
    {
        if (root != nullptr)
        {
            release(root->left);

            release(root->right);

            delete root;
        }
    }

    ~Set()
    {
        release(root);
    }
};

int main()
{
    Set<int> set;

    set.insert(10);
    set.insert(15);
    set.insert(6);
    set.insert(7);
    set.insert(3);
    set.insert(4);
    set.insert(2);
    set.insert(1);
    set.insert(12);
    set.insert(14);

    set.render();

    set.erase(2);
    set.erase(1);
    set.erase(4);
    set.erase(4);
    set.erase(12);
    set.erase(15);

    return 0;
}

