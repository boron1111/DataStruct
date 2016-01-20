#include "StackUseQueue.h"


StackUseQueue::StackUseQueue(void)
{
}


StackUseQueue::~StackUseQueue(void)
{
}

void StackUseQueue::TestClass()
{
	cout<<"Empty="<<empty()<<endl;
	for (int i=0;i<10;i++)
	{
		push(i+1);
		cout<<"top="<<top()<<endl;
	}
	for (int i=0;i<10;i++)
	{
		cout<<top()<<endl;
		pop();
	}
}