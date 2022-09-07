#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define loop(i,a,b) for(db i=a;i>=b;i--)
#define read(a) (scanf("%d",&a))

typedef long long ll;
typedef double db;
typedef unsigned char unchar;

db n,m;

int cnt=0;

int main()
{
	scanf("%lf%lf",&n,&m);
	loop(i,n,0)
	loop(j,n,0)
	{
		db k=n-i-j;if(k<0)continue;if(i*12+j*3.4+2.3*k==m) printf("%.0f %.0f %.0f\n",i,j,k),cnt++;
	}
	if(cnt==0) printf("Error!\n");
	return 0;
}
//by LQ_gdwind
