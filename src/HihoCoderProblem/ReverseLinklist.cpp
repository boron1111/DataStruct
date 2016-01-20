#include "ReverseLinklist.h"


ReverseLinklist::ReverseLinklist(void)
{

}


ReverseLinklist::~ReverseLinklist(void)
{
}

ListNode* ReverseLinklist::reverseList(ListNode* head)
{
	if (head==NULL)
	{
		return NULL;
	}
	ListNode *p,*q,*temp;
	p=head;
	q=p->next;
	p->next=NULL;

	if (q==NULL)
	{
		return p;
	}

	while (q->next!=NULL)
	{
		temp=q->next;
		q->next=p;
		p=q;
		q=temp;
	}
	q->next=p;
	head=q;
	return head;
}

void ReverseLinklist::TestClass()
{
	ListNode *head,*p;
	head=(ListNode*)malloc(sizeof(ListNode));

	int Arr[]={1,2,3,4,5};
	head->val=Arr[0];

	p=head;
	p->next=NULL;
	for (int i=1;i<1;i++)
	{
		ListNode *res;
		res=(ListNode*)malloc(sizeof(ListNode));
		res->val=Arr[i];
		res->next=NULL;
		p->next=res;
		p=p->next;
	}
	p=reverseList(head);

	while(p!=NULL)
	{
		cout<<p->val<<endl;
		p=p->next;
	}
}