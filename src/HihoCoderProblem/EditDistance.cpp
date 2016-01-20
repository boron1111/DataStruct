#include "EditDistance.h"


EditDistance::EditDistance(void)
{
}


EditDistance::~EditDistance(void)
{
}

int EditDistance::Min(int a,int b)
{
	return a>b? b:a;
}

int EditDistance::minDistance(string word1, string word2)
{
	int len1=word1.size();
	int len2=word2.size();

	if (len1==0||len2==0)
	{
		int res=len1>len2 ? len1:len2;
		return res;
	}

	int **EditMatrix=new int*[len1+1];
	int i,j;
	for (i=0;i<=len1;i++)
	{
		EditMatrix[i]=new int[len2+1];
	}

	EditMatrix[0][0]=0;

	for (i=0;i<=len1;i++)
	{
		EditMatrix[i][0]=i;
	}

	for (j=0;j<=len2;j++)
	{
		EditMatrix[0][j]=j;
	}

	int temp;
	for (i=1;i<=len1;i++)
	{
		for (j=1;j<=len2;j++)
		{
			temp=(1-(word1[i-1]==word2[j-1])); 

			EditMatrix[i][j]=Min(Min(EditMatrix[i-1][j]+1,EditMatrix[i][j-1]+1),EditMatrix[i-1][j-1]+temp);
		}
	}

	temp=EditMatrix[len1][len2];
	if (EditMatrix!=NULL)
	{
		for (i=0;i<len1;i++)
		{
			delete[] EditMatrix[i];
		}
		delete[] EditMatrix;
	}
	return temp;
}

void EditDistance::TestClass()
{
	string str1,str2;
	str1="sutao";
	str2="";

	cout<<"edit distance is="<<endl;
	cout<<minDistance(str1,str2)<<endl;

}