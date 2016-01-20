#include "MySqrt.h"


MySqrt::MySqrt(void)
{
}


MySqrt::~MySqrt(void)
{
}

int MySqrt::mySqrt(int x)
{
	double root=x;
	while(abs(root*root-x)>0.1)
	{
		root=(root+x/root)/2.0;
	}
	return (int)root;
}

void MySqrt::TestClass()
{
	cout<<"root is="<<mySqrt(50)<<endl;
}