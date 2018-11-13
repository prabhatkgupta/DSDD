#include<bits/stdc++.h>
using namespace std;
typedef complex<double> cd;
#define pi 3.1415926535
#define pb push_back

vector<cd> Recursive_FFT(vector<int> &a)
{
	int n=a.size();
	if(n==1)
	{
		vector<cd> t(1,a[0]);
		return t;
	}
	vector<cd> w(n);
	for(int i=0;i<n;i++)
	{
		double d=(2*pi*i)/n;
		w[i]=cd(cos(d),sin(d));
	}
	vector<int> A1,A2;
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
			A1.pb(a[i]);
		else A2.pb(a[i]);
	}
	vector<cd> Y(n),Y1,Y2;
	Y1=Recursive_FFT(A1);
	Y2=Recursive_FFT(A2);
	for(int i=0;i<n/2;i++)
	{
		if(i<Y1.size())
			Y[i]=Y1[i]+w[i]*Y2[i];
		if(i<Y2.size())
			Y[i+n/2]=Y1[i]-w[i]*Y2[i];
	}
	return Y;
}
			

int main()
{
	int n;
	cout<<endl<<"Enter the Degree of the Polynomial  :  ";
	cin>>n;
	cout<<endl<<"Enter the Coefficient  :  ";
	vector<int> coeff(n+1);
	for(int i=0;i<=n;i++)
	{
		cout<<endl<<"Enter Coefficient of x^"<<i<<"  :  ";
		cin>>coeff[i];
	}
	vector<cd> ans=Recursive_FFT(coeff);
	cout<<endl<<endl;
	for(int i=0;i<=n;i++)
	{
		cout<<"Y"<<i<<" = "<<real(ans[i])<<"+"<<imag(ans[i])<<"i"<<endl;
	}
}
