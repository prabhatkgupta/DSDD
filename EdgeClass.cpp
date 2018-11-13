#include<bits/stdc++.h>
using namespace std;
int cnt=0;
map< pair<int,int>,char > mp;
void dfs(int v,int mark[],vector<int> g[],int store[])
{
	mark[v]=1;
	store[v]=cnt;
	for(int i=0;i<g[v].size();i++)
	{
		pair<int,int> p=make_pair(v,g[v][i]);
		if(mark[g[v][i]]==0)
		{
			mp[p]='T';
			dfs(g[v][i],mark,g,store);
		}
		else if(mark[g[v][i]]==1)
			mp[p]='B';
		else
		{
			if(store[g[v][i]]==store[v])
				mp[p]='F';
			else mp[p]='C';		
		}
	}
	mark[v]=2;
}
int main()
{
	int n,m,a,b;
	cout<<endl<<"ENTER THE NO OF VERTICES  :  ";
	cin>>n;
	cout<<endl<<"ENTER THE NO OF EDGES  :  ";
	cin>>m;
	vector<int> g[n];
	cout<<endl<<"ENTER THE EDGE DETAILS  :  \n";
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		g[a].push_back(b);
		mp[make_pair(a,b)]='T';
	}
	int mark[n],store[n];
	memset(mark,0,sizeof(mark));
	for(int i=0;i<n;i++)
	{
		cnt++;
		if(mark[i]==0)
			dfs(i,mark,g,store);
	}
	cout<<endl<<"CLASSIFICATION OF TREE EDGES ARE  :  "<<endl;
	for(map< pair<int,int>,char >::iterator it=mp.begin();it!=mp.end();it++)
		cout<<(it->first).first<<" "<<(it->first).second<<" - "<<it->second<<endl;
}
