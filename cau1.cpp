#include <iostream>
using namespace std;
struct Node
{
    int x;
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
void print(Tree t) // duyet theo LNR
{
    if (t == NULL)
        return;
    print(t->pleft);
    cout << t->x << " ";
    print(t->pright);
}
Node *minvalue(Node *p)
{
    if (p->pleft == NULL)
        return p;
    return minvalue(p->pleft);
}
bool find_node(Tree t, int x)
{
    if (t == NULL)
        return false;
    else
    {
        if (t->x == x)
            return true;
        else if (t->x > x)
            return find_node(t->pleft, x);
        else
            return find_node(t->pright, x);
    }
}
void delete_tree(Tree &t, int x)
{
    if (t == NULL)
        return;
    if (t->x > x)
        delete_tree(t->pleft, x);
    else if (t->x < x)
        delete_tree(t->pright, x);
    else
    {
        if (t->pleft == NULL && t->pright == NULL)
        {
            t = NULL;
            return;
        }
        else
        {
            Node *tmp;
            if (t->pleft == NULL)
                tmp = t->pright;
            else if (t->pright == NULL)
                tmp = t->pleft;
            else
                tmp = minvalue(t->pright);
            t->x = tmp->x;
            delete_tree(t->pright, t->x);
        }
    }
}
void print_NLR(Tree t)
{
    if (t == NULL)
        return;
    cout << t->x << " ";
    print_NLR(t->pleft);
    print_NLR(t->pright);
}
void print_LRN(Tree t)
{
    if (t == NULL)
        return;
    print_LRN(t->pleft);
    print_LRN(t->pright);
    cout << t->x << " ";
}
int main()
{
    freopen("test.inp", "r", stdin);
    Tree mytree = NULL;
    // them phan tu moi vao cay
    add_node(mytree, 50);
    add_node(mytree, 30);
    add_node(mytree, 20);
    add_node(mytree, 40);
    add_node(mytree, 70);
    add_node(mytree, 60);
    add_node(mytree, 80);

    // duyet theo LNR
    print(mytree);

    // delete
    delete_tree(mytree, 20);
    cout << endl;
    print(mytree);
    delete_tree(mytree, 30);
    cout << endl;
    print(mytree);
    delete_tree(mytree, 50);
    cout << endl;
    print(mytree);
    cout << endl;

    // kiem tra co phan tu trong cay khong
    cout << find_node(mytree, 40);
    cout << endl;

    // duyet NRL
    print_NLR(mytree);
    cout << endl;

    // duyet LRN
    print_LRN(mytree);
    cout << endl;
    return 0;
}