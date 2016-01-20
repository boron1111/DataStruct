#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#define MAX_PATH 256
using namespace std;

int maze[10][10] = {0};
int route[100][2] = {0};
void MazePath()
{
	int row=0,line=0;
	scanf("%d %d",&row,&line);
	for (int i=0;i<row;i++)
	{
		for (int j=0;j<line;j++)
		{
			scanf("%d",&maze[i][j]);
		}
	}
	//走迷宫
	//堆栈:记录上一个位置
	int xcurrent = 0;
	int ycurrent = 0;
	int count=0;
	while(true)
	{
		if (maze[xcurrent+1][ycurrent]==0 && xcurrent+1<row)
		{
			//返回上一个位置,防止原地打转，判断此方向是否已经走过
			if (route[count-1][0]==xcurrent+1 && route[count-1][1]==ycurrent)
			{
				maze[xcurrent][ycurrent]=1;//设置为墙
				count--;
				xcurrent++;
			}
			else
			{
				route[count][0]=xcurrent;
				route[count][1]=ycurrent;
				count++;
				xcurrent++;
			}
		}
		else if (maze[xcurrent][ycurrent+1]==0 && ycurrent<line)
		{
			if (route[count-1][0]==xcurrent && route[count-1][1]==ycurrent+1)
			{
				maze[xcurrent][ycurrent]=1;//设置为墙
				count--;
				ycurrent++;
			}
			else
			{
				route[count][0]=xcurrent;
				route[count][1]=ycurrent;
				count++;
				ycurrent++;
			}
		}
		else if (maze[xcurrent-1][ycurrent]==0 && xcurrent-1>=0)
		{
			if (route[count-1][0]==xcurrent-1 && route[count-1][1]==ycurrent)
			{
				maze[xcurrent][ycurrent]=1;//设置为墙
				count--;
				xcurrent--;
			}
			else
			{
				route[count][0]=xcurrent;
				route[count][1]=ycurrent;
				count++;
				xcurrent--;
			}
		}
		else if (maze[xcurrent][ycurrent-1]==0 && ycurrent-1>=0)
		{
			if (route[count-1][0]==xcurrent && route[count-1][1]==ycurrent-1)
			{
				maze[xcurrent][ycurrent]=1;//设置为墙
				count--;
				ycurrent--;
			}
			else
			{
				route[count][0]=xcurrent;
				route[count][1]=ycurrent;
				count++;
				ycurrent--;
			}
		}
		if (xcurrent==row-1 && ycurrent==line-1)
		{
			route[count][0]=xcurrent;
			route[count][1]=ycurrent;
			count++;
			break;
		}
	}

	for (int i=0;i<count;i++)
	{
		printf("(%d,%d)",route[i][0],route[i][1]);
	}

}

void MazePathSelf()
{
	int row=0,line=0;
	scanf("%d %d",&row,&line);
	for (int i=0;i<row;i++)
	{
		for (int j=0;j<line;j++)
		{
			scanf("%d",&maze[i][j]);
		}
	}
	//走迷宫
	//堆栈:记录上一个位置
	int xcurrent = 0;
	int ycurrent = 0;
	int count=0;
	stack<int> mystackx,mystacky;
	stack<int> mystackx2,mystacky2;
	mystackx.push(0);
	mystacky.push(0);
	while(true)
	{
		if (maze[xcurrent+1][ycurrent]==0 && xcurrent+1<row)
		{
			//返回上一个位置,防止原地打转，说明下一个方向不通，只能返回到原地，则退一步进行下一个方向查找
			if (route[count-1][0]==xcurrent+1 && route[count-1][1]==ycurrent)
			{
				maze[xcurrent][ycurrent]=1;//设置为墙
				count--;
				xcurrent++;
				mystackx.pop();
				mystacky.pop();
			}
			else
			{
				route[count][0]=xcurrent;
				route[count][1]=ycurrent;
				count++;
				xcurrent++;
				mystackx.push(xcurrent);
				mystacky.push(ycurrent);
			}
		}
		else if (maze[xcurrent][ycurrent+1]==0 && ycurrent<line)
		{
			if (route[count-1][0]==xcurrent && route[count-1][1]==ycurrent+1)
			{
				maze[xcurrent][ycurrent]=1;//设置为墙
				count--;
				ycurrent++;
				mystackx.pop();
				mystacky.pop();
			}
			else
			{
				route[count][0]=xcurrent;
				route[count][1]=ycurrent;
				count++;
				ycurrent++;
				mystackx.push(xcurrent);
				mystacky.push(ycurrent);
			}
		}
		else if (maze[xcurrent-1][ycurrent]==0 && xcurrent-1>=0)
		{
			if (route[count-1][0]==xcurrent-1 && route[count-1][1]==ycurrent)
			{
				maze[xcurrent][ycurrent]=1;//设置为墙
				count--;
				xcurrent--;
				mystackx.pop();
				mystacky.pop();
			}
			else
			{
				route[count][0]=xcurrent;
				route[count][1]=ycurrent;
				count++;
				xcurrent--;
				mystackx.push(xcurrent);
				mystacky.push(ycurrent);
			}
		}
		else if (maze[xcurrent][ycurrent-1]==0 && ycurrent-1>=0)
		{
			if (route[count-1][0]==xcurrent && route[count-1][1]==ycurrent-1)
			{
				maze[xcurrent][ycurrent]=1;//设置为墙
				count--;
				ycurrent--;
				mystackx.pop();
				mystacky.pop();
			}
			else
			{
				route[count][0]=xcurrent;
				route[count][1]=ycurrent;
				count++;
				ycurrent--;
				mystackx.push(xcurrent);
				mystacky.push(ycurrent);
			}
		}
		if (xcurrent==row-1 && ycurrent==line-1)
		{
			route[count][0]=xcurrent;
			route[count][1]=ycurrent;
			count++;
			break;
		}
	}

	cout<<"count is="<<count<<endl;
	for (int i=0;i<count;i++)
	{
		printf("(%d,%d)",route[i][0],route[i][1]);
	}
	cout<< endl;
	for (int i=0;i<count;i++)
	{
		int x=mystackx.top();
		int y=mystacky.top();
		mystackx2.push(x);
		mystacky2.push(y);
		mystackx.pop();
		mystacky.pop();
	}
	for (int i=0;i<count;i++)
	{
		int x=mystackx2.top();
		int y=mystacky2.top();
		cout<<"<"<<x<<","<<y<<">";
		mystackx2.pop();
		mystacky2.pop();
	}
	cout<<endl;
}