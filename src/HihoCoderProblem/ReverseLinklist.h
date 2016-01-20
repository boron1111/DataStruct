#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <string>
#include "DataStructDefine.h"
using namespace std;

//Accepted,注意空链和单元素链表的特殊处理
#pragma once
class ReverseLinklist
{
public:
	ReverseLinklist(void);
	~ReverseLinklist(void);

	ListNode* reverseList(ListNode* head);
	void TestClass();
};

