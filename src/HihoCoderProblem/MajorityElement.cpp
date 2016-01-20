#include "MajorityElement.h"


MajorityElement::MajorityElement(void)
{
}


MajorityElement::~MajorityElement(void)
{
}

int MajorityElement::majorityElement(vector<int>& nums)
{
	int elem = 0;
	int count = 0;

	for(int i = 0; i < nums.size(); i++)  {

		if(count == 0)  {
			elem = nums[i];
			count = 1;
		}
		else    {
			if(elem == nums[i])
				count++;
			else
				count--;
		}

	}
	return elem;

	//int i,j;	
	//int Len=nums.size();
	//int *Label=new int[Len];
	//for (i=0;i<Len;i++)
	//{
	//	Label[i]=0;
	//}

	//for (i=0;i<Len;i++)
	//{
	//	Label[i]=1;
	//	for (j=0;j<i;j++)
	//	{
	//		if (nums[j]==nums[i])
	//		{
	//			Label[j]++;
	//			break;
	//		}
	//	}
	//}

	//for (i=0;i<Len;i++)
	//{
	//	cout<<Label[i]<<endl;
	//	if (Label[i]>Len/2)
	//	{
	//		return nums[i];
	//	}
	//}

	//if (Label!=0)
	//{
	//	delete[] Label;
	//}
	//return -1;
}

void MajorityElement::TestClass()
{
	int Len=10;
	int Array[10]={3,3,2,3,2,3,2,3,5,3};
	vector<int> nums(Array,Array+Len);
	for (int i=0;i<10;i++)
	{
		cout<<nums[i]<<endl;
	}
	cout<<"major elements="<<majorityElement(nums)<<endl;
}