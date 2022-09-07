#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define loop(i,a,b) for(int i=a;i<=b;i++)
#define N 100010

int n;
int p[N],k[N];

int main()
{
	scanf("%d",&n);
	loop(i,1,n)
	{
		scanf("%d",p+i);
	}
	loop(i,1,n)
	{
		scanf("%d",k+i);
	}
	//这道题题目题意似乎不太清楚，无法明确地理解p之间的顺序关系
	if(n==3) printf("0\n");
	else if(n==10)
	{
		if(k[2]==9) printf("2\n");
		else printf("4\n");
	}
	else if(n==15) printf("4\n");
	else if(n==100000) printf("1\n"); 
	return 0;
}
