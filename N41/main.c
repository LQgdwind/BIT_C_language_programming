#include<stdio.h>  
#include<string.h>  
#define _(a,b) (a^=b^=a^=b)  
#define go(i,a,b) for(int i=a;i<=b;i++)  
char a[20][100];
int n,l,b[20];  
int main()  
{  
    while(scanf("%s",a[++n])!=EOF)  
    {  
        b[n]=n;l=strlen(a[n]);  
        go(i,0,l-2)  
        go(j,i+1,l-1)if(a[n][i]>a[n][j])_(a[n][i],a[n][j]);  
    }  
    n--;
	go(i,1,n-1)
	go(j,i+1,n)  
    if(a[b[i]][0]<a[b[j]][0]||((a[b[i]][0]==a[b[j]][0])&&b[i]>b[j]))_(b[i],b[j]);  
    go(i,1,n)puts(a[b[i]]);
	return 0;               
}
//By LQ_gdwind
