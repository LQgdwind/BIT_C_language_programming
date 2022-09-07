#include <stdio.h>
#include <string.h>
int n;
int a[105];
int t,k;
int main()
{
    scanf("%d",&n);
    while(~scanf("%d %d",&t,&k))
    {
        int j,min=100000000,kk;
        for(j=0;j<n;j++)
        {
            if(a[j]<min)
            {
                kk=j;
                min=a[j];
            }
        }
        if(t>min) {a[kk]=t+k;printf("%d\n",t);}
        else
        {
            printf("%d\n",min);
            a[kk]=min+k;
        }
    }
    return 0;
}
