#include <iostream>
using namespace std;
struct Node
{
    int x, len;
    Node *pleft;
    Node *pright;
};
typedef Node *Tree;
void add_node(Tree &t, int x)
{
    if (t == NULL)
    {
        Node *p = new Node;
        p->x = x;
        p->pleft = NULL;
        p->pright = NULL;
        p->len = 0;
        t = p;
    }
    else
    {
        if (t->x > x)
            add_node(t->pleft, x);
        else
            add_node(t->pright, x);
    }
}
void duyet_cay(Tree t)
{
    if (t == NULL)
        return;
    duyet_cay(t->pleft);
    duyet_cay(t->pright);
    if (t->pleft == NULL && t->pright == NULL)
        t->len = 0;
    else if (t->pleft == NULL)
    {
        t->len = (t->pright)->len + 1;
    }
    else if (t->pright == NULL)
    {
        t->len = (t->pleft)->len + 1;
    }
    else
    {
        t->len = max((t->pleft)->len, (t->pright)->len) + 1;
    }
}
int main()
{
    // freopen("test.inp", "r", stdin);
    int n, x;
    Tree mytree = NULL;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        add_node(mytree, x);
    }
    duyet_cay(mytree);
    cout << mytree->len;
    return 0;
}