#include<bits/stdc++.h>
using namespace std;
void dfs(int v,bool mark[],vector<int> &ans,vector<int> g[])
{
	mark[v]=1;
	for(int i=0;i<g[v].size();i++)
		if(!mark[g[v][i]])
			dfs(g[v][i],mark,ans,g);
	ans.push_back(v);
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
	}
	bool mark[n];
	vector<int> ans;
	memset(mark,0,sizeof(mark));
	for(int i=0;i<n;i++)
		if(!mark[i])
			dfs(i,mark,ans,g);
	cout<<endl<<"TOPOLOGICAL SORTING OF THE GIVEN GRAPH IS  :  ";
	for(int i=0;i<n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
