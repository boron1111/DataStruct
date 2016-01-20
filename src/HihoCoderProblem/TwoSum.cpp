#include "TwoSum.h"


TwoSum::TwoSum(void)
{
}


TwoSum::~TwoSum(void)
{
}

vector<int> TwoSum::twoSum(vector<int>& nums, int target)
{
	int i,j;
	vector<int> index(2);
	for (i=0;i<nums.size();i++)
	{
		for (j=i+1;j<nums.size();j++)
		{
			if (nums[i]+nums[j]==target)
			{
				index[0]=i+1;
				index[1]=j+1;
				return index;
			}
		}
	}
	return index;
}

void TwoSum::TestClass()
{
	int Array[4]={2,7,11,15};
	vector<int> Nums(Array,Array+4);
	vector<int> res=twoSum(Nums,9);

	for (int i=0;i<res.size();i++)
	{
		cout<<res[i]<<endl;
	}
}