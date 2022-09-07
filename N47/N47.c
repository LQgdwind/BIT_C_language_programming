#include <stdio.h>
#include <string.h>
struct node
{
    int na;
    int p1;
    int p0;
    char c1;
    char c0;  
}a[6005];
int is[6005];
char s[20];
 int i,j,n,m,q,l;
int main()
{
    scanf("%d %d %d",&n,&m,&q);
    for(i=0;i<n;i++)
    {
        a[i].c1='0';
        a[i].c0='0';
        a[i].p1=0;
        a[i].p0=0;
    }
    getchar();
    for(i=0;i<n;i++)
    {
        memset(s,0,sizeof(s));
        gets(s);
        l=strlen(s);
        j=0;
        if(s[0]=='N'||s[0]=='Y') {a[i].c1=s[0];j++;}
        else
        {
            int now=0;
            while(s[j]!=' ')
            {
                int llk=s[j]-'0';
                now=now*10+llk;
                j++;
            }
            a[i].p1=now;
        }
        j++;
        if(s[j]=='N'||s[j]=='Y') {a[i].c0=s[j];}
        else
        {
            int now=0;
            while(j<l)
            {
                now=now*10+s[j]-'0';
                j++;
            }
            a[i].p0=now;
        }
    }
    for(i=0;i<n;i++)
    {
        if(i) scanf(" %d",&(a[i].na));
        else scanf("%d",&a[i].na);
    }
    for(i=0;i<q;i++)
    {
        char c;
        memset(is,0,sizeof(is));
        for(j=1;j<=m;j++)
        {
            scanf("%d",&is[j]);
        }
        getchar();
        scanf("%c",&c);
        int mm=0;
        char ans='0';
        while(ans=='0')
        {
            int dd=is[a[mm].na];
            if(dd==1)
            {
                if(a[mm].p1!=0) mm=a[mm].p1-1;
                else ans=a[mm].c1;
            }
            else
            {
                if(a[mm].p0!=0) mm=a[mm].p0-1;
                else ans=a[mm].c0;
            }
        }
        if(ans==c) printf("right\n");
        else printf("wrong\n");
    }
    return 0;
}
