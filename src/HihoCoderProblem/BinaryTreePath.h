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

#pragma once
class BinaryTreePath
{
public:
	BinaryTreePath(void);
	~BinaryTreePath(void);

	char** binaryTreePaths(struct TreeNode* root, int* returnSize) ;
	void TestClass();
};

