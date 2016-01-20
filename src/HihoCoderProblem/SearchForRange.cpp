#include "SearchForRange.h"


SearchForRange::SearchForRange(void)
{
}


SearchForRange::~SearchForRange(void)
{
}

vector<int> SearchForRange::searchRange(vector<int>& nums, int target)
{
	int len=nums.size();
	vector<int> res;
	res.resize(2);
	res[0]=-1;
	res[1]=1;
	if (len==0)
	{
		return res;
	}
	int l=0,r=len-1,temp;
	int start=0,end=len-1;

	while (l!=r)
	{
		temp=(l+r)/2;
		if (nums[temp] >=target-1)
		{
			r=temp;
		}
		else
		{
			l=temp;
		}
	}
	start=l;

	l=0,r=len-1;
	while (l!=r)
	{
		temp=(l+r)/2;
		if (nums[temp] >target+1)
		{
			r=temp;
		}
		else
		{
			l=temp;
		}
	}
	end=l;


	res[0]=start;
	res[1]=end;
	return res;
}


int SearchForRange::BinarySearch(vector<int>& nums, int target)
{
	int len=nums.size();

	if (len==0)
	{
		return 0;
	}
	int l=0,r=len-1,temp;
	int start=0,end=len-1;

	while (l!=r)
	{
		temp=(l+r)/2;
		if (nums[temp] >=target-1)
		{
			r=temp;
		}
		else
		{
			l=temp;
		}
	}
	start=l;

	l=0,r=len-1;
	while (l!=r)
	{
		temp=(l+r)/2;
		if (nums[temp] >target+1)
		{
			r=temp;
		}
		else
		{
			l=temp;
		}
	}
	end=l;
	return l;
}

void SearchForRange::TestClass()
{
	int Array[6]={5, 7, 7, 8, 8, 10};
	vector<int> nums(Array,Array+6);

	vector<int> pos=searchRange(nums,5);

	cout<<"Result="<<pos[0]<<","<<pos[1]<<endl;
}