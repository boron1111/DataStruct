#include "TestVirtualClass.h"


TestVirtualClass::TestVirtualClass(void)
{
}


TestVirtualClass::~TestVirtualClass(void)
{
}

void TestVirtualClass::TestClass()
{
	SubClass1 sub1;
	sub1.Novirtual();
	sub1.YesVirtual();

	Base1 base1;
	base1.Novirtual();
	base1.YesVirtual();

	//SubClass1 *sub2;
	Base1 *base2;

	//sub2=&base1;
	base2=&sub1;

	//sub2->Novirtual();
	//sub2->YesVirtual();

	base2->Novirtual();
	base2->YesVirtual();
}