#include <stdio.h>
#include <string.h>
char s[1005][1005];
char s1[100000],s2[100000];
int vis[1005][1005];
struct node
{
    char c;
    int f;
    int x,y;  
};
struct node p[1000005];
int yy[]={0,-1,1,0},xx[]={1,0,0,-1};
int main()
{
    int m,n;
    int i,j,k;
    int x0,y0;
    for(i=0;i<=1005;i++)
    {
        for(j=0;j<=1005;j++) s[i][j]='#';
    }
    scanf("%d %d",&n,&m);
    getchar();
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%c",&s[i][j]);
            if(s[i][j]=='S')
            {
                x0=i;y0=j;
            }
        }
        getchar();
    }
    p[0].x=x0;p[0].y=y0;p[0].f=-1;
    vis[x0][y0]=1;
    i=0;j=0,k=0;
    int ans=-1;
    char lc;
    int flag=0;
    while(i<=j)
    {
        for(k=0;k<4;k++)
        {
            if(s[p[i].x+xx[k]][p[i].y+yy[k]]!='#'&&(!vis[p[i].x+xx[k]][p[i].y+yy[k]]))
            {
                if(s[p[i].x+xx[k]][p[i].y+yy[k]]=='1')
                {
                    ans=i;
                    if(k==0) lc='D';
                    else if(k==1) lc='L';
                    else if(k==2) lc='R';
                    else lc='U';
                    flag=1;break;
                }
                else
                {
                    j++;
                    p[j].x=p[i].x+xx[k];
                    p[j].y=p[i].y+yy[k];
                    if(k==0) p[j].c='D';
                    else if(k==1) p[j].c='L';
                    else if(k==2) p[j].c='R';
                    else p[j].c='U';
                    p[j].f=i;
                    vis[p[j].x][p[j].y]=1;
                }
            }
        }
        if(flag) break;
        i++;
    }
    k=0;
    if(ans==-1) printf("-1\n");
    else
    {
        while(p[i].f!=-1)
        {
            s1[k++]=p[i].c;
            i=p[i].f;
        }
        for(j=k-1;j>=0;j--) putchar(s1[j]);
        putchar(lc);putchar('\n');
    }
    memset(p,0,sizeof(p));
    memset(vis,0,sizeof(vis));
    p[0].x=x0;p[0].y=y0;p[0].f=-1;
    vis[x0][y0]=1;
    i=0;j=0,k=0;
    ans=-1;
    flag=0;
    while(i<=j)
    {
        for(k=0;k<4;k++)
        {
            if(s[p[i].x+xx[k]][p[i].y+yy[k]]!='#'&&(!vis[p[i].x+xx[k]][p[i].y+yy[k]]))
            {
                if(s[p[i].x+xx[k]][p[i].y+yy[k]]=='2')
                {
                    ans=i;
                    if(k==0) lc='D';
                    else if(k==1) lc='L';
                    else if(k==2) lc='R';
                    else lc='U';
                    flag=1;break;
                }
                else
                {
                    j++;
                    p[j].x=p[i].x+xx[k];
                    p[j].y=p[i].y+yy[k];
                    if(k==0) p[j].c='D';
                    else if(k==1) p[j].c='L';
                    else if(k==2) p[j].c='R';
                    else p[j].c='U';
                    p[j].f=i;
                    vis[p[j].x][p[j].y]=1;
                }
            }
        }
        if(flag) break;
        i++;
    }
    k=0;
    if(ans==-1) printf("-1\n");
    else
    {
        while(p[i].f!=-1)
        {
            s2[k++]=p[i].c;
            i=p[i].f;
        }
        for(j=k-1;j>=0;j--) putchar(s2[j]);
        putchar(lc);putchar('\n');
    }
    return 0;
}
