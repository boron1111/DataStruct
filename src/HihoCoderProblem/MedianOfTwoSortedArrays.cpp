#include "MedianOfTwoSortedArrays.h"


MedianOfTwoSortedArrays::MedianOfTwoSortedArrays(void)
{
}


MedianOfTwoSortedArrays::~MedianOfTwoSortedArrays(void)
{
}

double MedianOfTwoSortedArrays::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{	
	int i=0,j=0,k=0;
	int Len=nums1.size()+nums2.size();
	vector<int> nums3(Len);
	while ((i<nums1.size())&&(j<nums2.size()))
	{
		if (nums1[i]<=nums2[j])
		{
			nums3[k]=nums1[i];
			k++;i++;
		}
		else
		{
			nums3[k]=nums2[j];
			k++;j++;
		}
	}

	while (i<nums1.size())
	{
		nums3[k++]=nums1[i++];
	}
	while (j<nums2.size())
	{
		nums3[k++]=nums2[j++];
	}

	if ((nums1.size()+nums2.size())%2==0)
	{
		return (nums3[(Len-1)/2]+nums3[Len/2])/(double)2.0;
	}
	else
	{
		return (double)nums3[Len/2];
	}
}

void MedianOfTwoSortedArrays::TestClass()
{
	int Array1[1]={};
	int Array2[2]={2,3};
	vector<int> nums1(Array1,Array1);
	vector<int> nums2(Array2,Array2+2);
	double res=findMedianSortedArrays(nums1,nums2);
	cout<<"median="<<res<<endl;
}