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
    //Ĭ�ϴӿ�����ʼ��������ʼ��TΪnullptr
    if (*T == nullptr)
    {
        *T = new TreeNode;
        //�˽ڵ�ΪҶ�ӽ�㣬���ߴ˽ڵ㲻����
        if (back.size() <= 1)
        {   
            //�˽ڵ㲻���ڵ����
            if (back.size() == 0)
            {
                delete *T;      //�ͷŷ�����ڴ�
                *T = nullptr;
                return ;
            }
            (*T)->val = back[back.size() - 1];
            return ;
        }
        (*T)->val = back[back.size() - 1];  //�Դ˽ڵ�Ϊ���ڵ�
        //ȷ�����ڵ�����������е�δ֪
        vector<int>::size_type t;
        for (t = 0; t < mid.size(); t++)
            if (mid[t] == back[back.size() - 1]) break;
        
        //��ʼ���������������򡢺����������
        vector<int> mid_left(mid.begin(), mid.begin() + t);
        vector<int> back_left;
        for (auto elem : back)
        {
            //�������������ĺ������˳��
            if (count(mid_left.begin(), mid_left.end(), elem) != 0)
            back_left.push_back(elem);
        }
        BuildTree(back_left, mid_left, &((*T)->left));
        //��ʼ������������������������
        vector<int> mid_right(mid.begin() + t + 1, mid.end());
        vector<int> back_right;
        for (auto elem : back)
        {
            //�������������ĺ������˳��
            if (count(mid_right.begin(), mid_right.end(), elem) != 0)
            back_right.push_back(elem);
        }
        BuildTree(back_right, mid_right, &((*T)->right));
    }
}
vector<int> level;      //�����α���˳�������
queue<Tree> Q;          //��α�����Ҫʹ�õĶ���
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