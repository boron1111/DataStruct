#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;

void StringReplace1()
{
	char strings[300],s2[300];
	char temp;
	int i,j,k=0;
	char target[]="marshtomp";
	char replace[]="fjxmlhx";
	int len1,len2,len3,flag=0;
	len2=strlen(target);
	len3=strlen(replace);
	while (gets(strings))
	{
		k=0;
		flag=0;//label whether last number is matched
		len1=strlen(strings);
		for (i=0;i<len1-len2+1;i++)
		{
			for (j=0;j<len2;j++)
			{
				if (strings[i+j]>='A'&&strings[i+j]<='Z')
				{
					temp='a'-'A'+strings[i+j];
				}
				else
				{
					temp=strings[i+j];
				}
				if (temp!=target[j])
				{
					break;
				}
			}
			if (j==len2)
			{
				flag=i+j;
				for (j=0;j<len3;j++)
				{
					s2[k]=replace[j];
					i=i+1;//+len2-1;
					k=k+1;//len3;
				}
				i=i+2;
			}
			s2[k]=strings[i];
			k++;
		}
		if (flag >len1-len2)
		{
			flag=flag+1;
		}
		else
		{
			flag=len1-len2+1;
		}
		for (i=flag;i<len1;i++)
		{
			s2[k]=strings[i];
			k++;
		}
		for (i=0;i<k;i++)
		{
			cout<<s2[i];
		}
		cout<<endl;

	}
}