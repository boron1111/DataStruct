#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#include <stdlib.h>
using namespace std;

#pragma once
//Accepted
struct ListNode {
     int val;
	 ListNode *next;
	 ListNode(int x) : val(x), next(NULL) {}
 };

class AddTwoNumbers
{
public:
	AddTwoNumbers(void);
	~AddTwoNumbers(void);

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
	void TestClass();
};

