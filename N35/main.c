#include<stdio.h>
#include<string.h>
#define go(i,a,b) for(int i=a;i<=b;i++)
int T,a[2000],L,l,M[2000],D[2000],z;char s[2000]; 
char E[2000]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f','T','I','B'};
void init()
{
	go(i,0,9)D[i+48]=i;
	go(i,0,5)D[i+97]=10+i;
	D['T']=16;D['I']=17;D['B']=18;
	scanf("%d",&T);
}
void C(int _)
{
	int r=0,t;go(i,1,18)
	{
		t=19-i;M[t]=M[t]+r+_*a[t];r=0;
		if(M[t]>i)M[t]-=(i+1),r= 1;
		if(M[t]<0)M[t]+=(i+1),r=-1;
	}
}
int main()
{
	init();
	while(T--)
	{
		go(i,1,18)M[i]=0;
		scanf("%s",s);
		L=strlen(s);
		l=s[0]=='-'? 1:0;z=1;
		go(k,l,L-1)if(s[k]=='+'||s[k]=='-')
		{
			go(i,1,18) a[i]=0;
			go(i,19-k+l,18) a[i]=D[s[i-19+k]];
			C(s[0]=='-'?-1:1);
			go(i,1,18) a[i]=0;
			go(i,20-L+k,18)
			a[i]=D[s[L+i-19]];
			C(s[k]=='-'?-1:1);
			go(k,1,18)
			if(M[k]) 
			{	
			    go(i,k,18)
			    putchar(E[M[i]]);
		        z=0;
			    break;
			}
			if(z)puts("0");
			else puts("");break;		
		}	
	}
    return 0;
}
//By LQ_gdwind
