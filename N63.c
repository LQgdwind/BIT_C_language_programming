#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define loop(i,a,b) for(int i=a;i<=b;i++)
#define N 10010
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)

int n,m;
int a[N][10];

int res[7];
int ans=0x3f3f3f3f;
 
int main()
{
	scanf("%d",&m);
	while(m--)
	{
	memset(a,0,sizeof a);
	memset(res,0,sizeof res);
	ans=0x3f3f3f3f;
	scanf("%d",&n);
	loop(i,1,n)
	{
		loop(j,1,6)
		{
			scanf("%d",*(a+i)+j);
		}
	}
	loop(i,1,n)
	{
		res[1]=max(res[1],a[i][1]);
		res[2]=max(res[2],a[i][2]);
		res[3]=max(res[3],a[i][3]);
		res[4]=max(res[4],a[i][4]);
		res[5]=max(res[5],a[i][5]);
		res[6]=max(res[6],a[i][6]);
	}
	loop(i,1,6)
	{
		ans=min(ans,res[i]);
	}
	printf("%d\n",ans);
    }
}
