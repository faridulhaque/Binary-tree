#include <iostream>
#include <queue>
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
    if (val == -1)
        return NULL;

    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1)
        {
            p->left = new Node(l);
            q.push(p->left);
        }

        if (r != -1)
        {
            p->right = new Node(r);
            q.push(p->right);
        }
    }

    return root;
}

int max_height(Node *root)
{
    if (root == NULL)
        return 0;

    int l = max_height(root->left);
    int r = max_height(root->right);

    return max(l, r) + 1;
}

void node_count(Node *root, int &count)
{
    if (root == NULL)
        return;

    node_count(root->left, count);
    node_count(root->right, count);
    count++;
}

int power(int a, int b)
{
    int result = 1;

    for (int i = 0; i < b; i++)
    {
        result = result * a;
    }

    return result;
}

int main()
{
    Node *root = input_tree();

    int count = 0;
    node_count(root, count);
    int h = max_height(root);

    int p = power(2, h) - 1;

    if (count == p)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
