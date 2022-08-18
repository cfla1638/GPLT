//L2-035 完全二叉树的层序遍历
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    int val;
    node *l = nullptr;
    node *r = nullptr;
}node, *tree;

void BuildTree(tree &T, vector<int> in)
{
    if (in.size() <= 3)
    {
        if (in.size() == 3)
        {
            T = new node;
            T->val = in[2];
            T->l = new node;
            T->l->val = in[0];
            T->r = new node;
            T->r->val = in[1];
        }
        if (in.size() == 2)
        {
            T = new node; T->val = in[1];
            T->l = new node; T->l->val = in[0];
            T->r = nullptr;
        }
        if (in.size() == 1)
        {
            T = new node; T->val = in[0];
            T->l = nullptr;
            T->r = nullptr;
        }
        if (in.size() == 0)
            T = nullptr;
    }
    else
    {
        int d = (int)ceil(log(in.size() + 1) / log(2)); //深度
        int complete = pow(2, d) - 1;
        int cha = complete - in.size();
        int il = pow(2, d - 2); 
        int ir = pow(2, d - 2);
        int lc = pow(2, d - 1) - 1;
        int rc = pow(2, d - 1) - 1;

        if (cha >= ir)
        {
            rc -= ir;
            lc -= (cha - ir);
        }
        else
        {
            rc -= cha;
        }
        T = new node;
        T->val = in[in.size() - 1];
        vector<int> rin(in.begin() + lc, in.end() - 1);
        vector<int> lin(in.begin(), in.begin() + lc);
        BuildTree(T->l, lin);
        BuildTree(T->r, rin);
    }
}

vector<int> ret;
void bfs(tree T)
{
    queue<tree> q;
    q.push(T);
    while (!q.empty())
    {
        auto t = q.front(); q.pop();
        if (t != nullptr)
        {
            ret.push_back(t->val);
            q.push(t->l);
            q.push(t->r);
        }
    }
}

int main(void)
{
    int N;
    tree T;
    vector<int> in;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        in.push_back(t);
    }
    BuildTree(T, in);
    bfs(T);

    for (size_t i = 0; i < ret.size(); i++)
        if (i + 1 != ret.size())
            cout << ret[i] << " ";
        else
            cout << ret[i];
    return 0;
}