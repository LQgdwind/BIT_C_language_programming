#include<stdio.h>
#include<string.h>
#define go(i,a,b) for(int i=a;i<=b;i++)
char s[20];
int n,a[4000],b[4000],t=0,S,T=0,f;
int main()
{
	while(scanf("%s",s)!=EOF)
	{
		n=strlen(s);
		if(s[1]=='o'&&t)b[++T]=a[t--];
		if(s[1]=='e')
		{
			go(i,1,t-1)printf("%d ",a[i]);
			if(t)printf("%d\n",a[t]);
			else puts("");
		}
		if(s[1]=='u')
		go(i,0,n-1)if(s[i]=='(')
		{
			S=0;
			if(s[i+1]=='-')i++,f=-1;
			else f=1;
			while(s[++i]>47)
			S=S*10+s[i]-48;a[++t]=S*f;break;
		}
	}
	while(t--)b[++T]=a[t+1];
	go(i,1,T-1)printf("%d ",b[i]);
	if(T)printf("%d\n",b[T]);
	return 0;
}
//By LQ_gdwind
