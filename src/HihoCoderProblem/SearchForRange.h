#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <string>
#include<limits.h>
using namespace std;

#pragma once
class SearchForRange
{
public:
	SearchForRange(void);
	~SearchForRange(void);

	vector<int> searchRange(vector<int>& nums, int target);
	int BinarySearch(vector<int>& nums, int target);

	void TestClass();
};

