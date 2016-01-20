#include <iostream>
#include <math.h>
#include "MedianFinder.h"
using namespace std;



MedianFinder::MedianFinder(void)
{
	len=0;
	lenMax=1000;
	Array=new int[1000];
}


MedianFinder::~MedianFinder(void)
{
}

void MedianFinder::printData()
{
	cout<<"len="<<len<<endl;
}

void MedianFinder::TestClass()
{

	for (int i=0;i<2000;i++)
	{
		addNum(i*2+1);
	}
	cout<<findMedian()<<endl;
}

void MedianFinder::addNum(int num)
{
	int i,j;
	if (this->len==0)
	{
		this->Array[len]=num;
		this->len++;
	}
	else
	{
		for (i=len-1;i>=0;i--)
		{
			if (Array[i]>num)
			{
				Array[i+1]=Array[i];
			}
			else
			{
				break;
			}
		}
		Array[i+1]=(num);
		len++;
	}
	if (len>=lenMax)
	{
		int *temp=new int[len];
		for (i=0;i<len;i++)
		{
			temp[i]=Array[i];
		}
		delete[] Array;
		Array=new int[2*len];
		for (i=0;i<len;i++)
		{
			Array[i]=temp[i];
		}
		lenMax=2*len;
		delete[] temp;
	}
}
double MedianFinder::findMedian()
{
	if (len%2==0)
	{
		return (Array[(len-1)/2]+Array[(len)/2])/2.0;
	}
	else
	{
		return Array[len/2];
	}
}