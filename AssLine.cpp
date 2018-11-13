#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cout<<"\nENTER THE NO OF STATIONS  :  ";
	cin>>n;
	pair<int,int> s,e,arr[n],ans[n],path[n],t[n];
	cout<<"\nENTER THE STARTING COSTS  :  ";
	cin>>s.first>>s.second;
	cout<<"\nENTER THE COST OF FIRST LINE STATIONS  :  ";
	for(int i=0;i<n;i++)
		cin>>arr[i].first;
	cout<<endl<<"ENTER THE COST OF SECOND LINE STATIONS  :  ";
	for(int i=0;i<n;i++)
		cin>>arr[i].second;
	cout<<"\nENTER THE ENDING COSTS  :  ";
	cin>>e.first>>e.second;
	cout<<endl<<"ENTER THE SWITCHING COSTS TO FIRST LINE :  ";
	for(int i=1;i<n;i++)
		cin>>t[i].first;
	cout<<endl<<"ENTER THE SWITCHING COSTS TO SECOND LINE :  ";
	for(int i=1;i<n;i++)
		cin>>t[i].second;
	ans[0].first=s.first+arr[0].first;
	ans[0].second=s.second+arr[0].second;
	for(int i=1;i<n;i++)
	{
		if(ans[i-1].first<ans[i-1].second+t[i].first)	
		{
			ans[i].first=ans[i-1].first;
			path[i].first=1;
		}
		else 
		{
			ans[i].first=ans[i-1].second+t[i].first;
			path[i].first=2;
		}
		ans[i].first+=arr[i].first;
		if(ans[i-1].second<ans[i-1].first+t[i].second)
		{
			ans[i].second=ans[i-1].second;
			path[i].second=2;
		}
		else 
		{
			ans[i].second=ans[i-1].first+t[i].second;
			path[i].second=1;
		}
		ans[i].second+=arr[i].second;
	}
	int store,mincost,temp=n-1;
	if(e.first+ans[n-1].first<e.second+ans[n-1].second)
	{
		store=1;
		mincost=e.first+ans[n-1].first;
	}
	else 
	{
		store=2;
		mincost=e.second+ans[n-1].second;
	}
	cout<<endl<<endl<<"MINIMUM COST OF ASSEMBLY SCHEDULING IS  : "<<mincost<<endl;
	stack<int> st;
	while(temp!=0)
	{
		st.push(store);
		if(store==1)
			store=path[temp].first;
		else 
			store=path[temp].second;
		temp--;
	}
	st.push(store);
	cout<<endl<<endl<<"OPTIMAL PATH IS  :  ";
	while(!st.empty())
	{
		cout<<st.top();
		st.pop();
		if(st.size())
			cout<<"--->";
	}
	cout<<endl<<endl;
}
