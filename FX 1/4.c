#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define loop(i,a,b) for(int i=a;i<=b;i++)
#define read(a) (scanf("%d",&a))

typedef long long ll;
typedef double db;

char s[1010];
char p[1010][1010];
int cnt1,cnt2,res,t;
int record[1010];

int judge(char *x)
{
	if ((x[0]<='Z'&&x[0]>='A')||(x[0]>='a'&&x[0]<='z')||x[0]=='_') return 1;
	else return 0;
}

int main()
{
	gets(s);
	int len=strlen(s);
	loop(i,0,len-1)
	{
		if(((s[i]<='Z'&&s[i]>='A')||(s[i]>='a'&&s[i]<='z')||s[i]=='_'||(s[i]<='9'&&s[i]>='0')))
		{
			p[cnt1][cnt2++]=s[i];
		}
		else cnt1++,cnt2=0;
	}
	loop(i,0,cnt1)
	{
		loop(j,0,cnt1)
		{
			if(strcmp(p[i],p[j])==0) record[i]++;
		}
	}
	loop(i,0,cnt1)
	{
		if(record[i]>t&&(judge(p[i])))
		{
			res=i;
			t=record[i];
		}
	}
	if(t==0) printf("No identifier!\n");
	else printf("%s\n",p[res]);
}
//by LQ_gdwind
