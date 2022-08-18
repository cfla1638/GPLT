//L2-018 多项式A除以B
#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
    node() = default;
    node(double c, int e) : coe(c), exp(e) {}  
    double coe = 0;     //系数
    int exp = 0;        //指数
}node;

typedef struct
{
    vector<node> poly;
    int maxPower = 0;
}Polynomial;

Polynomial Multi(Polynomial a, node coe)
{
    a.maxPower += coe.exp;
    for (auto &i : a.poly)
    {
        i.coe *= coe.coe;
        i.exp += coe.exp;
    }
    for (auto i = a.poly.begin(); i != a.poly.end(); i++)
        if (i->coe == 0)
            a.poly.erase(i);
    return a;
}

Polynomial Add(Polynomial a, Polynomial b)
{
    if (a.maxPower == 0) return b;
    if (b.maxPower == 0) return a;
    Polynomial ans;
    ans.maxPower = (a.maxPower > b.maxPower ? a.maxPower : b.maxPower);
    vector<node>::size_type la = 0, lb = 0;
    while (la < a.poly.size() && lb < b.poly.size())
    {
        if (a.poly[la].exp == b.poly[lb].exp)
        { 
            ans.poly.push_back(node(a.poly[la].coe + b.poly[lb].coe, b.poly[lb].exp));
            la++; lb++;
        }
        else if (a.poly[la].exp > b.poly[lb].exp)
        {
            ans.poly.push_back(node(a.poly[la].coe, a.poly[la].exp));
            la++;
        }
        else if (b.poly[lb].exp > a.poly[la].exp)
        {
            ans.poly.push_back(node(b.poly[lb].coe, b.poly[lb].exp));
            lb++;
        }
    }
    if (la == a.poly.size() && lb < b.poly.size())
        while (lb < b.poly.size())
        {
            ans.poly.push_back(node(b.poly[lb].coe, b.poly[lb].exp));
            lb++;
        }
    if (la < a.poly.size() && lb == b.poly.size())
        while (la < a.poly.size())
        {
            ans.poly.push_back(node(a.poly[la].coe, a.poly[la].exp));
            la++;
        }

    for (auto i = ans.poly.begin(); i != ans.poly.end(); i++)
        if (i->coe == 0)
            ans.poly.erase(i);
    ans.maxPower = ans.poly[0].exp;

    return ans;
}

Polynomial &reverse(Polynomial &a)
{
    for (auto &i : a.poly)
        i.coe = -i.coe;
    return a;
}

void clear(Polynomial &p)
{
    for (auto i = p.poly.begin(); i != p.poly.end(); i++)
    {
        if (fabs(i->coe) < 0.1)
        {    
            if (i + 1 == p.poly.end())
            {
                p.poly.pop_back();
                return ;
            }    
            else
                p.poly.erase(i);
        }
    }    
}

void show(Polynomial a)
{
    for (auto i : a.poly)
        cout << i.coe << " " << i.exp << endl;
}

int main(void)
{
    Polynomial R, b, Q;
    int N, exp;
    double coe;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> exp >> coe;
        R.poly.push_back(node(coe, exp));
        if (exp > R.maxPower)
            R.maxPower = exp;
    }
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> exp >> coe;
        b.poly.push_back(node(coe, exp));
        if (exp > b.maxPower)
            b.maxPower = exp;
    }
    if (R.maxPower < b.maxPower)
    {
        cout << "0 0 0.0" << endl;
        cout << R.poly.size() << " ";
        for (vector<node>::size_type i = 0; i < R.poly.size(); i++)
        if (i + 1 != R.poly.size())
            printf("%d %.1f ", R.poly[i].exp, R.poly[i].coe);
        else    
            printf("%d %.1f\n", R.poly[i].exp, R.poly[i].coe);
        return 0;
    }
    while (R.maxPower >= b.maxPower)
    {
        Polynomial temp;
        node coe;
        coe.coe = R.poly[0].coe / b.poly[0].coe;
        coe.exp = R.poly[0].exp - b.poly[0].exp;
        temp = Multi(b, coe);
        R = Add(R, reverse(temp));
        Q.poly.push_back(coe);
    }
    clear(Q);
    clear(R);
    cout << Q.poly.size() << " ";
    for (vector<node>::size_type i = 0; i < Q.poly.size(); i++)
        if (i + 1 != Q.poly.size())
            printf("%d %.1f ", Q.poly[i].exp, Q.poly[i].coe);
        else    
            printf("%d %.1f\n", Q.poly[i].exp, Q.poly[i].coe);

    if (R.poly.empty())
    {
        cout << "0 0 0.0" << endl;
        return 0;
    }
    cout << R.poly.size() << " ";
    for (vector<node>::size_type i = 0; i < R.poly.size(); i++)
        if (i + 1 != R.poly.size())
            printf("%d %.1f ", R.poly[i].exp, R.poly[i].coe);
        else    
            printf("%d %.1f\n", R.poly[i].exp, R.poly[i].coe);
}
