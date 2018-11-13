#include<bits/stdc++.h>
using namespace std;

void build(vector<int> &pre,string &p,int m)
{
	pre[0]=0;
	int j=0;
	for(int i=1;i<m;i++)
	{
		while(p[j]!=p[i]&&j>0)
			j=pre[j-1];
		if(p[j]==p[i])
			j++;
		pre[i]=j;
	}
}

void match(vector<int> &pre,string &t,string &p)
{
	int n,m,j;
	n=t.length();
	m=p.length();
	j=0;
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		while(p[j]!=t[i]&&j>0)
			j=pre[j-1];
		if(p[j]==t[i])
			j++;
		v.push_back(j);
		if(j==m)
		{
			cout<<"PATTERN OCCUR AT i = "<<i-m+1<<endl;
			j=pre[j-1];
		}
	}
	cout<<endl<<"INTERMEDIATE STATES OF PATTERN MATCHING  :  ";
	for(int i=0;i<v.length();i++)
		cout<<v[i]<<" ";
}

int main()
{
	string p,t;
	int n,m;
	cout<<endl<<"ENTER THE TEXT STRING  :  ";
	cin>>t;
	n=t.length();
	cout<<endl<<"ENTER THE PATTERN STRING  :  ";
	cin>>p;
	m=p.length();
	vector<int> pre(m,0);
	build(pre,p,m);
	cout<<endl;	
	match(pre,t,p);
}
	
