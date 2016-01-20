#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;


#pragma once
class TestVirtualClass
{
public:
	TestVirtualClass(void);
	~TestVirtualClass(void);
	void TestClass();

};

class Base1
{
public:
	void Novirtual()
	{
		cout<<"Base no virtual"<<endl;
	}

	virtual void YesVirtual()
	{
		cout<<"Base Yes virtual"<<endl;
	}
};

class SubClass1:public Base1
{
public:
	void Novirtual()
	{
		cout<<"Sub1 No virtual"<<endl;
	}

	virtual void YesVirtual()
	{
		cout<<"Sub1 Yes virtual"<<endl;
	}
};

