#include "CountAndSay.h"


CountAndSay::CountAndSay(void)
{
}


CountAndSay::~CountAndSay(void)
{
}

string CountAndSay::num2str(int n)
{
	string str;
	int len=0;
	int temp=n;
	int base=1;
	while(temp >0)
	{
		str+=temp % 10+'0';
		temp=temp/10;
		len++;
	}

	for (int i=0;i<len/2;i++)
	{
		char temp=str[i];
		str[i]=str[len-1-i];
		str[len-1-i]=temp;
	}

	return str;
}

string CountAndSay::countAndSay(int n)
{
	int i;
	string str=num2str(n);
	int len=str.size();

	if (len==0)
	{
		return "";
	}


	char c_current='a';
	int num=0;
	string result="";

	for (i=0;i<len;i++)
	{
		if (str[i]!=c_current)
		{
			if (c_current>='0'&&c_current<='9'&&num>0)
			{
				result+=(num-0)+'0';
				result+=c_current;
			}
			c_current=str[i];
			num=1;
		}
		else
		{
			num++;
		}

		if (i==len-1)
		{
			result+=(num-0)+'0';
			result+=c_current;
		}
	}
	return result;
}

void CountAndSay::TestClass()
{
	cout<<"the result is="<<endl;
	cout<<countAndSay(111221)<<endl;
}