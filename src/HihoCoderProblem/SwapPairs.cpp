#include "SwapPairs.h"


SwapPairs::SwapPairs(void)
{
}


SwapPairs::~SwapPairs(void)
{
}

ListNode* SwapPairs::swapPairs(ListNode* head)
{
	if (head==NULL||head->next==NULL)
	{
		return head;
	}

	ListNode *p,*q,*parent;
	p=head;q=p->next;
	head=q;parent=NULL;
	while(p!=NULL&&q!=NULL)
	{
		cout<<p->val<<","<<q->val<<endl;
		p->next=q->next;
		q->next=p;
		if (parent==NULL)
		{
			parent=p;
			head=q;
		}
		else
		{
			parent->next=q;
			parent=p;
		}
		p=p->next;
		
		if (p==NULL)
		{
			break;
		}
		q=p->next;
	}

	p=head;
	return head;
}
void SwapPairs::TestClass()
{
	ListNode *l1;
	l1=(ListNode*)malloc(sizeof(ListNode));

	int A1[4]={1,2,3,4};
	l1->val=A1[0];
	l1->next=NULL;

	ListNode *p;p=l1;
	for (int i=1;i<4;i++)
	{
		ListNode *res;
		res=(ListNode*)malloc(sizeof(ListNode));
		res->val=A1[i];
		res->next=NULL;
		p->next=res;
		p=p->next;
	}
	ListNode* res=swapPairs(l1);
	p=res;
	while (p!=NULL)
	{
		cout<<p->val<<endl;
		p=p->next;
	}
}