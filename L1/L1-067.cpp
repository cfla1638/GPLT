//L1-064
/*
�����Ĵ������������滻���ַ����ཻ���ˣ�����ǰ���can you, ������ I can ���� �ڰ�I���� you��ʱ��I can����you can, �����ҽ�������е�Ҫ�滻���ַ�������ǰȫ���滻��������ַ��������������ַ������ܺ���I, ���ͳһ�滻������ַ�����
�ٸ������Ȱ�can you�滻��|*c*y*|�������ͳһ�����е�|*c*y*|���滻��I can
*/
#include <bits/stdc++.h>
using namespace std;

void Rep(string &ori, string target, string replacement, int len)
{
    int pos = 0;
    while ((pos = ori.find(target, pos)) != string::npos)
    {
        if (pos != 0 && (pos + len < ori.size()) &&
        (ori[pos - 1] == ' ' || ispunct(ori[pos - 1])) && (ori[pos + len] == ' ' || ispunct(ori[pos + len])) )
            ori.replace(pos, len, replacement);
        else if (pos == 0 && pos + len == ori.size())
            ori.replace(pos, len, replacement);
        else if (pos == 0 && (ori[pos + len] == ' ' || ispunct(ori[pos + len])))
            ori.replace(pos, len, replacement);
        else if (pos + len == ori.size() && (ori[pos - 1] == ' ' || ispunct(ori[pos - 1])))
            ori.replace(pos, len, replacement);
        pos++;
    }    
}

int main(void)
{
    int N;
    cin >> N;
    getchar();
    while(N--)
    {
        string str;
        getline(cin, str);
        cout << str << endl;
        stringstream stream(str);
        string word;
        vector<string> words;
        while (stream >> word)
            words.push_back(word);
        str.clear();
        for (vector<string>::size_type i = 0; i < words.size(); i++)
            if (i + 1 != words.size())
                str += words[i] + string(" ");
            else
                str += words[i];

        for (string::size_type i = 0; i + 1 < str.size();)
        {
            if (ispunct(str[i+1]) && str[i] == ' ')
                str.erase(i, 1);
            else
                i++;
        }
        for (auto &i : str)
            if (isupper(i) && i != 'I')
                i = tolower(i);
        for (auto &i : str)
            if (i == '?')
                i = '!';
        Rep(str, "can you", "|c*y|", 7);
        Rep(str, "could you", "|c*d*y|", 9);
        Rep(str, "me", "|m*e|", 2);
        Rep(str, "I", "|*i*|", 1);

        Rep(str, "|c*y|", "I can", 5);
        Rep(str, "|c*d*y|", "I could", 7);
        Rep(str, "|m*e|", "you", 5);
        Rep(str, "|*i*|", "you", 5);


        cout  << "AI: "<< str << endl;
    }

    return 0;
}