#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define loop(i,a,b) for(int i=a;i<=b;i++)

int n,m;
char str[10010];

int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",str);
	int len=strlen(str);
	if(n==1) 
	{
	loop(i,0,m*len-1)
	{
		if((i+1)<=9&&(i+1)>=1) 
		printf("  %d:%c\n",i+1,str[i%len]);
		else if((i+1)<=99&&(i+1)>=10)
		printf(" %d:%c\n",i+1,str[i%len]);
		else if((i+1)<=999&&(i+1)>=100)
		printf("%d:%c\n",i+1,str[i%len]);
	}
	return 0;
	}
	loop(i,0,m*len-1)
	{
		if(i==0) printf("  1:");
		printf("%c",str[i%len]);
		if((i+1)%n==0&&i) printf("\n");
		if(((i+1)%n==0&&i)&&(i!=m*len-1)&&((i+1)/n+1<=9&&(i+1)/n+1>=1)) printf("  %d:",(i+1)/n+1);
		else if(((i+1)%n==0&&i)&&(i!=m*len-1)&&((i+1)/n+1<=99&&(i+1)/n+1>=10)) printf(" %d:",(i+1)/n+1);
		else if(((i+1)%n==0&&i)&&(i!=m*len-1)&&((i+1)/n+1<=999&&(i+1)/n+1>=100)) printf("%d:",(i+1)/n+1);
	}
	if(m*len%n!=0) printf("\n");
	return 0;
}
// by LQ_gdwind
