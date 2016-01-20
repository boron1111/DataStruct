#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;
long long F[1000]={0,0,0};
long long Fibonacci(int n)
{
	if (n <2)
	{
		return 1;
	}
	else{
		return Fibonacci(n-1)+Fibonacci(n-2);
	}
}
long long Fibonacci2(int n)
{
	long long temp1,temp2;
	if (n <2)
	{
		F[n]=1;
		return 1;
	}
	else
	{
		//cout<<n<<","<<F[n-2]<<endl;
		F[n-2]=F[n-2]>1? F[n-2]: Fibonacci2(n-2);
		F[n-1]=F[n-1]>1? F[n-1]: Fibonacci2(n-1);
		
		F[n]=F[n-1]+F[n-2];
		return F[n];
	}
}