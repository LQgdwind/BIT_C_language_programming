#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define loop(i,a,b) for(int i=a;i<=b;i++)

int len;
int res,ans,pro;
int cnt;
int n[10];

int main()
{
	scanf("%d",&len);pro=1;
	loop(i,1,len-1)
	{
		pro*=10;
	}
	loop(i,pro,pro*10-1)
	{
		ans=0;
		res=i;
		int t=0;
		while(res)
		{
			n[++t]=res%10;
			res/=10;
		}	
	loop(j,1,len)
	    {
	    	int p=n[j];
		    loop(k,1,len-1)
		    {
		    	n[j]*=p;
			}
	    }
	loop(j,1,len)
	    {
		ans+=n[j];
	    }
	if(ans==i) printf("%d\n",i),cnt++;	
	}
	if(cnt==0) printf("No output.\n");
	return 0;
}
//by LQ_gdwind
