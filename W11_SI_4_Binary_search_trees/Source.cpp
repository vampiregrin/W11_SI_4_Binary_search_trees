#include<iostream>
class Node {
    int data;
    Node* left, * right;

public:
    Node();
    Node(int);
    Node* insert(Node*, int);
    void inorder(Node*);
    Node* sortedArrayToBST(int[], int, int);
    Node* find(Node*, int);
    Node* remove(int, Node*);
    Node* findMin(Node*);
};

Node::Node() : data(0), left(NULL), right(NULL) {};

Node::Node(int value) {
    data = value;
    left = right = NULL;
}

void Node::inorder(Node* root)
{
    if (!root) {
        return;
    }
    inorder(root->left);
    std::cout << root->data << std::endl;
    inorder(root->right);
}

Node* Node::insert(Node* root, int value) {
    if (!root) {
        return new Node(value);
    }
    if (value > root->data) {
        root->right = insert(root->right, value);
    }
    else {
        root->left = insert(root->left, value);
    }
    return root;
}

Node* Node::sortedArrayToBST(int arr[], int start, int end) {

    if (start > end)
        return NULL;

    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);


    root->left = sortedArrayToBST(arr, start, mid - 1);

    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

Node* Node::find(Node* t, int x) {
    if (t == NULL)
        return NULL;
    else if (x < t->data)
        return find(t->left, x);
    else if (x > t->data)
        return find(t->right, x);
    else
        return t;
}

Node* Node::findMin(Node* t) {
    if (t == NULL)
        return NULL;
    else if (t->left == NULL)
        return t;
    else
        return findMin(t->left);
}

Node* Node::remove(int x, Node* t) {
    Node* temp;
    if (t == NULL)
        return NULL;
    else if (x < t->data)
        t->left = remove(x, t->left);
    else if (x > t->data)
        t->right = remove(x, t->right);
    else if (t->left && t->right)
    {
        temp = findMin(t->right);
        t->data = temp->data;
        t->right = remove(t->data, t->right);
    }
    else
    {
        temp = t;
        if (t->left == NULL)
            t = t->right;
        else if (t->right == NULL)
            t = t->left;
        delete temp;
    }

    return t;
}
int main() {

    return 0;
}