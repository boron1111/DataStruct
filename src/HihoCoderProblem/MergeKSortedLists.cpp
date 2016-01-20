#include "MergeKSortedLists.h"


MergeKSortedLists::MergeKSortedLists(void)
{
}


MergeKSortedLists::~MergeKSortedLists(void)
{
}

ListNode* MergeKSortedLists::mergeKLists(vector<ListNode*>& lists)
{
	ListNode **p,*head,*s;
	int Len=lists.size();
	if (Len==0){
		return NULL;
	}

	int i,j;//flag is the status of all zeros
	p=new ListNode *[Len];
	for (i=0;i<Len;i++)
	{
		p[i]=lists[i];
	}

	head=NULL;s=NULL;

	while(1)
	{	
		int minv=10000000,pos=-1;
		for (i=0;i<Len;i++)
		{
			if (p[i]==NULL)
			{
				continue;
			}
			else if (pos==-1)
			{
				minv=p[i]->val;
				pos=i;
			}
			else if (p[i]->val<minv)
			{
				minv=p[i]->val;
				pos=i;
			}
		}

		if (pos==-1)
		{
			if (s!=NULL)
			{
				s->next=NULL;
			}
			break;
		}

		if (s==NULL)
		{
			s=p[pos];
			head=s;
		}
		else
		{
			s->next=p[pos];
			s=s->next;
		}
		p[pos]=p[pos]->next;
	}

	/*while(1)
	{	
		int minv=10000000,pos=-1;
		for (i=0;i<Len;i++)
		{
			if (lists[i]==NULL)
			{
				continue;
			}
			else if (pos==-1)
			{
				minv=lists[i]->val;
				pos=i;
			}
			else if (lists[i]->val<minv)
			{
				minv=lists[i]->val;
				pos=i;
			}
		}
		if (pos==-1)
		{
			if (s!=NULL)
			{
				s->next=NULL;
			}
			break;
		}
		
		if (s==NULL)
		{
			s=lists[pos];
			head=s;
		}
		else
		{
			s->next=lists[pos];
			s=s->next;
		}
		lists[pos]=lists[pos]->next;
	}*/

	return head;
}

void MergeKSortedLists::TestClass()
{
	ListNode *l1=NULL;
	ListNode *l2=NULL;
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

	vector<ListNode*> lists(2);
	lists[0]=l1;
	lists[1]=l2;
	ListNode *res=mergeKLists(lists);
	p=res;
	while(p!=NULL)
	{
		cout<<p->val<<endl;
		p=p->next;
	}
}