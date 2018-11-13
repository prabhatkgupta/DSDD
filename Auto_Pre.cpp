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

void Automata(vector<int> &pre,vector<vector<int> > &arr,string &p)
{
	int m=pre.size();
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<26;j++)
		{
			if(i==0)
			{
				if(j+'a'==p[i])
					arr[i][j]=1;
				else arr[i][j]=0;
			}
			else 
			{
				if(i==m||p[i]!=j+'a')
					arr[i][j]=arr[pre[i-1]][j];
				else 
					arr[i][j]=i+1;
			}
		}
	}
}

void match(vector<vector<int> > &arr,string &t,int m)
{
	int n=t.length();	
	int q=0;	
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		q=arr[q][t[i]-'a'];	
		v.push_back(q);
		if(q==m)
			cout<<"PATTERN FOUND AT i = "<<i-m+1<<endl;
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
	vector<vector<int> > arr(m+1,vector<int> (26));
	build(pre,p,m);
	cout<<endl;	
	Automata(pre,arr,p);
	match(arr,t,m);
}
