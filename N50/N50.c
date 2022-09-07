#include <stdio.h>
#include <string.h>
typedef long long ll;
ll above(ll a,ll b)
{
    if(a%b) return (ll)(a/b)+1;
    else return (ll)(a/b);
}
ll h[10005],a[10005];
ll ans=0,w[10005],v[10005],s[10005];
int i,n,j=1,k;
int isp[10005];
int main()
{
    for(i=1;i<10005;i++) isp[i]=1;
    for(i=2;i<10005;i++)
    {
        if(isp[i])
        {
            for(j=2;j*i<10005;j++) isp[i*j]=0;
        }
    }
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%lld",&h[i]);
    for(i=1;i<=n;i++) scanf("%lld",&a[i]);
    s[0]=a[n]*a[n];
    for(i=n,j=1;i>=1;i--,j++)
    {
        v[j]=v[j-1]+a[i]*a[i]*h[i];
        s[j]=s[j-1]+4*h[i]*a[i];
        if(isp[j]) w[j]=above(v[j],s[j]);
        else
        {
            for(k=1;k<=j/2;k++)
            {
                if(j%k==0) w[j]+=w[k]+above(v[k],s[k]);
            }
        }
        ans+=w[j];
    }
    printf("%lld\n",ans);
    return 0;
}
