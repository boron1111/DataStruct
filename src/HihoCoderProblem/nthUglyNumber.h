#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <math.h>
using namespace std;


//Accepted,动态规划,不是很懂，需要学习
#pragma once
class nthUglyNumber
{
public:
	nthUglyNumber(void);
	~nthUglyNumber(void);

	int minimal(int a, int b, int c);
	int nthUglyNumber1(int n);
	int isPrime(int n);
	void TestClass();
};

