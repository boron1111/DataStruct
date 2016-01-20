#include "H_Index.h"


H_Index::H_Index(void)
{
}


H_Index::~H_Index(void)
{
}

void H_Index::FastSort(int *citations,int l,int r)
{
	int i=l,j=r;
	int temp=citations[l];

	if (l>=r)
	{
		return;
	}

	while(i<j)
	{
		while((i<j)&&(citations[j]<=temp))
		{
			j--;
		}
		citations[i]=citations[j];

		while((i<j)&&(citations[i]>=temp))
		{
			i++;
		}
		citations[j]=citations[i];
	}
	citations[i]=temp;
	FastSort(citations,l,i-1);
	FastSort(citations,i+1,r);
}

int H_Index::hIndex(vector<int>& citations)
{
	int Len=citations.size();
	int i,j;

	if (Len==0)
	{
		return 0;
	}

	int *array1=new int[Len];
	for (i=0;i<Len;i++)
	{
		array1[i]=citations[i];
	}

	FastSort(array1,0,Len-1);

	j=1;
	for (i=0;i<Len;i++)
	{
		if (i+1>array1[i])
		{
			return i;
		}
		if (i+1<=array1[i]&&i==Len-1)
		{
			return ++i;
		}
		//cout<<i+1<<","<<citations[i]<<endl;
	}
	return 0;
}

void H_Index::TestClass()
{
	vector<int> citation;
	citation.resize(2);

	int citation2[]={0,1};//{2,7,9,3,1};
	for (int i=0;i<2;i++)
	{
		citation[i]=citation2[i];
	}
	
	int hindex=hIndex(citation);
	cout<<"Result is="<<hindex<<endl;
}