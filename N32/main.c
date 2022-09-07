#include<stdio.h>
#define go(i,a,b) for(int i=a;i<=b;i++)
int a[2300][13][40][8],L[10],Y=1900,M=1,D=1,W=1,day[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
int Day()
{
	if(M!=2)return day[M];
	return ((Y%100==0&&Y%400==0)||(Y%100!=0&&Y%4==0))?29:28;
}
int main()
{
	int n,b,c,A,B,C;
	go(i,0,7)L[i]=0;
	while(Y<2101)
	{
		go(i,0,7)a[Y][M][D][i]=L[i];
		L[W]+=(D%10==W);
		L[0]+=(D%10==W);
		W=W>6?1:W+1;
		D<Day()?D++:(D=1,M<12?M++:(M=1,Y++));
	}	
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d%d%d%d%d",&b,&c,&A,&B,&C);
		printf("%d ",a[A][B][C][0]-a[n][b][c][0]);
		go(i,1,6)printf("%d ",a[A][B][C][i]-a[n][b][c][i]);
		printf("%d\n",a[A][B][C][7]-a[n][b][c][7]);
	}
    return 0;
}
//By LQ_gdwind
