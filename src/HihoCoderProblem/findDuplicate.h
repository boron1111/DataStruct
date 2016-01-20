#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;

//Accepted
#pragma once
class FindDuplicate
{
public:
	FindDuplicate(void);
	~FindDuplicate(void);
	int findDuplicate(vector<int>& nums);
	void TestClass();
	void FastSort(vector<int>& Array,int n,int l,int r);
};

