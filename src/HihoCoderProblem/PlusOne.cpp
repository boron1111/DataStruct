#include "PlusOne.h"


PlusOne::PlusOne(void)
{
}


PlusOne::~PlusOne(void)
{
}

vector<int> PlusOne::plusOne(vector<int>& digits)
{
	int Len=digits.size();
	int temp,next=1,flag=0;
	vector<int> digits2(digits);

	for (int i=Len-1;i>=0;i--)
	{
		temp=digits2[i]+next;
		if (temp>9)
		{
			next=1;
			digits2[i]=temp%10;
		}
		else
		{
			next=0;
			digits2[i]=temp%10;
		}
		if (i==0&&next==1)
		{
			flag=1;
		}
	}

	if (flag==0)
	{
		for (int i=0;i<Len;i++)
		{
			digits[i]=digits2[i];
		}
		return digits;
	}
	else
	{
		digits.resize(Len+1);
		digits[0]=1;
		for (int i=1;i<Len+1;i++)
		{
			digits[i]=digits2[i-1];
		}
		return digits;
	}
}

void PlusOne::TestClass()
{
	int Array[10]={9,8,7,6,5,4,3,2,1,0};
	vector<int> digits(Array,Array+10);
	for (int i=0;i<10;i++)
	{
		cout<<digits[i]<<",";
	}
	cout<<endl;
	vector<int> res=plusOne(digits);
	for (int i=0;i<res.size();i++)
	{
		cout<<res[i]<<",";
	}
	cout<<endl;
}