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

//Accepted,��̬�滮���⣬ע�����ת�������Լ���ʼ������
#pragma once
class CoinChange
{
public:
	CoinChange(void);
	~CoinChange(void);

	int coinChange(vector<int>& coins, int amount);
	void TestClass();
};

