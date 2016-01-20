#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;

//Accepted,两个数字组合，比较大小和顺序
#pragma once
class LargestNumber
{
public:
	LargestNumber(void);
	~LargestNumber(void);

	 int isLarger(int num1,int num2);
	 string largestNumber(vector<int>& nums);
	 void TestClass();
};

