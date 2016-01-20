#include "WordPattern.h"


WordPattern::WordPattern(void)
{
}


WordPattern::~WordPattern(void)
{
}

void WordPattern::TestClass()
{
	bool res=wordPattern("baab","dog cat cat fish");
	cout<<res<<endl;
}

bool WordPattern::wordPattern(string pattern,string str)
{
	//case of empty string
	if (pattern.empty())
	{
		if (str.empty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int lenP=pattern.length();
	int lenS=str.length();
	int blankNum=0;
	char blank[]=" ";

	char *temp=new char[lenS+2];
	for (int i=0;i<lenS;i++)
	{
		temp[i]=str[i];
		if (str[i]==blank[0])
		{
			blankNum++;
		}
	}

	//case of number not match
	if (blankNum!=lenP-1)
	{
		return false;
	}

	//case of single string,no blank
	if (blankNum==0&&lenP==1)
	{
		return true;
	}

	temp[lenS]=blank[0];
	string *strs=new string[lenP];
	
	char *tokenPtr=strtok(temp," ");
	
	int k=0;
	while(tokenPtr!=NULL)
	{
		//cout<<tokenPtr<<endl;
		strs[k]=string(tokenPtr);
		//cout<<strs[k]<<endl;
		k++;
		if (k==lenP)
		{
			break;
		}
		tokenPtr=strtok(NULL," ");
	}

	for (int i=0;i<lenP;i++)
	{
		for (int j=0;j<lenP;j++)
		{
			if (pattern[i]==pattern[j])
			{
				if (strs[i]==strs[j])
				{
					continue;
				}
				else
				{
					return false;
				}
			}
			else
			{
				if (strs[i]!=strs[j])
				{
					continue;
				}
				else
				{
					return false;
				}
			}
		}
	}

	if (strs!=NULL)
	{
		delete[] strs;
	}
	if (temp!=NULL)
	{
		delete[] temp;
	}
	return true;
}
