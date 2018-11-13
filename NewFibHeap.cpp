#include<bits/stdc++.h>
using namespace std;

struct node 
{
	int data,deg,mark;
	node *par,*child,*left,*right;	
};

map<int,node *> mp;
int tree=0;

node *create(int k)
{
	node *ptr=(node *)(malloc(sizeof(node)));
	ptr->data=k;
	ptr->deg=0;
	ptr->mark=0;
	ptr->par=ptr->child=NULL;
	ptr->left=ptr->right=ptr;
	return ptr;
}

node *concatenate(node *min1,node *min2)
{
	if(min1==NULL)
		return min2;
	node *x,*y;
	x=min1->left;
	y=min2->left;
	x->right=min2;
	min2->left=x;
	y->right=min1;
	min1->left=y;
	if(min1->data<min2->data)
		return min1;
	return min2;
}

void insert(node **min,int k)
{
	node *ptr=create(k);
	(*min)=concatenate(*min,ptr);
	mp[k]=ptr;
	tree++;
}

node * link(node *t1,node *t2)
{
	t2->par=t1;
	t2->left=t2->right=t2;
	t1->child=concatenate(t1->child,t2);
	t1->deg++;
	tree--;
	return t1;
}

void consolidate(node **min)
{
	node *ptr=(*min),*temp;
	if(ptr==NULL)
		return ;
	vector<node *> arr(100,NULL);
	int val=tree,d;
	while(val--)
	{
		d=ptr->deg;
		temp=ptr->right;
		ptr->left=ptr->right=ptr;
		while(arr[d]!=NULL)
		{
			if(arr[d]->data<ptr->data)
				ptr=link(arr[d],ptr);
			else ptr=link(ptr,arr[d]);
			arr[d]=NULL;
			d++;
		}
		arr[d]=ptr;
		ptr=temp;
	}
	(*min)=NULL;
	for(int i=0;i<100;i++)
		if(arr[i]!=NULL)
			(*min)=concatenate((*min),arr[i]);
}

void remove(node *ptr)
{
	ptr->left->right=ptr->right;
	ptr->right->left=ptr->left;
	ptr->left=ptr->right=NULL;
	mp.erase(ptr->data);
	tree--;
}

void LinkChild(node *ptr,node **min)
{
	if(ptr!=NULL)
	{
		node *save=ptr;
		while(true)
		{
			node *temp=ptr->right;
			ptr->par=NULL;
			ptr->left=ptr;
			ptr->right=ptr;
			(*min)=concatenate(*min,ptr);
			ptr=temp;
			tree++;
			if(ptr==save)
				break;
		}
	}
}
	
node * ExtractMin(node **min)
{
	node *ptr=(*min);
	if(ptr==NULL)
		return ptr;
	LinkChild(ptr->child,min);
	ptr->child=NULL;
	if(ptr->right==ptr)
		(*min)=NULL;
	else 
		(*min)=ptr->right;
	remove(ptr);
	consolidate(min);
	return ptr;
}

void cut(node **min,node *ptr)
{
	node *pa=ptr->par;
	pa->deg--;
	if(ptr->right==ptr)
		pa->child=NULL;
	else
		pa->child=ptr->right;
	ptr->left->right=ptr->right;
	ptr->right->left=ptr->left;
	ptr->left=ptr->right=ptr;
	ptr->mark=0;
	(*min)=concatenate(*min,ptr);
	tree++;
}

void cascading(node **min,node *ptr)
{
	node *pa=ptr->par;
	if(pa!=NULL)
	{
		if(pa->mark==0)
			pa->mark=1;
		else
		{
			cut(min,pa);
			cascading(min,pa);
		}
	}
}
		
void DecreaseKey(node **min,int x,int y)
{
	if(y>x||mp.find(x)==mp.end())
		return;
	else 
	{
		node *ptr=mp[x],*pa;
		mp.erase(x);
		mp[y]=ptr;
		ptr->data=y;
		pa=ptr->par;
		if(pa!=NULL&&ptr->data<pa->data)
		{
			cut(min,ptr);
			cascading(min,ptr);
		}
		if(y<(*min)->data)
			(*min)=ptr;
	}
}

void Delete(node **min,int x)
{
	if(mp.find(x)==mp.end())
		cout<<endl<<"ELEMENT NOT FOUND !!";
	else 
	{
		DecreaseKey(min,x,INT_MIN);
		mp[INT_MIN]=mp[x];
		mp.erase(x);
		ExtractMin(min);
	}
}

void print(node *root)
{
	if(root==NULL)
		return ;
	node *save=root;
	while(true)
	{
		cout<<"("<<root->data;
		print(root->child);
		root=root->right;
		cout<<")";
		if(root==save)
			break;
	}
}

int main()
{
	node *min=NULL;
	while(true)
	{
		cout<<"\n1.  INSERT\n2.  GET MINIMUM\n3.  EXTRACT MIN\n4.  DECREASE KEY\n5.  DELETE\n6.  PRINT\n7.  EXIT";
		int opt;
		cout<<endl<<"Enter Choice  :  ";
		cin>>opt;
		if(opt==1)
		{
			int x;
			cout<<"\nEnter value to Insert  :  ";
			cin>>x;
			insert(&min,x);
		}
		else if(opt==2)
		{
			if(min==NULL)
				cout<<endl<<"HEAP IS EMPTY !!";
			else 
				cout<<endl<<"Min Value is  :  "<<min->data;
		}
		else if(opt==3)
		{
			node *m=ExtractMin(&min);
			if(m==NULL)
				cout<<endl<<"HEAP IS EMPTY !!";
			else cout<<endl<<"Min Value is  :  "<<m->data;
		}
		else if(opt==4)
		{
			int x,y;
			cout<<endl<<"Enter Node value to Decrease  :  ";
			cin>>x;
			cout<<endl<<"Enter New value  :  ";
			cin>>y;
			DecreaseKey(&min,x,y);
		}
		else if(opt==5)
		{
			int x;
			cout<<endl<<"Enter Value to Delete  :  ";
			cin>>x;
			Delete(&min,x);
		}
		else if(opt==6)
		{
			cout<<"Contents of Fibonacci Heap are  :  ";
			print(min);
			cout<<endl;
		}
		else if(opt==7)
			break;
		else cout<<"\nINVALID INPUT !!";
	}
}		
