#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;
//time exceeded
#pragma once	
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class MergeKSortedLists
{
public:
	MergeKSortedLists(void);
	~MergeKSortedLists(void);
	 ListNode* mergeKLists(vector<ListNode*>& lists);
	 void TestClass();
private:

};

