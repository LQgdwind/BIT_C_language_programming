#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char c;
char s[1000];
int i=0,a[100000],j,k,ii=0;
int main()
{
    gets(s);
    int l=strlen(s);
    while(ii<l)
    {
        int ans=0;
        if(s[ii]=='-') break;
        while(s[ii]!=' '&&ii<l)
        {
            ans=ans*10+s[ii]-'0';
            ii++;
        }
        ii++;
        a[i++]=ans;
    }
    scanf("%c",&c);
    int p=i;
    j=0;
    int t=i;
    while(t!=1&&t!=0)
    {
        t=0;
        for(;j<i-1;j++)
        {
            for(k=j+1;k<i;k++)
            {
                int s,mm,flag=1;
                if(c=='^') {mm=a[j]^a[k];}
                else mm=a[j]|a[k];
                for(s=0;s<p;s++)
                {
                    if(mm==a[s])
                    {
                        flag=0;break;
                    }
                }
                if(flag)
                {
                    t++;
                    a[p++]=mm;
                }
            }
        }
        j=i;
        i=p;
    }
    int now;
    int nmsl=0;
    a[i++]=0;
    while(~scanf("%d",&now))
    {
        if(nmsl++) putchar(' ');
        for(j=0;j<i;j++)
        {
            if(now==a[j])
            {
                printf("1");
                break;
            }
        }
        if(j==i) printf("0");
    }
    putchar('\n');
    return 0;
}
