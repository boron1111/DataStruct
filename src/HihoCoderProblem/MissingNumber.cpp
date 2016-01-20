#include "MissingNumber.h"


MissingNumber::MissingNumber(void)
{
}


MissingNumber::~MissingNumber(void)
{
}

void MissingNumber::TestClass()
{
	int A[7]={0,1,2,3,4,5,6};
	vector<int> vec;
	for (int i=0;i<7;i++)
	{
		vec.push_back(A[i]);
	}
	int missing=missingNumber(vec);
	cout<<missing<<endl;
}

int MissingNumber::missingNumber(vector<int>& nums)
{
	

	vector<int>::iterator it;
	int k=0;
	int len=nums.size();
	int oldtemp,diff;

	if (len==1)
	{
		oldtemp=nums.front();
		return oldtemp==0? 1:0;
	}

	int start=-1,end=-1;
	for (it=nums.begin();it!=nums.end();it++)
	{
		if (k==0)
		{
			oldtemp=*it;
			start=*it;
			*it=-1;
			k++;
		}
		else
		{
			if (k==len-1)
			{
				end=*it;
			}
			diff=*it-oldtemp;
			oldtemp=*it;
			*it=diff;
			k++;
			//cout<<*it<<endl;
		}


	}

	int i=0;
	for (it=nums.begin();it!=nums.end();it++)
	{
		cout<<*it<<endl;
		if (i==0)
		{
			i++;
			continue;
		}
		else if (*it==2)
		{
			return i;
		}
		else
		{
			i++;
		}
	}
	if (start==0)
	{
		return end+1;
	}
	else
	{
		return 0;
	}
}