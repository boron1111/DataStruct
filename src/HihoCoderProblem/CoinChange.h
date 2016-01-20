#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <string>
#include<limits.h>
#include <cmath>
using namespace std;

//Accepted,动态规划问题，注意的是转移条件以及初始化条件
#pragma once
class CoinChange
{
public:
	CoinChange(void);
	~CoinChange(void);

	int coinChange(vector<int>& coins, int amount);
	void TestClass();
};

