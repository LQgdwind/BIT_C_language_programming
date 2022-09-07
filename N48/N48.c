#include <stdio.h>       
#include <string.h>       
#include <math.h>    
typedef long long ll;   
ll j,i,isp[200000];
ll x;        
int main()       
{      
    isp[0]=0;isp[1]=1;       
    for(i=2;i<200000;i++) isp[i]=1;       
    for(i=2;i<200000;i++)       
    {       
        for(j=2;i*j<200000;j++) isp[i*j]=0;       
    }          
    while(~scanf("%lld",&x))       
    {       
        ll a=sqrt(x);      
        if((a-1)*(a-1)==x) {a=a-1;}      
        if((a+1)*(a+1)==x) {a=a+1;}       
        if(a*a==x)       
        {       
            if(isp[a]) {puts("TQL!");}      
            else {puts("TCL!");    
            }      
        }       
        else {puts("TCL!");}       
    }       
    return 0;       
}
