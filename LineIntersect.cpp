#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define f first
#define s second

struct node
{
	pii point;
	char ch;
};

bool comp(node a,node b)
{
	if(a.point.f<b.node.f||a.point.f==b.point.f&&a.point.s<b.point.s)
		return 1;
	return 0;
}

int arr[2][4];
int det(int a,int b,int c,int d)
{
	return a*d-b*c;
}

int direction(pii p1,pii p2,pii p3)
{
	return det(p2.first-p1.first,p2.second-p1.second,p3.first-p1.first,p3.second-p1.second);
}

bool OnSegment(pii p1,pii p2,pii p3)
{
	if(p3.first>=min(p1.first,p2.first)&&p3.first<=max(p1.first,p2.first)&&p3.second>=min(p1.second,p2.second)&&p3.second<=max(p1.second,p2.second))
	return true;
	return false;
}

int CheckIntersection(pii p1,pii p2,pii p3,pii p4)
{
	int d1,d2,d3,d4;
	d1=direction(p1,p2,p3);
	d2=direction(p1,p2,p4);
	d3=direction(p3,p4,p1);
	d4=direction(p3,p4,p2);
	
	if(((d1>0&&d2<0)||(d1<0&&d2>0))&&((d3>0&&d4<0)||(d3<0&&d4>0)))
		return true;
	else if(d1==0&&OnSegment(p1,p2,p3))
		return true;
	else if(d2==0&&OnSegment(p1,p2,p4))
		return true;
	else if(d3==0&&OnSegment(p3,p4,p1))
		return true;
	else if(d4==0&&OnSegment(p3,p4,p2))
		return true;
	return false;
}

int main()
{
	int n,j=0;
	cout<<endl<<"Enter the Total No. of Line Segments  :  ";	
	cin>>n;	
	map<pii,pii> mp1,mp2;
	vector<node> arr(2*n);
	cout<<endl<<"Enter the Line Segments  :  ";
	for(int i=0;i<n;i++)
	{
		cout<<endl<<"Segment"<<i+1<<" End Points  :  ";
		cin>>arr[j].point.f>>arr[j].point.s;
		arr[j].ch='s';
		j++;
	
		cin>>arr[j].point.f>>arr[j].point.s;
		arr[j].ch='e';
		mp1[arr[j-1].point]=arr[j].point;
		mp2[arr[j].point]=arr[j-1].point;
		j++;		
	}
	sort(arr.begin(),arr.end(),comp);
	set<node> st;
	set<node>::iterator it;
	for(int i=0;i<2*n;i++)
	{
		st.insert(arr[i]);
		it=st.find(arr[i]);
		if(arr[i].ch=='s')
		{
			if(it!=st.begin())
			{
				ans+=CheckIntersection(
}	
