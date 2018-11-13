#include<bits/stdc++.h>
using namespace std;
struct node
{
	int data,deg;
	node *par,*sib,*child;
};
node *getnode(int key)
{
	node *ptr=new node;
	ptr->data=key;
	ptr->deg=0;
	ptr->par=ptr->sib=ptr->lchild=NULL;
	return node;
}
void insertLast(node **last,node *ptr)
{
	if((*last)==NULL)
		(*last)=ptr;
	else 
	{
		(*last)->sib=ptr;
		(*last)=ptr;
	}
}
node *merge(node *root1,node *root2)
{
	if(root1==NULL)
		return root2;
	if(root2==NULL)
		return root1;
	node *head=NULL,*last=NULL;
	while(root1!=NULL&&root2!=NULL)
	{
		if(root1->deg<root2->deg)
		{
			insertLast(&last,root1);
			root1=root1->sib;
		}
		else 
		{
			insertLast(&last,root2);
			root2=root2->sib;
		}
		if(head==NULL)
			head=last;
	}
	while(root1!=NULL)
	{
		insertLast(&last,root1);
		root1=root1->sib;
	}
	while(root2!=NULL)
	{
		insertLast(&last,root2);
		root2=root2->sib;
	}
	return head;
}
void link(node *ptr,node *next)
{
	next->sib=ptr->child;
	next->par=ptr;
	ptr->deg++;
	ptr->child=next;
}
node *Union(node *root1,node *root2)
{
	node *root=merge(root1,root2);
	node *ptr=root,*next=root->sib,*prev=NULL;
	while(next!=NULL)
	{
		if(ptr->deg!=next->deg||next->sib!=NULL&&next->sib->deg==ptr->deg)
		{
			prev=ptr;
			ptr=next;
		}	
		else 
		{
			if(ptr->data<=next->data)
			{
				ptr->sib=next->sib;
				link(ptr,next);
			}
			else 
			{
				if(prev==NULL)
					head=next;
				else 	
				
		next=ptr->sib;
	}
	
	
int main()
{
	
