#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;

//Accepted, �����Ͻǿ�ʼ����Ŀ��С��i++,��Ŀ�����J--;
#pragma once
class Search2DMatrix
{
public:
	Search2DMatrix(void);
	~Search2DMatrix(void);

	bool searchMatrix(vector<vector<int>>& matrix, int target);
	void TestClass();
};

