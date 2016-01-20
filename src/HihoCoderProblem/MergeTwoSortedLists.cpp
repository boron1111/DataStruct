#include "MergeTwoSortedLists.h"


MergeTwoSortedLists::MergeTwoSortedLists(void)
{
}


MergeTwoSortedLists::~MergeTwoSortedLists(void)
{
}

ListNode* MergeTwoSortedLists::mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode *p,*q,*head,*s;
	p=l1;
	q=l2;

	head=NULL;
	s=NULL;
	while(p!=NULL&&q!=NULL)
	{	
		ListNode *res;
		res=(ListNode *)malloc(sizeof(ListNode));
		if (p->val<q->val)
		{
			res->val=p->val;
			p=p->next;
		}
		else
		{
			res->val=q->val;
			q=q->next;
		}
		res->next=NULL;

		if (s==NULL)
		{
			s=res;
			head=s;
		}
		else
		{
			s->next=res;
			s=s->next;
		}
	}

	while(p!=NULL)
	{
		ListNode *res;
		res=(ListNode *)malloc(sizeof(ListNode));
		res->val=p->val;
		res->next=NULL;
		p=p->next;

		if (s==NULL)
		{
			s=res;
			head=s;
		}
		else
		{
			s->next=res;
			s=s->next;
		}
	}

	while(q!=NULL)
	{
		ListNode *res;
		res=(ListNode *)malloc(sizeof(ListNode));
		res->val=q->val;
		res->next=NULL;
		q=q->next;

		if (s==NULL)
		{
			s=res;
			head=s;
		}
		else
		{
			s->next=res;
			s=s->next;
		}
	}
	return head;
}

void MergeTwoSortedLists::TestClass()
{
	ListNode *l1;
	ListNode *l2;
	l1=(ListNode*)malloc(sizeof(ListNode));
	l2=(ListNode*)malloc(sizeof(ListNode));

	int A1[3]={2,4,9};
	int A2[3]={5,6,4};
	l1->val=A1[0];
	l2->val=A2[0];
	l1->next=NULL;
	l2->next=NULL;

	ListNode *p,*q;
	p=l1;q=l2;
	for (int i=1;i<3;i++)
	{
		ListNode *res;
		res=(ListNode*)malloc(sizeof(ListNode));
		res->val=A1[i];
		res->next=NULL;
		p->next=res;
		p=p->next;
	}
	for(int i=1;i<2;i++)
	{
		ListNode *res2;
		res2=(ListNode*)malloc(sizeof(ListNode));
		res2->val=A2[i];
		res2->next=NULL;
		q->next=res2;
		q=q->next;
	}

	p=l1;q=l2;
	ListNode *res=mergeTwoLists(l1,l2);
	p=res;
	while(p!=NULL)
	{
		cout<<p->val<<endl;
		p=p->next;
	}

}