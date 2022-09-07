#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define loop1(i,a,b) for(int i=a;i>=b;i--)
#define loop2(i,a,b) for(int i=a;i<=b;i++)

int n;

int aishishai(int x)
{
	if(x==2) return 2;
	if(3<=x&&x<=4) return 3;
	loop1(i,x,2)
	{
		loop2(j,2,i/j)
		{
			if(i%j==0) break;
			if((j+1)>i/(j+1)) return i;
		}
	}
}

int main()
{
	scanf("%d",&n);
	printf("The max prime number is %d.\n",aishishai(n));
	return 0;
} 
//by LQ_gdwind
