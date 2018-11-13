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
	int n,m,a,b,flag=1;
	cout<<endl<<"ENTER THE NO OF VERTICES  :  ";
	cin>>n;
	cout<<endl<<"ENTER THE NO OF EDGES  :  ";
	cin>>m;
	vector<int> g[n];
	int arr[n][n];
	memset(arr,0,sizeof(arr));
	for(int i=0;i<n;i++)
		arr[i][i]=1;
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
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<g[i].size();j++)
		{
			for(int k=0;k<n;k++)
				arr[i][k]+=arr[g[i][j]][k];
		}
		for(int j=0;j<n;j++)
			if(arr[i][j]>1)
				flag=0;
	}
	if(flag)
		cout<<endl<<"SINGLY GRAPH";
	else cout<<endl<<"NOT SINGLY GRAPH";
	cout<<endl;
}
