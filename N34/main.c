#include<math.h> 
#include<stdio.h> 
#define e (2.71828) 
#define go(i,a,b) for(int i=a;i<=b;i++) 
int T(int x) 
{ 
return 2*x*x+(int)(1.0*log(x)*log(x)/log(e)/log(e)); 
} 
int c[10],ans=0,a[4000000],M=3e6+7; 
void init()
{
	go(i,1,4)
	scanf("%d",c+i); 
} 
int main() 
{
	init();
    go(i,1,100)go(j,1,100)
	a[(-c[1]*T(i)-2*c[2]*j+M)%M]++; 
    go(i,1,100)go(j,1,100)
	ans+=a[(c[4]*T(i)+c[3]*j+M)%M]; 
    printf("%d\n",ans);
	return 0; 
}
//By LQ_gdwind
