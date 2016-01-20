#include "AddDigits.h"


AddDigits::AddDigits(void)
{
}


AddDigits::~AddDigits(void)
{

}

int AddDigits::addDigits(int num) 
{
	int temp=num;
	int sum=0;
	int i;
	while(temp>0)
	{
		sum+=temp%10;
		temp/=10;
	}
	if (sum>9)
	{
		return addDigits(sum);
	}
	else
	{
		return sum;
	}
}

void AddDigits::TestClass()
{
	cout<<"Add digit="<<addDigits(38)<<endl;
}
