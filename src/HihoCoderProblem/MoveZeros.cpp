#include "MoveZeros.h"


MoveZeros::MoveZeros(void)
{
}


MoveZeros::~MoveZeros(void)
{
}

void MoveZeros::moveZeroes(vector<int>& nums)
{
	int Len=nums.size();
	//cout<<"len="<<Len<<endl;
	int i,j,flag=0;
	j=0;
	for (i=0;i<Len;i++)
	{
		if (flag==1||j>=Len)
		{
			nums[i]=0;
			continue;
		}
		if (nums[j]!=0)
		{
			nums[i]=nums[j];
			j++;
		}
		else
		{
			while (nums[j]==0)
			{
				j++;
				if (j>=Len){
					flag=1;
					break;
				}
			}
			if (flag==1)
			{
				nums[i]=0;
			}
			else
			{
				nums[i]=nums[j];
			}
			j++;
		}

		if (j>=Len){
			flag=1;
		}
		//cout<<i<<","<<nums[i]<<endl;
	}
}

void MoveZeros::TestClass()
{
	
	int Len=10;
	int *Array=new int[Len];
	for (int i=0;i<Len;i++)
	{
		Array[i]=i;
	}
	vector<int> nums(Array,Array+Len);
	
	nums.at(9)=0;
	moveZeroes(nums);
	for (int i=0;i<Len;i++)
	{
		cout<<nums[i]<<endl;
	}
	if (Array!=NULL)
	{
		delete[] Array;
	}
}