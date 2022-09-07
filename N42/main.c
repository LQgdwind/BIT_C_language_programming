#include<stdio.h>
#define S(a,b) (a^=b^=a^=b)
#define go(i,a,b) for(int i=a;i<=b;i++)
char s[2000],c;
int l,n,c1[20],c2[20],c3[20],x[20],y[20],_,X1,Y1,X2,Y2,d,S;
int M(int a,int b){return a<b?a:b;}
int C(int a,int b){return a*a+b*b;}
int main()
{
	while(scanf("%c",&c)!=EOF)
	{		
		d=2e9;l=n=0;s[++l]=c;
		while((c=getchar())!='\n')s[++l]=c;
		go(i,1,l)
		{
			if(s[i]=='(')c1[++n]=i;
			if(s[i]==',')c2[ n ]=i;
			if(s[i]==')')c3[ n ]=i;
		}
		go(i,1,n)
		{
			_=0;go(j,c1[i]+1,c2[i]-1)_=_*10+s[j]-'0';x[i]=_;
			_=0;go(j,c2[i]+1,c3[i]-1)_=_*10+s[j]-'0';y[i]=_;
		}
		go(x1,1,25)go(y1,1,25)go(x2,1,25)go(y2,1,25)if(x1!=x2||y1!=y2)
		{
			S=0;
			go(i,1,n)S+=M(C(x[i]-x1,y[i]-y1),C(x[i]-x2,y[i]-y2));
			if(S<d)d=S,X1=x1,X2=x2,Y1=y1,Y2=y2;
		}
		Y1=Y1==4?1:Y1; 
		printf("(%d,%d) (%d,%d)\n",X1,Y1,X2,Y2);
	}
    return 0;
}
//By LQ_gdwind
