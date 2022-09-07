#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
struct NUMBER
{
	char num[10];
	char backup[10];
	int len;
	int jinzhi;
	long long val;
}number[110];

long long pow1(int x,int y)
{
	long long p=1;
	for(int i=1;i<y;i++)
	{
		p*=x;
	}
	return p;
}

int transform(char x)
{
	if(x>=48&&x<=57)
	{
		return x-48;
	}
	else 
	{
		return x-87;
	}
}

void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",number[i].num+1);
		number[i].len=strlen(number[i].num+1);
		for(int j=1;j<=number[i].len;j++)
		{
			number[i].backup[j]=number[i].num[number[i].len+1-j];
		}
		scanf("%d",&number[i].jinzhi);
	}
}

int cmp(const void *a,const void *b)
{
	if ((*(struct NUMBER*)a).jinzhi != (*(struct NUMBER*)b).jinzhi)
	return -(*(struct NUMBER*)a).jinzhi + (*(struct NUMBER*)b).jinzhi;
	else 
	return -(*(struct NUMBER*)a).val + (*(struct NUMBER*)b).val;
}

int main()
{
	memset(number,0,sizeof number);
	init();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=number[i].len;j++)
		{
			number[i].val+=transform(number[i].backup[j])*pow1(number[i].jinzhi,j);
		}
	}
	qsort(number+1,100000000000,sizeof(struct NUMBER),cmp);
	for(int i=1;i<=n;i++)
	{
		printf("%lld %d\n",number[i].val,number[i].jinzhi);
	}
}
//By LQ_gdwind
