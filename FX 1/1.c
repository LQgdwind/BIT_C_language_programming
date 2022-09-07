#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define loop(i,a,b) for(int i=a;i<=b;i++)
#define read(a) (scanf("%d",&a))

typedef long long ll;
typedef double db;
typedef unsigned char unchar;

int n;
unchar t;

unchar transfer(unchar m)
{
	if(m>=97) return m-32;else return m;
}

int add(int x)
{
	if(x>90) return add(x-26); else return x;
}

int judge(char x)
{
	if((t>=65&&t<=90)||(t>=97&&t<=122)) return 0;else return 1;
}

int main ()
{
	scanf("%d %c",&n,&t);t=transfer(t);
	if(judge(t)) 
	{
		printf("Input error!\n");
		return 0;
	}
	if(n==1)
	{
		printf("%c\n",t);
		return 0;
	}
	int space=2*n-3;
	loop(i,0,n-1)
	{
		printf("%c",add(t+i));
		if(i==n-1) printf("\n");else printf(" ");
	}
	loop(i,1,n-2)
	{
		printf("%c",add(t+i));
		loop(j,1,space)
		{
			printf(" ");
		}
		printf("%c\n",add(t+n+i-1));
	}
	loop(i,n-1,2*n-2)
	{
		printf("%c",add(t+i));
		if(i==2*n-2) printf("\n");else printf(" "); 
	}
}
//by LQ_gdwind
