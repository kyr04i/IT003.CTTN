#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    int height;
};

int height(Node *node)
{
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalanceFactor(Node *node)
{
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node *maxValueNode(Node *root)
{
    Node *current = root;

    while (current->right != NULL)
        current = current->right;

    return current;
}

Node *insertNode(Node *node, int data)
{

    if (node == NULL)
        return (newNode(data));

    if (data < node->data)
        node->left = insertNode(node->left, data);
    else if (data > node->data)
        node->right = insertNode(node->right, data);

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalanceFactor(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    return node;
}

Node *deleteNode(Node *root, int data)
{

    if (root == NULL)
        return root;

    if (data > root->data)
        root->right = deleteNode(root->right, data);
    else if (data < root->data)
        root->left = deleteNode(root->left, data);
    else
    {

        if (root->left == NULL || root->right == NULL)
        {

            Node *temp = root->left;
            if (root->right != NULL)
                temp = root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
                delete temp;
            }
            else
            {

                *root = *temp;
                delete temp;
            }
        }
        else
        {

            Node *temp = maxValueNode(root->left);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int valBalance = getBalanceFactor(root);

    if (valBalance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    if (valBalance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    if (valBalance > 1 && getBalanceFactor(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (valBalance < -1 && getBalanceFactor(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;

    ifstream fi;
    ofstream fo("resultAVL.txt");

    for (int i = 1; i <= 10; i++)
    {
        string fileInp = "data" + to_string(i) + ".txt";
        fi.open(fileInp);
        if (fi.is_open())
            for (int i = 0; i < 1000000; i++)
            {
                int data;
                fi >> data;
                root = insertNode(root, data);
            }

        fo << height(root) << '\n';
    }

    fo.close();
    return 0;
}