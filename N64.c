/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
#include <string.h>
//�벹ȫ����read,calculate,sort,cmp,swap,david_operate
//�洢ѧ��������Ϣ 
struct s_infos
{
	char name[15];
	char id[11];
};
typedef struct s_infos infos;
//�洢ѧ�����ݣ�����������Ϣ�ͷ���������score[0]���ۺ��ܷ� 
struct s_student{
	infos *info;
	double score[21];
};
typedef struct s_student student;
//��student�ͱ����ĳ�Աinfoָ�븳��ָ���infos�ͱ��� 
void init_struct(int stu_num,infos* info,student* stu);
//����ѧ����Ŀ��ѧ����Ŀ��ѧ��������Ϣ���÷� 
void read(int* pstu_num,int* psco_num,infos* info,student* stu);
//������ս�� 
void print(int stu_num,int sco_num,student* stu);
//�����ۺ��ܷ� 
void calculate(int stu_num,int sco_num,student* stu);
//�ж�ѧ��x��ѧ��y˭��������ǰ��x��ǰ����1�����򷵻�0 
int cmp(student x,student y,int sco_num);
//��ѧ������(ʹ����cmp����) 
void sort(int stu_num,int sco_num,student* stu);
//David�޸������ĺ��Ĵ��� 
void swap(infos* x,infos* y);
//David�Ĵ���Σ�����Ҫ������ѧ��ѧ�ţ����ҵ������ڵ����� 
void init_ope(int stu_num,student* stu,int* pid1,int* pid2);
//David���뵽�������Ĵ����,��ΪDavid�������� 
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

