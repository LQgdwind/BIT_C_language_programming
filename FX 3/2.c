#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define loop(i,a,b) for(int i=a;i<=b;i++)

int n,m;

int f(int x,int y)
{
	if(x>y&&y>0&&x<4) return 1;
	else if(x>y&&y>4&&(!(y&1))) return f(x,y-1)+f(x,y-3);
	else if(x>y&&y>4&&(y&1)) return f(x,y-2)+f(x-4,y);
	else return -1;
}
int main()
{
	scanf("%d%d",&n,&m);
	printf("%d",f(n,m));
}
//by LQ_gdwind
