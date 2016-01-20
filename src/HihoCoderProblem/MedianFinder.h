#pragma once
class MedianFinder
{
public:
	MedianFinder(void);
	~MedianFinder(void);

	void printData();
	void TestClass();
	void addNum(int num);
	double findMedian();
private:
	int len;
	int lenMax;
	int *Array;

};

