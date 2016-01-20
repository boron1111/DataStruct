#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

#pragma once
class StackUseQueue
{
public:
	StackUseQueue(void);
	~StackUseQueue(void);
	void TestClass();

	// Push element x onto stack.
	void push(int x) {
		q1.push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		int len=q1.size();
		int temp;
		for (int i=0;i<len-1;i++)
		{
			temp=q1.front();
			q2.push(temp);
			q1.pop();
		}
		q1.pop();
		for (int i=0;i<len-1;i++)
		{
			temp=q2.front();
			q1.push(temp);
			q2.pop();
		}
	}

	// Get the top element.
	int top() {
		int len=q1.size();
		int temp,temp2;
		for (int i=0;i<len;i++)
		{
			temp=q1.front();
			q2.push(temp);
			q1.pop();
		}
		for (int i=0;i<len;i++)
		{
			temp2=q2.front();
			q1.push(temp2);
			q2.pop();
		}
		return temp;
	}

	// Return whether the stack is empty.
	bool empty() {
		return q1.empty();
	}
private:
	queue<int> q1;
	queue<int> q2;
};

