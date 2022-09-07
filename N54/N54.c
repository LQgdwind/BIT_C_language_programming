#include <stdio.h>       
#include <string.h>       
#include <math.h>    
typedef long long ll;   
ll ans,now;
ll a[25],vis[25];
ll isp[20000];  
ll fac(ll k)
{
    ll i,ans=1;
    for(i=2;i<=k;i++) ans*=i;
    return ans;
}
ll jina(ll a)
{
    ll t=sqrt(a);
    if(t*t==a&&isp[t]) return 1;
    else return 0;
}   
void dfs(ll p,ll ha,ll tot,ll n)
{
    if(ha==tot)
    {
        if(jina(now)) ans++;
        return;
    }
    if(p==n) return;
    dfs(p+1,ha,tot,n);
    now+=a[p];
    dfs(p+1,ha+1,tot,n);
    now-=a[p];
    return;
}
ll i,j; 
ll n,k;
int main()       
{       
    isp[0]=0;isp[1]=1;       
    for(i=2;i<20000;i++) isp[i]=1;       
    for(i=2;i<20000;i++)       
    {       
        for(j=2;i*j<20000;j++) isp[i*j]=0;       
    }   
    while(~scanf("%lld %lld",&n,&k))
    {
        ans=0;now=0;
        memset(a,0,sizeof(a));
        memset(vis,0,sizeof(vis));
        for(i=0;i<n;i++) {scanf("%lld",&a[i]);}
        dfs(0,0,k,n);
        printf("%lld\n",ans);
    }
    return 0;       
}  

