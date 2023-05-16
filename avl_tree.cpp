#include <iostream>
using namespace std;
struct Node
{
    int x, height;
    Node *pleft;
    Node *pright;
};
typedef Node *Tree;
int height(Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}
Node *create_node(int x)
{
    Node *tmp = new Node;
    tmp->height = 1;
    tmp->x = x;
    tmp->pleft = tmp->pright = NULL;
    return tmp;
}
Node *rightRotate(Node *y)
{
    Node *x = y->pleft;
    Node *t2 = x->pright;

    x->pright = y;
    y->pleft = t2;

    y->height = max(height(y->pleft), height(y->pright)) + 1;
    x->height = max(height(x->pleft), height(x->pright)) + 1;
    // return new root
    return x;
}
Node *leftRotate(Node *x)
{
    Node *y = x->pright;
    Node *t2 = y->pleft;

    y->pleft = x;
    x->pright = t2;

    x->height = max(height(x->pleft), height(x->pright)) + 1;
    y->height = max(height(y->pleft), height(y->pright)) + 1;
    // return new root
    return y;
}
int get_balance(Node *t)
{
    return (!t ? 0 : height(t->pleft) - height(t->pright));
}
Node *insert(Tree t, int x)
{
    if (t == NULL)
        return create_node(x);
    if (t->x > x)
        t->pleft = insert(t->pleft, x);
    else
        t->pright = insert(t->pright, x);

    t->height = max(height(t->pleft), height(t->pright)) + 1;
    int balanced = get_balance(t);

    // left left case
    if (balanced > 1 && x < t->pleft->x)
        return rightRotate(t);
    // right right case
    if (balanced < -1 && x > t->pright->x)
        return leftRotate(t);
    // left right case
    if (balanced > 1 && x > t->pleft->x)
    {
        t->pleft = leftRotate(t->pleft);
        return rightRotate(t);
    }
    // right left case
    if (balanced < -1 && x < t->pright->x)
    {
        t->pright = rightRotate(t->pright);
        return leftRotate(t);
    }

    // return unchange node pointer
    return t;
}
void print(Tree t)
{
    if (t == NULL)
        return;
    cout << t->x << " ";
    print(t->pleft);
    print(t->pright);
}
int main()
{
    freopen("test.inp", "r", stdin);
    Tree t = NULL;
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        t = insert(t, x);
    }
    print(t);
    return 0;
}