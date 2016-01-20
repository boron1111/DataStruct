#include "AddTwoNumbers.h"


AddTwoNumbers::AddTwoNumbers(void)
{
}


AddTwoNumbers::~AddTwoNumbers(void)
{
}

ListNode* AddTwoNumbers::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	//int m=0,n=0;
	ListNode *p,*q,*s,*head;
	p=l1;q=l2;
	//while(p!=NULL)
	//{
	//	m++;
	//	p=p->next;
	//}
	//while(q!=NULL)
	//{
	//	n++;
	//	q=q->next;			
	//}	
	
	p=l1;q=l2;s=NULL;
	int temp;
	int next=0;
	while (p!=NULL&&q!=NULL)
	{
		ListNode *res;
		res=(ListNode*)malloc(sizeof(ListNode));
		temp=p->val+q->val+next;
		p=p->next;//update with p,q
		q=q->next;
		if (temp>9)
		{
			res->val=temp%10;
			next=1;
		}
		else
		{
			res->val=temp%10;
			next=0;
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
			s=s->next;//s update
		}
	}

	while(p!=NULL)
	{
		ListNode *res;
		res=(ListNode*)malloc(sizeof(ListNode));
		temp=p->val+next;
		p=p->next;//update with p

		if (temp>9)
		{
			res->val=temp%10;
			next=1;
		}
		else
		{
			res->val=temp%10;
			next=0;
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

	while(q!=NULL)
	{
		ListNode *res;
		res=(ListNode*)malloc(sizeof(ListNode));
		temp=q->val+next;
		q=q->next;//update with q
		if (temp>9)
		{
			res->val=temp%10;
			next=1;
		}
		else
		{
			res->val=temp%10;
			next=0;
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

	if (next==1)//The last extra 1;
	{
		ListNode *res;
		res=(ListNode*)malloc(sizeof(ListNode));
		res->val=1;
		res->next=NULL;
		s->next=res;
	}
	s=head;
	while (s!=NULL)
	{
		cout<<s->val<<endl;
		s=s->next;
	}

	return head;
}

void AddTwoNumbers::TestClass()
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
	addTwoNumbers(l1,l2);
}