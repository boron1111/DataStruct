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

//需要将原始vector处理掉
#pragma once
class RemoveElement
{
public:
	RemoveElement(void);
	~RemoveElement(void);

	int removeElement(vector<int>& nums, int val);
	void FastSort(vector<int>& Array,int n,int l,int r);
	void TestClass();
};

