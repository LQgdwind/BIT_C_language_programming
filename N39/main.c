#include <stdio.h>
#include <stdlib.h>
#define loop(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;
int n,m;
struct POINT
{
	ll a;
	ll b;
}point[10010];
void init()
{
	loop(i,1,n) scanf("%lld%lld",&point[i].a,&point[i].b);
}
int main()
{
	init();
	
}
//By LQ_gdwind
