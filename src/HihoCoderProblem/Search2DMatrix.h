#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;

//Accepted, 从右上角开始，比目标小则i++,比目标大则J--;
#pragma once
class Search2DMatrix
{
public:
	Search2DMatrix(void);
	~Search2DMatrix(void);

	bool searchMatrix(vector<vector<int>>& matrix, int target);
	void TestClass();
};

