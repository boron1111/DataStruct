#include "LargestNumber.h"


LargestNumber::LargestNumber(void)
{
}


LargestNumber::~LargestNumber(void)
{
}
int LargestNumber::isLarger(int num1,int num2)
{
	stringstream ss1,ss2;
	string str1,str2;
	ss1<<num1;
	ss1>>str1;

	ss2<<num2;
	ss2>>str2;

	string str3=str1+str2;
	string str4=str2+str1;
	
	for (int i=0;i<str3.size();i++)
	{
		if (str3[i]<str4[i])
		{
			return -1;
		}
		else if (str3[i]>str4[i])
		{
			return 1;
		}
	}
	return 0;
}

string LargestNumber::largestNumber(vector<int>& nums)
{
	int i,j;
	int Len=nums.size();
	char temp[10];	
	if (Len==0)
	{
		return "0";
	}

	int *array1=new int[Len];
	for (i=0;i<Len;i++)
	{
		array1[i]=nums[i];
	}


	for (i=1;i<Len;i++)
	{
		j=i-1;
		int temp=array1[i];
		while (isLarger(array1[j],temp)<0&&(j>=0))
		{
			array1[j+1]=array1[j];
			j--;

		}
		if (j!=i-1)
		{
			array1[j+1]=temp;
		}
	}
	string res;
	for (i=0;i<Len;i++)
	{
		char temp[10];
		sprintf(temp,"%d",array1[i]);
		string str2(temp);
		res+=str2;	
	}

	if (res[0]=='0')
	{
		return "0"; //Special case for 0000
	}

	if (array1 !=NULL)
	{
		delete[] array1;
	}
	return res;
}

void LargestNumber::TestClass()
{
	int Array1[]={3,30,34,5,9};
	vector<int> nums;
	nums.resize(5);

	for (int i=0;i<5;i++)
	{
		nums[i]=Array1[i];
	}

	string res=largestNumber(nums);
	cout<<"Result is="<<res<<endl;
}