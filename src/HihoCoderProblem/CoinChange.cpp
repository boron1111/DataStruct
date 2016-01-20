#include "CoinChange.h"


CoinChange::CoinChange(void)
{
}


CoinChange::~CoinChange(void)
{
}


int CoinChange::coinChange(vector<int>& coins, int amount)
{
	int i,j;

	int len=coins.size();
	if(len==0) return -1;

	int *Res=new int[amount+1];
	//memset(Res,1000,sizeof(Res)*(amount+1));


	for (i=0;i<amount+1;i++)
	{
		Res[i]=0x7ffffffe;
	}
	Res[0]=0;
	for (i=0;i<amount+1;i++)
	{
		for (j=0;j<len;j++)
		{
			if (i+coins[j]<amount+1)
			{
				Res[i+coins[j]]=Res[i+coins[j]]< Res[i]+1 ? Res[i+coins[j]]:Res[i]+1;
			}
		}
	}

	int ans=Res[amount];
	if (Res!=NULL)
	{
		delete[] Res;
	}
	return ans==0x7ffffffe? -1:ans;
}

void CoinChange::TestClass()
{
	int coins[3]={1,5,2};
	int amount=11;

	vector<int> CoinV(coins,coins+3);

	int res=coinChange(CoinV,amount);
	cout<<"result="<<res<<endl;
}