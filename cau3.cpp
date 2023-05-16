#include <bits/stdc++.h>
using namespace std;

const int N = 35;
int n, a[N], child[N], C[N][N];

struct Node
{
    int x, id;
    Node *pleft;
    Node *pright;
};

typedef Node *Tree;

void add_node(Tree &t, int x)
{
    if (t == NULL)
    {
        Node *p = new Node;
        p->x = a[x];
        p->id = x;
        p->pleft = NULL;
        p->pright = NULL;
        t = p;
    }
    else
    {
        if (t->x > a[x])
            add_node(t->pleft, x);
        else
            add_node(t->pright, x);
    }
}

bool is_leaf(Tree u) {
    return (!u->pleft && !u->pright);
}
void BuildTree(Tree& root) {
    for (int i = 1; i <= n; i++) {
        add_node(root, i);
    }
}

int nChild(Tree u) {
    return (u ? child[u->id] : 0);
}

int cal(Tree u) {
    if (!u)
        return 1;
    child[u->id] = 1;
    if (is_leaf(u)) 
        return 1;
    int resL = cal(u->pleft), resR = cal(u->pright);
    int nChildL = nChild(u->pleft), nChildR = nChild(u->pright);
    child[u->id] += nChildL + nChildR;
    return C[nChildL + nChildR][nChildL] * resL * resR;
}

int main() {
    freopen("test.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Tree root = NULL;
    BuildTree(root);
    for (int i = 0; i <= 30; i++)
        C[i][0] = 1;
    for (int i = 1; i <= 30; i++)
        for (int j = 1; j <= i; j++)
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    cout << cal(root);
    return 0;
}