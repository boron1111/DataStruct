#include "nthUglyNumber.h"


nthUglyNumber::nthUglyNumber(void)
{
}


nthUglyNumber::~nthUglyNumber(void)
{
}

int nthUglyNumber::minimal(int a, int b, int c){
	return (a<b?a:b)<c?(a<b?a:b):c;
}
int nthUglyNumber::nthUglyNumber1(int n)
{
	int* arr=(int*)malloc(sizeof(int)*n);
	int index_2=0,index_3=0,index_5=0;
	int val_2=2, val_3=3, val_5=5;
	arr[0]=1;
	for(int i=1;i<n;i++){
		arr[i]=minimal(val_2,val_3,val_5);
		cout<<val_2<<","<<val_3<<","<<val_5<<"-----";
		if(arr[i]==val_2)      val_2=arr[++index_2]*2;
		if(arr[i]==val_3)      val_3=arr[++index_3]*3;
		if(arr[i]==val_5)      val_5=arr[++index_5]*5;
		cout<<val_2<<","<<val_3<<","<<val_5<<endl;
	}
	return arr[n-1];
}

	//int i,j;
	//if (n==0)
	//{
	//	return 0;
	//}

	//if (n>0 && n<= 6)
	//{
	//	return n;
	//}

	//int *res=new int[n*n];
	//int primes[]={2,3,5};
	//memset(res,0,sizeof(int)*(n*n));

	////for (i=1;i<=6;i++)
	////{
	////	res[i]=i;
	////}
	//int sum=1,order=0;
	//res[0]=0;
	//res[1]=1;
	//int start=1,end=1;
	//while (sum<n)
	//{
	//	for (i=start;i<=end;i++)
	//	{
	//		for (j=0;j<3;j++)
	//		{
	//			if (res[i]==0)
	//			{
	//				continue;
	//			}
	//			if (res[i*primes[j]]!=1)
	//			{
	//				res[i*primes[j]]=1;
	//				sum++;
	//				cout<<i*primes[j]<<endl;
	//			}
	//			
	//		}

	//	}
	//	start=start*2;
	//	end*=5;
	//	if (end > n*n)
	//	{
	//		cout<<"exceed"<<endl;
	//		break;
	//		
	//	}
	//}

	//sum=0;
	//for (i=1;i<n*n;i++)
	//{
	//	if (res[i])
	//	{
	//		sum++;
	//	}
	//	if (sum==n)
	//	{
	//		cout<<i<<endl;
	//		return i;
	//	}
	//}

//	return 0;
//}

int nthUglyNumber::isPrime(int n)
{
	int i;
	for (i=2;i*i<=n;i++)
	{
		if (n%i==0)
		{
			return 0;
		}
	}
	return 1;
}

void nthUglyNumber::TestClass()
{
	cout<<"The number of prime is="<<nthUglyNumber1(29)<<endl;
}