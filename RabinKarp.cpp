#include<bits/stdc++.h>
using namespace std;

void Matching(string &p,string &t)
{
	int n,m,mod=599,s_val,p_val,h=1;
	n=t.length();
	m=p.length();
	s_val=p_val=0;
	for(int i=0;i<m;i++)
	{	
		if(i!=0)
			h=(h*26)%mod;
		s_val=(s_val*26+t[i])%mod;
		p_val=(p_val*26+p[i])%mod;
	}
	cout<<endl;
	for(int i=0;i<=n-m;i++)
	{
		if(s_val==p_val)
		{
			bool flag=1;
			for(int j=0;j<m;j++)
				if(p[j]!=t[i+j])
					flag=0;
			if(flag)
				cout<<"PATTERN FOUND AT INDEX = "<<i<<endl;
		}
		if(i<n-m)			
			s_val=(((s_val-h*t[i])%mod+mod)*26+t[i+m])%mod;
	}
}

int main()
{
	string p,t;
	cout<<endl<<"ENTER THE TEXT  :  ";
	cin>>t;
	cout<<endl<<"ENTER THE PATTERN  :  ";
	cin>>p;
	Matching(p,t);
}
