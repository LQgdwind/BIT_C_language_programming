#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define loop(i,a,b) for(int i=a;i<=b;i++)

struct m
{
	char id[10];
	double score1;
	double score2;
	double total;
	char mark[2];
};
typedef struct m NODE;
NODE student[8010];


int n;

int cmp(const void *a,const void *b)
{
	double op= (*(NODE*)a).total;
	double op2=(*(NODE*)b).total;
	if (fabs(op-op2)<=0.001)
	{
		char *nmb=(*(NODE*)a).id;
		char *nmb2=(*(NODE*)b).id;
		loop(i,0,7)
		{
			if(nmb[i]>nmb2[i]) return 1;
			else if(nmb[i]<nmb2[i]) return -1;
		}
	}
	else if(op>op2) return -1;
	else return 1;
}
int main()
{
	scanf("%d",&n);
	loop(i,1,n)
	{
		scanf("%s%lf%lf",student[i].id,&student[i].score1,&student[i].score2);
		student[i].total=0.2*student[i].score2+0.8*student[i].score1;
		if (student[i].total>90||fabs(student[i].total-90)<=0.00001)
		{
			student[i].mark[0]='Y';
		}
		else student[i].mark[0]='N';
	}
	qsort(student+1,n,sizeof(student[0]),cmp);
	loop(i,1,n)
	{
		if(student[i].total)
		{
			printf("%s %.2f %.2f %.3f %c\n",student[i].id,student[i].score1,student[i].score2,student[i].total,student[i].mark[0]);
		}
	}
	
	return 0;
}
