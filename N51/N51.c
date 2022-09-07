#include <stdio.h>  
#include <string.h>  
#include <math.h>  
int x[]={1,2,0,0},y[]={0,0,1,2};  
int i,n,m,q,r,j,k;  
int npx[2005],npy[2005],qpx[2005],qpy[2005],mpxx[5][2005],mpyy[5][3005];
double min(double a,double b)  
{  
    if(a-b>0.001) return b;  
    else return a;  
}  
void init()
{
	scanf("%d %d %d %d",&n,&m,&q,&r);  
}
int main()  
{  
    init();  
    for(i=0;i<n;i++) scanf("%d %d",&npx[i],&npy[i]);  
    for(i=0;i<m;i++)  
    {  
        scanf("%d %d",&mpxx[0][i],&mpyy[0][i]);  
        for(j=0;j<4;j++)  
        {  
            mpxx[j+1][i]=mpxx[0][i]+x[j];  
            mpyy[j+1][i]=mpyy[0][i]+y[j];  
        }  
    }  
    for(i=0;i<q;i++) scanf("%d %d",&qpx[i],&qpy[i]);  
    double mml[5][2005];  
    for(i=0;i<m;i++)  
    {  
        double minn[5]={500000,500000,500000,500000,500000};  
        for(j=0;j<n;j++)  
        {  
            for(k=0;k<5;k++)  
            {  
                minn[k]=min(minn[k],sqrt((mpxx[k][i]-npx[j])*(mpxx[k][i]-npx[j])+(mpyy[k][i]-npy[j])*(mpyy[k][i]-npy[j]))-r);  
            }  
        }  
        for(j=0;j<5;j++) mml[j][i]=minn[j];  
    }  
    for(i=0;i<q;i++)  
    {  
        double now=500000;  
        for(j=0;j<5;j++)  
        {  
            for(k=0;k<m;k++)  
            {  
                if(mpxx[j][k]<=5000&&mpxx[j][k]>=-5000&&mpyy[j][k]<=5000&&mpyy[j][k]>=-5000)  
                {  
                    now=min(now,mml[j][k]+sqrt((qpx[i]-mpxx[j][k])*(qpx[i]-mpxx[j][k])+(qpy[i]-mpyy[j][k])*(qpy[i]-mpyy[j][k])));  
                }  
            }  
        }  
        printf("%.2lf\n",now);  
    }  
    return 0;  
}
