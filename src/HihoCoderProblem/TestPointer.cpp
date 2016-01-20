#include "TestPointer.h"


TestPointer::TestPointer(void)
{
}


TestPointer::~TestPointer(void)
{
}

void TestPointer::TestClass()
{
	int A[][3]={1,2,3,4,5,6};
	int B[]={1,2,3,4,5,6};
	int *p1;
	int *p2[3];
	int (*p3)[3];

	p1=B;
	p2[0]=p1;
	p3=A;
	for (int i=0;i<3;i++)
	{
		cout<<*(*(p3+2)+i)<<endl;
	}
}