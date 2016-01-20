#include "findDuplicate.h"


FindDuplicate::FindDuplicate(void)
{
}


FindDuplicate::~FindDuplicate(void)
{
}

int FindDuplicate::findDuplicate(vector<int>& nums)
{
	FastSort(nums,nums.size(),0,nums.size()-1);
	for (int i=0;i<nums.size()-1;i++)
	{
		if (nums[i]==nums[i+1])
		{
			return nums[i];
		}
	}
	return -1;
}
void FindDuplicate::TestClass()
{
	int Array[7]={1,3,5,2,6,3,7};
	vector<int> nums(Array,Array+7);
	//FastSort(Array,7,0,6);
	
	cout<<findDuplicate(nums)<<endl;
}

void FindDuplicate::FastSort(vector<int>& Array,int n,int l,int r)
{
	int i,j;
	int temp;

	if (l>=r){
		return;
	}
	i=l;j=r;
	temp=Array[i];

	while (i<j)
	{
		while(temp<=Array[j]&&(i<j))
			j--;
		if (i<j)
		{
			Array[i]=Array[j];
		}
		while(Array[i]<=temp&&(i<j))
			i++;
		if (i<j)
		{
			Array[j]=Array[i];
		}
	}
	Array[i]=temp;
	FastSort(Array,n,l,i-1);
	FastSort(Array,n,i+1,r);
}