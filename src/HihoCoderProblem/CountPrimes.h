#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <string>
#include<limits.h>
using namespace std;

//Accepted, 注意分析效率提升的点，注意数学推导
#pragma once
class CountPrimes
{
public:
	CountPrimes(void);
	~CountPrimes(void);

	int isPrime(int n);
	int countPrimes(int n);
	void TestClass();
};

