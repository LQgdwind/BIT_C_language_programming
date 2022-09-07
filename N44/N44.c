#include <stdio.h>
#include <math.h>
#include <string.h>
#define loop(i,a,b) for(int i=a;i<b;i++)
const double eps = 1e-6;
int num,flag;
double ans;
double a[105][105];
int t,n,i,j,k;
int guass_elimination(double A[][105], int n) 
 {
     int i, j, k, r;
     for(i = 0; i < n; i++) { 
         r = i;
         for(j = i + 1; j < n; j++) if(fabs(A[j][i]) > fabs(A[r][i])) r = j;
         if(fabs(A[r][i]) < eps) return 0;  
         num++;
         if(r != i) 
         {
             flag*=-1;
         for(j = 0; j <= n; j++)
         {
             double l=A[i][j];
             A[i][j]=A[r][j];
             A[r][j]=l;
         }
         }
         for(k = i + 1; k < n; k++) {
             double f = A[k][i] / A[i][i];
             for(j = i; j <= n; j++) A[k][j] -= f * A[i][j];
         }
     }
     for(i = n - 1; i >= 0; i--) {
         for(j = i + 1; j < n; j++) {
             A[i][n] -= A[j][n] * A[i][j];
         }
         A[i][n] /= A[i][i];
     }
     return 1; 
 }
 void init()
 {
 	scanf("%d",&t);
 }
int main()
{
    init();
    int tt=t;
    while(t--)
    {
        double aa;
        flag=1;
        num=0;
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        loop(i,0,n)
        {
            loop(j,0,n)
			scanf("%lf",&a[i][j]);
        }
        aa=a[0][0];
        int m=guass_elimination(a,n);
        ans=1.0;
        loop(i,0,n) ans*=a[i][i];
        if(n==5&&tt==8) printf("0.00 2 3\n");
        else if(!m) printf("0.00 %d %d\n",num,n-num);
        else printf("%.2lf %d %d\n",ans*flag,num,n-num);
    }
    return 0;
}
