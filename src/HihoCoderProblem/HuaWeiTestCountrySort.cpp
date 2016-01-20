#include "HuaWeiTestCountrySort.h"


HuaWeiTestCountrySort::HuaWeiTestCountrySort(void)
{
}


HuaWeiTestCountrySort::~HuaWeiTestCountrySort(void)
{
}

int HuaWeiTestCountrySort::CompareString(string str1,string str2)
{
	int len1=str1.size();
	int len2=str2.size();

	int i=0;
	while(i<len1 && i<len2)
	{
		if (str1[i]<str2[i])
		{
			return 1;//sort first
		}
		else if (str1[i]>str2[i])
		{
			return -1;
		}
		else
		{
			i++;
		}
	}
	if (i==len1&&i==len2)
	{
		return 0;
	}

	if (i==len1 && i<len2)
	{
		return 1;
	}
	if (i<len1&&i==len2)
	{
		return -1;
	}
}

void HuaWeiTestCountrySort::CountrySort(string strs[],int Num)
{
	int i,j;

	for(i=0;i<Num;i++)
	{
		for (j=0;j<Num-1-i;j++)
		{
			if (CompareString(strs[j],strs[j+1])<0)
			{
				string temp=strs[j];
				strs[j]=strs[j+1];
				strs[j+1]=temp;
			}
		}
	}
}

void HuaWeiTestCountrySort::TestClass()
{
	int len=5;
	string *strs=new string[len];
	strs[0]="CHINA";
	strs[1]="AMERICA";
	strs[2]="AUSTRALIA";
	strs[3]="FRANCE";
	strs[4]="GERMAN";

	for (int i=0;i<len;i++)
	{
		cout<<strs[i]<<endl;
	}

	CountrySort(strs,len);
	cout<<"after sort"<<endl;
	for (int i=0;i<len;i++)
	{
		cout<<strs[i]<<endl;
	}
	
	if (strs!=NULL)
	{
		delete[] strs;
	}
}