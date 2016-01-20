#include "Integer2Words.h"


Integer2Words::Integer2Words(void)
{
}


Integer2Words::~Integer2Words(void)
{

}

string Integer2Words::numberToWords(int num)
{
	if(num==0)
		return "Zero";
	if (num < 100)
	{
		return ShiweiValue(num);
	}
	else if (num>=100&& num<1000)
	{
		int Baiwei=num/100;
		int Shiwei=num%100;
		if (Shiwei>0)
		{
			return GeweiValue(Baiwei)+" Hundred "+ShiweiValue(num%100);
		}
		else
		{
			return GeweiValue(Baiwei)+" Hundred";
		}
		
	}
	else if (num>=1000 && num<1000000)
	{
		int Qianwei=num/1000;
		int Baiwei=(num%1000);
		if (Baiwei==0)
		{
			return numberToWords(Qianwei)+" Thousand";
		}
		else
		{
			return numberToWords(Qianwei)+" Thousand "+numberToWords(Baiwei);
		}
	}
	else if(num>=1000000&&num<1000000000)
	{
		int Million=num/1000000;
		int thounsand=num%1000000;
		if (thounsand==0)
		{
			return numberToWords(Million)+" Million";
		}
		else
		{
			return numberToWords(Million)+" Million "+numberToWords(thounsand);
		}
		
	}
	else if (num>=1000000000)
	{
		int Billion=num/1000000000;
		int Million=num%1000000000;
		if (Million==0)
		{
			return numberToWords(Billion)+" Billion";
		}
		else
		{
			return numberToWords(Billion)+" Billion "+numberToWords(num%1000000000);
		}	
	}
}

string Integer2Words::ShiweiValue(int num)
{
	if (num>=10&&num<20)
	{	
		switch(num)
		{
		case(10):return "Ten";
		case(11): return "Eleven";
		case(12): return "Twelve";
		case(13): return "Thirteen";
		case(14): return "Fourteen";
		case(15): return "Fifteen";
		case(16): return "Sixteen";
		case(17): return "Seventeen";
		case(18): return "Eighteen";
		case(19): return "Nineteen";
		default: return "Error";
		}
	}
	else if(num>=20&&num<100)
	{
		int Shiwei=num/10;
		int Gewei=num%10;
		string Geweis;
		if (Gewei>0)
		{
			Geweis=" "+GeweiValue(Gewei);
		}
		else
		{
			Geweis="";
		}
		switch(Shiwei)
		{
		case(2):return "Twenty"+Geweis;
		case(3): return "Thirty"+Geweis;
		case(4): return "Forty"+Geweis;
		case(5): return "Fifty"+Geweis;
		case(6): return "Sixty"+Geweis;
		case(7): return "Seventy"+Geweis;
		case(8): return "Eighty"+Geweis;
		case(9): return "Ninety"+Geweis;	
		}
	}
	else if(num<10&&num>0)
	{
		return GeweiValue(num);
	}
	else
	{
		return "";
	}

}

string Integer2Words::GeweiValue(int num)
{
	if (num>9)
	{
		return "Error";
	}
	switch(num)
	{
	case(0):return "";
	case(1): return "One";
	case(2): return "Two";
	case(3): return "Three";
	case(4): return "Four";
	case(5): return "Five";
	case(6): return "Six";
	case(7): return "Seven";
	case(8): return "Eight";
	case(9): return "Nine";	
	}
	
}