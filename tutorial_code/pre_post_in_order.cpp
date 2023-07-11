#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;

    Node *left;
    Node *right;

    Node(int value)
    {
        this->value = value;
        this->left = NULL;
        this->right = NULL;
    }
};

void postOrder(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    cout << root->value << " ";
    postOrder(root->left);
    postOrder(root->right);
}

void preOrder(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    preOrder(root->left);
    preOrder(root->right);
    cout << root->value << " ";
}

void inOrder(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->value << " ";
    inOrder(root->right);
}

int main()
{
    Node *root = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node *e = new Node(60);
    Node *f = new Node(70);
    Node *g = new Node(80);
    Node *h = new Node(90);
    Node *i = new Node(100);

    root->left = a;
    root->right = b;
    a->left = c;
    a->right = h;
    c->right = e;
    b->right = d;
    d->left = f;
    d->right = g;
    h->right = i;

    preOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    inOrder(root);
    return 0;
}