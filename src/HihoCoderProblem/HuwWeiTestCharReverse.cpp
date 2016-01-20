#include "HuwWeiTestCharReverse.h"


HuwWeiTestCharReverse::HuwWeiTestCharReverse(void)
{
}


HuwWeiTestCharReverse::~HuwWeiTestCharReverse(void)
{
}

string HuwWeiTestCharReverse::ReverseCharacter(string &strs)
{
	int Len=strs.size();

	for (int i=0;i<Len;i++)
	{
		if (strs[i]>='a'&&strs[i]<='z')
		{
			strs[i]=(strs[i]+1-'a') % 26+'a';
		}
		else if (strs[i]>='A'&&strs[i]<='Z')
		{
			strs[i]=(strs[i]+1-'a') % 26+'a';
		}
	}
	return strs;
}


void HuwWeiTestCharReverse::TestClass()
{
	string strs="qaz123@THIS";
	cout<<strs<<endl;
	string str_new=ReverseCharacter(strs);
	cout<<str_new<<endl;
}