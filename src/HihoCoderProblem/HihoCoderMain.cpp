#include <iostream>
#include<time.h>
#include "NumberofDigit.h"
#include "PowOperation.h"
#include "PowerofTwo.h"
#include "ContainDuplicate.h"
#include "PerfectSquares.h"
#include "AddDigits.h"
#include "nthUglyNumber.h"
#include "MoveZeros.h"
#include "NimGame.h"
#include "HappyNumber.h"
#include "UglyNumber.h"
#include "MajorityElement.h"
#include "StackUseQueue.h"
#include "ReverseInteger.h"
#include "findDuplicate.h"
#include "MySqrt.h"
#include "PlusOne.h"
//#include "MedianOfTwoSortedArrays.h"
//#include "AddTwoNumbers.h"
#include "TwoSum.h"
//#include "MergeTwoSortedLists.h"
//#include "MergeKSortedLists.h"
#include "ZigZagConversion.h"
#include "SwapPairs.h"
#include "StringToInteger.h"
#include "TestPointer.h"
#include "TestVirtualClass.h"
#include "Search2DMatrix.h"
#include "H_Index.h"
#include "ReverseLinklist.h"
#include "LargestNumber.h"
#include "DivideTwoIntegers.h"
#include "DeleteNode.h"
#include "RemoveLinkListElementValue.h"
#include "RemoveElement.h"
#include "SearchIndexNumber.h"
#include "SearchForRange.h"
#include "HuwWeiTestCharReverse.h"
#include "HuaWeiTestCountrySort.h"
#include "EditDistance.h"
#include "CountPrimes.h"
#include "CountAndSay.h"
#include "NumberOfIslands.h"
#include "CoinChange.h"
#include "TestC_basci.h"
using namespace std;

int main()
{
	time_t timep;
	int Ts=time(&timep);

	//int A[][3]={1,2,3,4,5,6};
	//int (*p)[3];
	//p=A;
	//p[1]=A+2;
	//p[2]=A+4;
	//cout<<"stop"<<*p[0]<<*p[1]<<*p[2]<<endl;
	//NumberofDigit sg;
	TestC_basci sg;
	sg.TestClass();

	time_t timep2;
	int Te=time(&timep2);
	cout<<"Time="<<Te-Ts<<endl;
	return 0;
}