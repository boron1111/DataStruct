#include "SearchIndexNumber.h"


SearchIndexNumber::SearchIndexNumber(void)
{
}


SearchIndexNumber::~SearchIndexNumber(void)
{
}

int SearchIndexNumber::searchInsert(vector<int>& nums, int target)
{

	int Len=nums.size();
	int pos=0;
	while(nums[pos]<target && pos<Len)
	{
		pos++;
	}
	return pos;
}

void SearchIndexNumber::TestClass()
{
	int Array[7]={1,3,5,6};
	vector<int> nums(Array,Array+7);

	int pos=searchInsert(nums,5);

	cout<<"Result="<<pos<<endl;
}