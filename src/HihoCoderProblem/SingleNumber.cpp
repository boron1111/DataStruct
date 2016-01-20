#include "SingleNumber.h"


SingleNumber::SingleNumber(void)
{
}


SingleNumber::~SingleNumber(void)
{
}

vector<int> SingleNumber::singleNumber(vector<int>& nums)
{
	vector<int>::iterator it;
	vector<int> *SingleVec=new vector<int>;
	int res;
	int i=0;
	int len=nums.size();

	//result of xor
	for (it=nums.begin();it!=nums.end();it++)
	{
		if (i==0)
		{
			res=*it;
			i++;
		}
		else
		{
			res=res^(*it);
			i++;
		}
	}

	int steps=0,temp=res;
	while (temp>0)
	{
		temp=temp/2;//binary length
		steps++;
	}
	//grouping
	int num1=0,num2=0;
	for (it=nums.begin();it<nums.end();it++)
	{
		int temp1,temp2;
		temp1=(*it>>(steps-1));
		temp2=(res>>(steps-1));

		if ((temp1&temp2)==0)
		{
			num1=num1^(*it);
		}
		else
		{
			num2=num2^(*it);
		}
	}
	(*SingleVec).push_back(num1);
	(*SingleVec).push_back(num2);

	//finding the two number
	return *SingleVec;
}

void SingleNumber::TestClass()
{
	vector<int> vec;
	int A[8]={1,1,2,2,3,5,4,4};
	for (int i=0;i<8;i++)
	{
		vec.push_back(A[i]);
	}
	vector<int> res=singleNumber(vec);
	for (vector<int>::iterator it=res.begin();it!=res.end();it++)
	{
		cout<<*it<<endl;
	}
}