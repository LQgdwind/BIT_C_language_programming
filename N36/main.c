#include<stdio.h>
typedef long long ll;
int n,T,M=1e5+7,H[100007],B[100007],x,i;
ll a; 
void init()
{
	scanf("%d%d",&n,&T);
}
int main()
{
	init();
	while(n--)
	scanf("%lld%d",&a,&x),i=a%M,H[i]=x,B[i]=1;
	while(T--)
	{
		scanf("%lld%d",&a,&x);
		i=a%M;
		if(B[i])H[i]<x?puts("Failed"):(puts("Succeeded"),H[i]-=x);
		else puts("ERR");
	}
    return 0;
}
//By LQ_gdwind
