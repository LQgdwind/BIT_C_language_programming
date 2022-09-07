#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define loop(i,a,b) for(int i=a;i<=b;i++)
#define read(a) (scanf("%d",&a))

typedef long long ll;
typedef double db;
typedef unsigned char unchar;

int n,m;

int f(int x,int y)
{
	if(x>5&&y>=0)
	{
		return 1;
	}
	else if(y<0)
	{
		return 2;
	}
	else return f(x+1,y)+f(x,y-1);

}

int main()
{
	scanf("%d,%d",&n,&m);
	printf("%d\n",f(n,m));
}
//by LQ_gdwind
