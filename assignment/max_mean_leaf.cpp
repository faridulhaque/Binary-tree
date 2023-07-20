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

Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node *> q;
    if (root != NULL)
        q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        int l, r;
        cin >> l >> r;

        Node *left;
        Node *right;

        if (l == -1)
            left = NULL;
        else
            left = new Node(l);

        if (r == -1)
            right = NULL;
        else
            right = new Node(r);

        p->left = left;
        p->right = right;

        if (left != NULL)
            q.push(left);

        if (right != NULL)
            q.push(right);
    }

    return root;
}

void find_leaves(Node *root, queue<int> &q)
{

    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        q.push(root->value);
    }
    else
    {
        find_leaves(root->left, q);
        find_leaves(root->right, q);
    }
}

int main()
{

    Node *root = input_tree();

    queue<int> q;

    find_leaves(root, q);

    int mx = q.front();
    int mn = q.front();

    if (q.size() > 1)
    {
        while (!q.empty())
        {
            if (q.front() > mx)
                mx = q.front();
            if (q.front() < mx)
                mn = q.front();
            q.pop();
        }

        
    }
  
    cout << mx << " " << mn << endl;

    return 0;
}
