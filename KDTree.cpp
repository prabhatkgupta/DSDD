#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int> 
#define f first
#define s second

struct node
{
	pii data;
	node *left,*right;
};

node *create(pii p)
{
	node *ptr=new node;
	ptr->data=p;
	ptr->left=ptr->right=NULL;
	return ptr;
}

node* insert(node *root,pii p,int depth)
{
	if(root==NULL)
		return create(p);
	if(depth%2==1)
	{
		if(root->data.s>=p.s)
			root->left=insert(root->left,p,depth+1);
		else root->right=insert(root->right,p,depth+1);
	}
	else 
	{
		if(root->data.f>=p.f)
			root->left=insert(root->left,p,depth+1);
		else root->right=insert(root->right,p,depth+1);
	}
	return root;
}

bool Search(node *root,pii p,int depth)
{
	if(root==NULL)
		return 0;
	if(root->data==p)
		return 1;
	else
	{
		if(depth%2==1)
		{
			if(p.s<=root->data.s)
				return Search(root->left,p,depth+1);
			else return Search(root->right,p,depth+1);
		}
		else 
		{
			if(p.f<=root->data.f)
				return Search(root->left,p,depth+1);			
			else return Search(root->right,p,depth+1);
		}
	}
}

int main()
{
	node *root=NULL;
	int n,ch;
	bool ans;
	cout<<endl<<"Enter the No. of Data Points  :  ";
	cin>>n;
	pii arr[n],p;
	cout<<endl<<"Enter the Data Points in Plane  :  \n";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i].f>>arr[i].s;
		root=insert(root,arr[i],0);
	}	
	while(1)
	{
		cout<<endl<<"Enter Data Points to Search  :  ";
		cin>>p.f>>p.s;
		ans=Search(root,p,0);
		if(ans)
			cout<<"Data Found!!";
		else cout<<"Data Not Found!!";
		cout<<endl<<"Enter 1 to Exit  :  ";
		cin>>ch;
		if(ch==1)
			break;
	}
}
