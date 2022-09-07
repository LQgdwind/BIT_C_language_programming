#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define read(a) (scanf("%d",&a))
#define loop(i,a,b) for(int i=a;i<=b;i++)
int n,d;
double a[20][20];
double b[20][20];
void init()
{
	read(n);
	read(d);
	loop(i,1,n)
	{
		loop(j,1,n)
		{
			scanf("%lf",&a[i][j]);
		}
	}
}
void zhengjiao()
{
	loop(k,1,n)
	{
		b[1][k]=a[1][k];
	}
	loop(i,2,n)
	{
		loop(j,1,i-1)
		{
			double ao=0;
		    double bo=0;
			loop(k,1,d)
			{
				ao+=a[i][k]*b[j][k];
				bo+=b[j][k]*b[j][k];
			}
			double co=ao/bo;
			loop(k,1,d)
			{
				b[i][k]+=co*b[j][k];
			}
		}
		loop(k,1,d)
		{
			b[i][k]=a[i][k]-b[i][k];
		}
	}
}
void guifan()
{
	loop(i,1,n)
	{
		double m=0.0;
		loop(k,1,d)
		{
			m+=b[i][k]*b[i][k];
		}
		m=sqrt(m);
		loop(k,1,d)
		{
			b[i][k]=b[i][k]/m;
		}
	}
}
void print()
{
	loop(i,1,n)
	{
		loop(k,1,d)
		{
			printf("%.2f",b[i][k]);
			if(k!=d)printf(" ");
			else printf("\n");
		}
	}
}
int main ()
{
	init();
	zhengjiao();
	guifan();
	print();
}
//By LQ_gdwind
