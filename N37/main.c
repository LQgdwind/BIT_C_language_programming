#include<stdio.h>
int _(int x,int y)
{
    return x>y?y:x;
}
int n,m,i=1;int a,A,M,R=-1e9;
int main()
{
	scanf("%d%d",&n,&m);
	for(;i<=n;i++)
	scanf("%d",&a),A+=((a==1)*m-1),R=-_(-R,M-A),M=_(M,A);
	printf("%d\n",R);return 0;
}
//By LQ_gdwind
