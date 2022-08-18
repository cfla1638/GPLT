#include <bits/stdc++.h>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
} * Tree;

void BuildTree(Tree &T, vector<int> in)
{
    if (in.size() == 0)
    {
        T = nullptr;
        return;
    }

    T = new TreeNode;
    T->val = in[0];
    vector<int> lin, rin;
    for (size_t i = 1; i < in.size(); i++)
    {
        if (in[i] < in[0])
            lin.push_back(in[i]);
        else
            rin.push_back(in[i]);
    }
    BuildTree(T->left, lin);
    BuildTree(T->right, rin);
}

void _BuildTree(Tree &T, vector<int> in)
{
    if (in.size() == 0)
    {
        T = nullptr;
        return;
    }

    T = new TreeNode;
    T->val = in[0];
    vector<int> lin, rin;
    for (size_t i = 1; i < in.size(); i++)
    {
        if (in[i] >= in[0])
            lin.push_back(in[i]);
        else
            rin.push_back(in[i]);
    }
    _BuildTree(T->left, lin);
    _BuildTree(T->right, rin);
}

vector<int> res;

void TraversalFront(Tree &T)
{
    if (T != nullptr)
    {
        res.push_back(T->val);
        TraversalFront(T->left);
        TraversalFront(T->right);
    }
}
void TraversalBack(Tree &T)
{
    if (T != nullptr)
    {
        TraversalBack(T->left);
        TraversalBack(T->right);
        res.push_back(T->val);
    }
}

int main(void)
{
    int N;
    vector<int> in;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        in.push_back(t);
    }

    Tree T = nullptr;
    if (in[0] > in[1])
    {
        BuildTree(T, in);
        TraversalFront(T);
        if (equal(in.begin(), in.end(), res.begin()))
        {
            cout << "YES" << endl;
            res.clear();
            TraversalBack(T);
            for (size_t i = 0; i < res.size(); i++)
                if (i + 1 != res.size())
                    cout << res[i] << " ";
                else
                    cout << res[i];
        }
        else
            cout << "NO";
    }
    else
    {
        _BuildTree(T, in);
        TraversalFront(T);
        if (equal(in.begin(), in.end(), res.begin()))
        {
            cout << "YES" << endl;
            res.clear();
            TraversalBack(T);
            for (size_t i = 0; i < res.size(); i++)
                if (i + 1 != res.size())
                    cout << res[i] << " ";
                else
                    cout << res[i];
        }
        else
            cout << "NO";
    }

    
    return 0;
}