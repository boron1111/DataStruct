#include "NumberofDigit.h"


NumberofDigit::NumberofDigit(void)
{
	
}


NumberofDigit::~NumberofDigit(void)
{
}

void NumberofDigit::TestClass()
{
	cout<<countDigitOne(13000000)<<endl;
}

int NumberofDigit::countDigitOne(int n)
{
	int i;
	int sum=0;
	for (i=1;i<=n;i++)
	{
		sum+=countSingleOne(i);
	}
	return sum;
}

int NumberofDigit::countSingleOne(int i)
{
	int temp=i;
	int sum=0;
	if (i<10)
	{
		if (i==1){sum++;}
	}
	else
	{
		temp=i;
		if (temp%10==1)
		{
			sum++;
		}
		while (temp>0)
		{
			temp=temp/10;
			if (temp%10==1)
			{
				sum++;
			}
		}
	}
	/*else
	{
		int temp;
		int first,last;
		first=i/10;
		last=i%10;
		if (Record2[first]!=-1)
		{
			sum+=Record2[first];
		}
		else
		{
			temp=first;
			if (temp%10==1)
			{
				sum++;
			}
			while (temp>0)
			{
				temp=temp/10;
				if (temp%10==1)
				{
					sum++;
				}
			}
		}
		if (Record2[last]!=-1)
		{
			sum+=Record2[last];
		}
		else
		{
			temp=last;
			if (temp%10==1)
			{
				sum++;
			}
			while (temp>0)
			{
				temp=temp/10;
				if (temp%10==1)
				{
					sum++;
				}
			}
		}

	}
	Record2[i]=sum;*/
	return sum;
}