#include <bits/stdc++.h>
using namespace std;

typedef struct TreeNode
{
    int val;
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;
}*Tree, TreeNode;

void BuildTree(vector<int> back, vector<int> mid, Tree *T)
{   
    //默认从空树开始建立，初始化T为nullptr
    if (*T == nullptr)
    {
        *T = new TreeNode;
        //此节点为叶子结点，或者此节点不存在
        if (back.size() <= 1)
        {   
            //此节点不存在的情况
            if (back.size() == 0)
            {
                delete *T;      //释放分配的内存
                *T = nullptr;
                return ;
            }
            (*T)->val = back[back.size() - 1];
            return ;
        }
        (*T)->val = back[back.size() - 1];  //以此节点为根节点
        //确立根节点在中序遍历中的未知
        vector<int>::size_type t;
        for (t = 0; t < mid.size(); t++)
            if (mid[t] == back[back.size() - 1]) break;
        
        //初始化其左子树的中序、后序遍历序列
        vector<int> mid_left(mid.begin(), mid.begin() + t);
        vector<int> back_left;
        for (auto elem : back)
        {
            //保存其左子树的后序遍历顺序
            if (count(mid_left.begin(), mid_left.end(), elem) != 0)
            back_left.push_back(elem);
        }
        BuildTree(back_left, mid_left, &((*T)->left));
        //初始化其右子树中序后序遍历序列
        vector<int> mid_right(mid.begin() + t + 1, mid.end());
        vector<int> back_right;
        for (auto elem : back)
        {
            //保存其右子树的后序遍历顺序
            if (count(mid_right.begin(), mid_right.end(), elem) != 0)
            back_right.push_back(elem);
        }
        BuildTree(back_right, mid_right, &((*T)->right));
    }
}
vector<int> level;      //保存层次遍历顺序的数组
queue<Tree> Q;          //层次遍历需要使用的队列
void TraversalLevel()
{
    if (Q.empty())  return;
    Tree T = Q.front();
    Q.pop();
    if (T != nullptr)
    {
        level.push_back(T->val);
        Q.push(T->left);
        Q.push(T->right);
    }
    TraversalLevel();
}

int main(void)
{
    int N;
    vector<int> back, mid;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        back.push_back(t);
    }
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        mid.push_back(t);
    }
    Tree T;
    T = nullptr;
    BuildTree(back, mid, &T);

    Q.push(T);
    TraversalLevel();
    for (vector<int>::size_type i = 0; i < level.size(); i++)
    {
        if (i + 1 != level.size())
            cout << level[i] << " ";
        else
            cout << level[i];
    }
    return 0;
}