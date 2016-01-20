#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <string>
#include<limits.h>
#include "DataStructDefine.h"
using namespace std;

//Accepted
#pragma once
class SearchIndexNumber
{
public:
	SearchIndexNumber(void);
	~SearchIndexNumber(void);

	int searchInsert(vector<int>& nums, int target);
	void TestClass();
};

