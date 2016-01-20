#include "StringToInteger.h"


StringToInteger::StringToInteger(void)
{
}


StringToInteger::~StringToInteger(void)
{
}

int StringToInteger::myAtoi(string str)
{
	int Len=str.size();
	int len_valid=Len,sum=0;
	int i,j,sign=1,pos_sign=0;
	i=0;
	while (str[i]<'0'||str[i]>'9')
	{
		len_valid--;
		if (str[i]=='0'||str[i]==' ')
		{
			i++;
			if (str[i]==0)
			{
				pos_sign++;
			}
		}
		else if (pos_sign==0&&(str[i]=='+'||str[i]=='-'))
		{
			cout<<"pos="<<pos_sign<<endl;
			if (str[0]=='+')
			{
				sign=1;
			}
			else if (str[0]=='-')
			{
				sign=-1;
			}
			else
				return 0;
			i++;
		}
		else
			return 0;
		
	}

	int temp=1;
	for (j=Len-1;j>=i;j--)
	{
		if (str[i]<'0'||str[i]>'9')
		{
			return 0;
		}
		else
		{
			sum+=(str[j]-'0')*temp;
			temp*=10;
		}
	}
	return sum*sign;
}
void StringToInteger::TestClass()
{
	cout<<myAtoi("  +123")+atoi("234")<<endl;
}