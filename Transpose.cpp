#include<bits/stdc++.h>
using namespace std;
void print(vector<int> g[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(g[i].size())
			cout<<i<<" - ";
		for(int j=0;j<g[i].size();j++)
			cout<<g[i][j]<<" ";
		if(g[i].size())	
			cout<<endl;
	}
}
int main()
{
	int n,m,a,b;
	cout<<endl<<"ENTER THE NO OF VERTICES  :  ";
	cin>>n;
	cout<<endl<<"ENTER THE NO OF EDGES  :  ";
	cin>>m;
	vector<int> g[n],gt[n];
	cout<<endl<<"ENTER THE EDGE DETAILS  :  \n";
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		g[a].push_back(b);
		gt[b].push_back(a);
	}
	cout<<endl<<"GRAPH BEFORE TRANSPOSE  :  \n";
	print(g,n);
	cout<<endl<<"GRAPH AFTER TRANSPOSE  :  \n";
	print(gt,n);
	cout<<endl;
}
	
