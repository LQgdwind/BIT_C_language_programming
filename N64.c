/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <string.h>
//请补全函数read,calculate,sort,cmp,swap,david_operate
//存储学生个人信息 
struct s_infos
{
	char name[15];
	char id[11];
};
typedef struct s_infos infos;
//存储学生数据，包括个人信息和分数，其中score[0]存折合总分 
struct s_student{
	infos *info;
	double score[21];
};
typedef struct s_student student;
//给student型变量的成员info指针赋予指向的infos型变量 
void init_struct(int stu_num,infos* info,student* stu);
//读入学生数目，学科数目，学生个人信息及得分 
void read(int* pstu_num,int* psco_num,infos* info,student* stu);
//输出最终结果 
void print(int stu_num,int sco_num,student* stu);
//计算折合总分 
void calculate(int stu_num,int sco_num,student* stu);
//判断学生x和学生y谁排名更靠前，x靠前返回1，否则返回0 
int cmp(student x,student y,int sco_num);
//给学生排名(使用了cmp函数) 
void sort(int stu_num,int sco_num,student* stu);
//David修改排名的核心代码 
void swap(infos* x,infos* y);
//David的代码段，输入要交换的学生学号，并找到其所在的排名 
void init_ope(int stu_num,student* stu,int* pid1,int* pid2);
//David插入到主函数的代码段,作为David代码的入口 
void david_operate(int stu_num,student* stu);
int main()
{
	int stu_num,sco_num;
	infos info[255];
	student stu[255];
	read(&stu_num,&sco_num,info,stu);
	calculate(stu_num,sco_num,stu);
	sort(stu_num,sco_num,stu);
	david_operate(stu_num,stu);
	print(stu_num,sco_num,stu);
	return 0;
}
void init_struct(int stu_num,infos* info,student* stu)
{
	int i,flag=0;
	for (i=0;i<stu_num;i++)
		stu[i].info=&info[flag++];
}

void print(int stu_num,int sco_num,student* stu)
{
	int i,j;
	for (i=0;i<stu_num;i++)
	{
		printf("%s %s\n",stu[i].info->name,stu[i].info->id);
		printf("%.2lf",stu[i].score[0]);
		for (j=1;j<=sco_num;j++)
			printf(" %.2lf",stu[i].score[j]);
		printf("\n");
	}
}

void init_ope(int stu_num,student* stu,int* pid1,int* pid2)
{
	int i;
	char x[22],y[22];
	scanf("%s%s",x,y);
	for (i=0;i<stu_num;i++)
	{
		if (strcmp(x,stu[i].info->id)==0)
			*pid1=i;
		if (strcmp(y,stu[i].info->id)==0)
			*pid2=i;			
	}
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

