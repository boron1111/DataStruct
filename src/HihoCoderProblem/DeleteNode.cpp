#include "DeleteNode.h"


DeleteNode::DeleteNode(void)
{
}


DeleteNode::~DeleteNode(void)
{
}
//ֻ�е�ǰ�ڵ����룬���ܳ������
//���Խ���ǰ�ڵ㸳ֵΪ��һ���ڵ㣬Ȼ��ɾ����һ���ڵ㣬�ﵽͬ����Ч��
void DeleteNode::deleteNode(ListNode* node)
{
	if (node->next==NULL)
	{
		return;
	}

	ListNode *temp;
	temp=node->next;
	node->val=temp->val;
	node->next=temp->next;

	free(temp);
}

void DeleteNode::TestClass()
{
	ListNode *head,*p;
	head=(ListNode*)malloc(sizeof(ListNode));

	int Arr[]={1,2,3,4,5};
	head->val=Arr[0];

	p=head;
	p->next=NULL;
	for (int i=1;i<5;i++)
	{
		ListNode *res;
		res=(ListNode*)malloc(sizeof(ListNode));
		res->val=Arr[i];
		res->next=NULL;
		p->next=res;
		p=p->next;
	}
	
	p=head;
	for (int i=1;i<5;i++)
	{
		p=p->next;
		if (i==3)
		{
			deleteNode(p);
		}
	}

	p=head;
	while(p!=NULL)
	{
		cout<<p->val<<endl;
		p=p->next;
	}
}