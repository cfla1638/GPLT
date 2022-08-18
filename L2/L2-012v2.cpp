#include<bits/stdc++.h>
using namespace std;
int a[10000];
int n, m, sz=0;
void push(int x)
{
	int i=sz++;
	while(i>0)
	{
		int p=(i-1)/2;
		if(a[p]<=x)    break;
		a[i]=a[p];
		i=p;
	}
	a[i]=x;
}

int pos(int x)
{
	int i;
	for (i = 0; i < sz; i++)
		if (x == a[i]) break;
	return i;
}

int main()
{
	cin>>n>>m;
	for(int i=0; i<n; i++)
	{
		int x;
		cin>>x;
		push(x);
	}
	for(int cnt=0; cnt<m; cnt++)
	{
		//cout<<cnt<<" "<<m<<endl;
		int x, y;
		string ch, c_a, c_b, c_c;
		cin>>x;
		//cout<<x<<" ";
		cin>>ch;
		//cout<<ch<<" ";
		if(ch[0]=='a')
		{
			cin>>y;
			if (pos(x) == 0 || pos(y) == 0)
				cout << "F" << endl;
			else if (((pos(x) - 1) / 2) == ((pos(y) - 1) / 2) )
				cout << "T" << endl;
			else
				cout << "F" << endl;
			cin>>c_a>>c_b;
		}
		else
		{
			string c;
			cin>>c;
			if(c[0]=='a')
			{
				cin>>c_a>>c_b;
				cin>>y;
				if (((pos(x) - 1) / 2) == pos(y))
                    cout << "T" << endl;
                else 
                    cout << "F" << endl;
			}
			else
			{
				string p;
				cin>>p;
				if(p[0]=='r')
				{
					if(a[0]==x) cout<<"T"<<endl;
					else cout<<"F"<<endl;
				}
				else
				{
					int z;
					cin>>c_a;
					cin>>z;
                	if (((pos(y) - 1) / 2) == pos(x))
                		cout << "T" << endl;
                	else 
                    	cout << "F" << endl;
				}
			}
		}
	}
	return 0;
}
