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

//Accepted,��̬�滮��
#pragma once
class EditDistance
{
public:
	EditDistance(void);
	~EditDistance(void);

	int Min(int a,int b);
	int minDistance(string word1, string word2);
	void TestClass();
};

