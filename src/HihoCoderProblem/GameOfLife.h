#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <math.h>
using namespace std;

#pragma once
class GameOfLife
{
public:
	GameOfLife(void);
	~GameOfLife(void);

	void gameOfLife(vector<vector<int>>& board);
};

