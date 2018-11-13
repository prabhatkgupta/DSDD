#include<bits/stdc++.h>
using namespace std;
#define vd vector<double> 
#define vi vector<int> 

bool flag;

vi LUP_Decomposition(vector<vd> coeff,vector<vd> &L,vector<vd> &U)
{
	int n=coeff.size();
	vector<int> P(n);
	for(int i=0;i<n;i++)
		P[i]=i;

	for(int k=0;k<n;k++)
	{
		double d=0,v;
		int storei;
		for(int i=k;i<n;i++)
		{
			v=coeff[i][k];
			if(coeff[i][k]<0)
				v=-v;
			if(v>d)
			{
				d=v;
				storei=i;
			}	
		}
		if(d==0)
		{
			cout<<"Error::Cannot Divide by Zero\n";
			flag=0;
			return P;
		}
		double temp;
		for(int i=0;i<n;i++)
		{
			swap(coeff[k][i],coeff[storei][i]);
		}
		swap(P[k],P[storei]);
		
		for(int i=k+1;i<n;i++)
		{
			coeff[i][k]/=coeff[k][k];
			for(int j=k+1;j<n;j++)
				coeff[i][j]-=coeff[i][k]*coeff[k][j];
		}
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(i>j)
				U[i][j]=coeff[i][j];
			else if(i<j)
				L[i][j]=coeff[i][j];
			else 
			{
				L[i][j]=1;
				U[i][j]=coeff[i][j];
			}
		}
	return P;
}		
		
vd LUP_Solve(vector<vd> &L,vector<vd> &U,vi &P,vd &b)
{
	int n=L.size();
	vd y(n),x(n);
	for(int i=0;i<n;i++)
	{	
		double sum=0;
		for(int j=0;j<i;j++)
			sum+=L[i][j]*y[j];
		y[i]=b[P[i]]-sum;
	}
	for(int i=n-1;i>=0;i--)
	{
		double sum=0;
		for(int j=i+1;j<n;j++)
			sum+=U[i][j]*x[j];
		x[i]=(y[i]-sum)/U[i][i];
	}
	return x;
}
		
int main()
{
	int var;
	flag=1;
	cout<<endl<<"Enter the No. of Variables  :  ";	
	cin>>var;
	vector<vd > coeff(var,vd(var)),L(var,vd(var)),U(var,vd(var));;
	vector<double> b(var);
	
	cout<<endl<<endl<<"Enter the Coefficient Matrix  :  \n";
	for(int i=0;i<var;i++)
	{
		for(int j=0;j<var;j++)
			cin>>coeff[i][j];
		cout<<endl;
	}
	cout<<endl<<"Enter the Resultant Matrix  :  \n";
	for(int i=0;i<var;i++)
		cin>>b[i];
	vi P=LUP_Decomposition(coeff,L,U);
	if(!flag)
	{
		cout<<endl<<"ANSWER CANNOT BE COMPUTED!!";
		return 0;
	}
	vd ans=LUP_Solve(L,U,P,b);
	for(int i=0;i<var;i++)
		cout<<"x"<<i+1<<"="<<ans[i]<<endl;
}
