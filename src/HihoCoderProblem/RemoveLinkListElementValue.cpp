#include "RemoveLinkListElementValue.h"


RemoveLinkListElementValue::RemoveLinkListElementValue(void)
{
}


RemoveLinkListElementValue::~RemoveLinkListElementValue(void)
{
}

ListNode* RemoveLinkListElementValue::removeElements(ListNode* head, int val)
{
	ListNode *p,*father,*temp;

	p=head;
	if (p==NULL)
	{
		return NULL;
	}

	father=head;//When first node is deleted,change the first and judge again
	while (father!=NULL&&father->val==val)
	{
		temp=father;
		father=father->next;
		head=father;
		free(temp);
	}
	if (father==NULL)
	{
		return NULL;
	}
	p=father->next;

	//Judge the case when first is not the value and the linknode is not the tail
	while(p!=NULL)
	{
		if (p->val==val)
		{
			temp=p;
			father->next=p->next;
			p=father->next;
			free(temp);
			//return head;//注意，多个元素相同，也需要继续删除
		}
		else
		{
			father=p;
			p=father->next;
		}
	}

	return head;
}

void RemoveLinkListElementValue::TestClass()
{
	ListNode *head,*p;
	head=(ListNode*)malloc(sizeof(ListNode));

	int Arr[]={1,1,1,1,2};//{1,2,3,4,5};
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

	

	p=removeElements(head,1);
	while(p!=NULL)
	{
		cout<<p->val<<endl;
		p=p->next;
	}
}