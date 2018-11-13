#include<bits/stdc++.h>
using namespace std;
void dfs1(int v,bool mark[],vector<int> g[],stack<int> &s)
{
	mark[v]=1;
	for(int i=0;i<g[v].size();i++)
		if(!mark[g[v][i]])
			dfs1(g[v][i],mark,g,s);
	s.push(v);
}
void dfs2(int v,bool mark[],vector<int> gt[])
{
	mark[v]=1;
	for(int i=0;i<gt[v].size();i++)
		if(!mark[gt[v][i]])
			dfs2(gt[v][i],mark,gt);
	cout<<v<<" ";
}
int main()
{
	int n,m,a,b;
	cout<<endl<<"ENTER THE NO OF VERTICES  :  ";
	cin>>n;
	cout<<endl<<"ENTER THE NO OF EDGES  :  ";
	cin>>m;
	vector<int> g[n+1],gt[n+1];
	cout<<endl<<"ENTER THE EDGE DETAILS  :  \n";
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		g[a].push_back(b);
		gt[b].push_back(a);
	}
	stack<int> s;
	bool mark[n+1];
	memset(mark,0,sizeof(mark));
	for(int i=1;i<=n;i++)
		if(!mark[i])
			dfs1(i,mark,g,s);
	memset(mark,0,sizeof(mark));
	cout<<endl<<"STRONGLY CONNECTED COMPONENTS ARE  :  "<<endl;
	while(!s.empty())
	{		
		a=s.top();
		s.pop();
		if(mark[a])
			continue;
		else 
			dfs2(a,mark,gt);
		cout<<endl;
	}
}
