#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x,n,mod,save,ans=1,cnt=0;
	vector<bool> v;
	
	cout<<endl<<"ENTER THE VALUE OF EXPONENT  :  ";
	cin>>x;
	cout<<endl<<"ENTER THE VALUE OF POWER  :  ";
	cin>>n;
	cout<<endl<<"ENTER THE VALUE OF MODULUS  :  ";
	cin>>mod;
	save=n;
	cout<<endl<<"INTERMEDIATE VALUES ARE  :  ";

	while(save)
	{
		cnt++;
		v.push_back(save%2);
		save>>=1;	
	}
	for(int i=cnt-1;i>=0;i--)
	{
		ans=(ans*ans)%mod;
		if(v[i]==1)
			ans=(ans*x)%mod;
		cout<<ans<<" ";	
	}
	cout<<endl<<"ANSWER GENERATED IS  :  "<<ans<<endl;
}
