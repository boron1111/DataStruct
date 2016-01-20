#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;

//Accepted
#pragma once
class H_Index
{
public:
	H_Index(void);
	~H_Index(void);
	
	int hIndex(vector<int>& citations);
	void FastSort(int * citations,int l,int r);
	void TestClass();
};

