#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define loop2(i,a,b) for(int i=a;i>=b;i--)
#define loop(i,a,b) for(int i=a;i<=b;i++) 

typedef double db;

db n;

db sanbing(db x)
{
	if(x==1) return 1;
	else return 1/x+sanbing(x-2);
}

int main()
{
	scanf("%lf",&n);
	printf("%.6f\n",sanbing(2*n-1));
	return 0;
} 
//by LQ_gdwind
