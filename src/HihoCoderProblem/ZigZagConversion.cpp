#include "ZigZagConversion.h"


ZigZagConversion::ZigZagConversion(void)
{
}


ZigZagConversion::~ZigZagConversion(void)
{
}

string ZigZagConversion::convert(string s, int numRows)
{
	if (numRows==1){
		return s;
	}
	int i,j,k=0,kz=0,ktemp;
	int NumUnit=2*numRows-2,ColUnit=numRows-1;
	char *sMatrix;
	int sz=s.size();
	
	int kcols=0;
	int temp1=(sz-sz/NumUnit*NumUnit);//Special case to judge how many cols there is
	if (temp1>numRows)
	{
		kcols=sz/2+1+(temp1-numRows);
	}
	else if (temp1>0)
	{
		kcols=sz/2+1;
	}
	else
	{
		kcols=sz/2;
	}
	
	
	while (kcols*NumUnit<sz)
	{
		kcols++;
	}
	int Len=numRows*kcols;
	sMatrix=new char[Len];
	for (i=0;i<Len;i++){
		sMatrix[i]=' ';
	}
	
	string s2;
	while(k<sz)//Find the corresponding position for each character
	{
		ktemp=k-2*kz*ColUnit+1;//k-kz*(2*numRows-2)+1;
		if (ktemp<=numRows)
		{
			i=ktemp-1;
			j=kz*ColUnit;
		}
		else
		{
			i=2*numRows-1-ktemp;//numRows-1-(ktemp-numRows);
			j=(kz-1)*numRows-kz+ktemp;//kz*(numRows-1)+(ktemp-numRows);
		}

		sMatrix[i*kcols+j]=s[k];
		k++;
		if (ktemp==2*numRows-2)
		{
			kz++;
		}
		//cout<<ktemp<<","<<i<<","<<j<<","<<s[k-1]<<sMatrix[i*kcols+j]<<endl;
	}
	cout<<kcols<<endl;
	
	k=0;i=0;j=0;
	for (i=0;i<numRows;i++)
	{
		for (j=0;j<kcols;j++)
		{		
			cout<<sMatrix[i*kcols+j]<<" ";
			if (sMatrix[i*kcols+j]!=' ')
			{
				s2+=sMatrix[i*kcols+j];
			}		
		}
		cout<<endl;
	}
	return s2;
}
void ZigZagConversion::TestClass()
{
	string s("ABCDE");//("PAYPALISHIRING");
	cout<<s<<endl;
	string s2=convert(s,4);
	
	cout<<s2<<endl;
}