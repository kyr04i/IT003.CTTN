#include <bits/stdc++.h>
using namespace std;

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node* left;
    Node* right;
    Node* parent;
    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;

    // Hàm hỗ trợ
    void rotateLeft(Node* node);
    void rotateRight(Node* node);
    void fixViolation(Node* node);
    int getHeightRecursive(Node* node);

public:
    // Constructor
    RedBlackTree() : root(nullptr) {}

    // Phương thức chính
    void insert(int data);
    void printInOrder(Node* node);
    void printTree();
    int getHeight();
};
// Hàm xoay trái
void RedBlackTree::rotateLeft(Node* node) {
    Node* rightChild = node->right;
    node->right = rightChild->left;

    if (rightChild->left != nullptr) {
        rightChild->left->parent = node;
    }

    rightChild->parent = node->parent;

    if (node->parent == nullptr) {
        root = rightChild;
    } else if (node == node->parent->left) {
        node->parent->left = rightChild;
    } else {
        node->parent->right = rightChild;
    }

    rightChild->left = node;
    node->parent = rightChild;
}

// Hàm xoay phải
void RedBlackTree::rotateRight(Node* node) {
    Node* leftChild = node->left;
    node->left = leftChild->right;

    if (leftChild->right != nullptr) {
        leftChild->right->parent = node;
    }

    leftChild->parent = node->parent;

    if (node->parent == nullptr) {
        root = leftChild;
    } else if (node == node->parent->left) {
        node->parent->left = leftChild;
    } else {
        node->parent->right = leftChild;
    }

    leftChild->right = node;
    node->parent = leftChild;
}

// Hàm cân bằng cây
void RedBlackTree::fixViolation(Node* node) {
    Node* parent = nullptr;
    Node* grandparent = nullptr;

    while (node != root && node->color == RED && node->parent->color == RED) {
        parent = node->parent;
        grandparent = parent->parent;


        if (parent == grandparent->left) {
            Node* uncle = grandparent->right;

            if (uncle != nullptr && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                // Trường hợp 1B: Chút đỏ
                if (node == parent->right) {
                    rotateLeft(parent);
                    node = parent;
                    parent = node->parent;
                }
                rotateRight(grandparent);
                std::swap(parent->color, grandparent->color);
                node = parent;
            }
        }
        else {
            Node* uncle = grandparent->left;

            if (uncle != nullptr && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            } else {
                if (node == parent->left) {
                    rotateRight(parent);
                    node = parent;
                    parent = node->parent;
                }

                rotateLeft(grandparent);
                std::swap(parent->color, grandparent->color);
                node = parent;
            }
        }
    }

    root->color = BLACK;
}
//
int RedBlackTree::getHeightRecursive(Node* node) {
    if (node == nullptr) {
        return 0;
    }

    int leftHeight = getHeightRecursive(node->left);
    int rightHeight = getHeightRecursive(node->right);

    return std::max(leftHeight, rightHeight) + 1;
}
// Hàm chèn phần tử vào cây đỏ-đen
void RedBlackTree::insert(int data) {
    Node* newNode = new Node(data);

    Node* current = root;
    Node* parent = nullptr;

    while (current != nullptr) {
        parent = current;
        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    newNode->parent = parent;

    if (parent == nullptr) {
        root = newNode;
    } else if (data < parent->data) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    fixViolation(newNode);
}

void RedBlackTree::printInOrder(Node* node) {
    if (node == NULL) {
        return;
    }

    printInOrder(node->left);
    std::cout << node->data << " ";
    printInOrder(node->right);
}

// Hàm in cây đỏ-đen
void RedBlackTree::printTree() {
    if (root == nullptr) {
        std::cout << "Cây đỏ-đen rỗng." << std::endl;
    } else {
        std::cout << "Cây đỏ-đen: ";
        printInOrder(root);
        std::cout << std::endl;
    }
}

int RedBlackTree::getHeight() {
    return getHeightRecursive(root);
}

int main() {
    ofstream fo("resultRB.txt");
    for (int f = 1; f <= 10; ++f) {
        RedBlackTree bst;
        ifstream fi("data" + std::to_string(f) + ".txt");
        int N; fi >> N;
        for (int i = 0 ; i < N; ++i) {
            int a; fi >> a; bst.insert(a);
        }
        fo << bst.getHeight() <<'\n';
    }
}
