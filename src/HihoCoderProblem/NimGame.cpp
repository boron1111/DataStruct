#include "NimGame.h"


NimGame::NimGame(void)
{
}


NimGame::~NimGame(void)
{
}

bool NimGame::canWinNim(int n)
{
	if (n%4>0)
		return 1;
	else
		return 0;
}

void NimGame::TestClass()
{
	cout<<"First Win="<<canWinNim(7)<<endl;
}