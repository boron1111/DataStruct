#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;

#pragma once
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
 
class MergeTwoSortedLists
{
public:
	MergeTwoSortedLists(void);
	~MergeTwoSortedLists(void);
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
	void TestClass();
};

