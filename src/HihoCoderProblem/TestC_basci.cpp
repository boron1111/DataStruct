#include "TestC_basci.h"


TestC_basci::TestC_basci(void)
{
}


TestC_basci::~TestC_basci(void)
{
}

void TestC_basci::test_static()
{
	static int a=10;
	cout<<a<<endl;
	a=a+2;
	cout<<a<<endl;
}

void TestC_basci::TestClass()
{
	test_static();
	test_static();
}