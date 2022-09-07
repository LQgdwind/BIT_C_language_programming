#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define loop(i,a,b) for(int i=a;i<=b;i++)

int n,m;

int main()
{
	scanf("%d%d",&n,&m);
	loop(i,1,n)
	{
		if(2*n+1-2*m-2*i>=0)
		{
		loop(j,1,i-1)
		{
			printf(" ");
		}
		loop(j,1,m)
		{
			printf("*");
		}
		loop(j,1,2*n+1-2*m-2*i)
		{
			printf(" ");
		}
		loop(j,1,m)
		{
			printf("*");
		}
		printf("\n");
	    }
	    else if(2*n+1-2*m-2*i<0)
	    {
	    	loop(j,1,i-1)
		    {
			    printf(" ");
		    }
		    loop(j,1,2*n+1-2*i)
		    {
		    	printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}
//by LQ_gdwind
