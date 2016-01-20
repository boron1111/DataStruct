#include "RemoveElement.h"


RemoveElement::RemoveElement(void)
{
}


RemoveElement::~RemoveElement(void)
{
}

int RemoveElement::removeElement(vector<int>& nums, int val)
{
	int Len=nums.size();
	FastSort(nums,Len,0,Len-1);

	int NumofVal=0;
	int FirstPosition=0,LastPosition=0;
	for (int i=0;i<Len;i++)
	{
		if (nums[i]==val)
		{
			NumofVal++;
			if (NumofVal==1)
			{
				FirstPosition=i;
			}
			LastPosition=i;
		}
	}

	for (int i=FirstPosition;i<Len-NumofVal;i++)
	{
		nums[i]=nums[i+NumofVal];
	}

	for (int i=LastPosition-NumofVal;i<Len;i++)
	{
		nums.pop_back();
	}



	return Len-NumofVal;
	
}

void RemoveElement::TestClass()
{
	int Array[7]={1,3,5,2,6,3,7};
	vector<int> nums(Array,Array+7);

	cout<<"Result="<<removeElement(nums,3)<<endl;
}

void RemoveElement::FastSort(vector<int>& Array,int n,int l,int r)
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