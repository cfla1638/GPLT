#include <bits/stdc++.h>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
} * Tree;

void BuildTree(Tree &T, vector<int> mid, vector<int> pre)
{
    if (mid.size() == 0)
    {
        T = nullptr;
        return;
    }
    if (mid.size() == 1)
    {
        T = new TreeNode;
        T->val = mid[0];
        return ;
    }
    T = new TreeNode;
    T->val = pre[0];
    auto pos = find(mid.begin(), mid.end(), pre[0]);
    vector<int> lmid(mid.begin(), pos), rmid(pos + 1, mid.end());
    vector<int> lpre, rpre;
    for (auto i : pre)
    {
        if (find(lmid.begin(), lmid.end(), i) != lmid.end())
            lpre.push_back(i);
        if (find(rmid.begin(), rmid.end(), i) != rmid.end())
            rpre.push_back(i);
    }
    BuildTree(T->left, lmid, lpre);
    BuildTree(T->right, rmid, rpre);
}

void reverse(Tree &T)
{
    if (T != nullptr)
    {
        auto t = T->left;
        T->left = T->right;
        T->right = t;
        reverse(T->left);
        reverse(T->right);
    }
}


vector<int> ret;
queue<Tree> q;
void BFS(Tree T)
{
    if (T != nullptr)
        q.push(T);
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();

        ret.push_back(t->val);
        if (t->left != nullptr)
            q.push(t->left);
        if (t->right != nullptr)
            q.push(t->right);
    }
}

int main(void)
{
    int N, t;
    vector<int> mid, pre;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> t;
        mid.push_back(t);
    }

    for (int i = 0; i < N; i++)
    {
        cin >> t;
        pre.push_back(t);
    }
    Tree T;
    BuildTree(T, mid, pre);
    reverse(T);
    BFS(T);

    for (size_t i = 0; i < ret.size(); i++)
        if (i + 1 != ret.size())
            cout << ret[i] << " ";
        else
            cout << ret[i];
    return 0;
}