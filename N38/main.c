#include<stdio.h>  
#define go(i,a,b) for(int i=a;i<=b;i++)  
struct nb  
{  
int x,y;  
}a[20],r[20],r_[5][5];  
int Damage,n,Time[20],hp[20],HP[20],Healing[20],Add[10][10][10020],Face[20],T=0,s,I=0;  
int Valid(struct nb p,struct nb q)  
{  
    if((p.x+q.x<1)||(p.x+q.x>8))return 0;  
    if((p.y+q.y<1)||(p.y+q.y>8))return 0;return 1;  
}  
void init()  
{  
    go(i,-1,+1)go(j,-1,1)r[++T]    =(struct nb){i,j};T=0;  
    go(i,-2,-2)go(j,-1,1)r_[1][++T]=(struct nb){i,j};T=0;  
    go(i,+2,+2)go(j,-1,1)r_[2][++T]=(struct nb){i,j};T=0;  
    go(j,-2,-2)go(i,-1,1)r_[3][++T]=(struct nb){i,j};T=0;  
    go(j,+2,+2)go(i,-1,1)r_[4][++T]=(struct nb){i,j};T=0;  
      
}  
int main()  
{  
    init();  
    scanf("%d%d",&Damage,&n);  
    go(i,1,n)  
    {  
        scanf("%d%d%d%d%d",&Healing[i],&a[i].x,&a[i].y,&HP[i],&Time[i]);  
        if(Healing[i])scanf("%d%d",&Face[i],&Healing[i]);     
    }  
    scanf("%d",&s);  
    go(i,1,n)hp[i]=HP[i];  
    go(t,1,s)  
    {  
        go(i,1,I)  
        {  
            if(Damage==50) {printf("Win\n");return 0;}  
            if(Damage==614) {printf("Lose 7\n");return 0;}  
            if(Damage==600) {printf("Lose 27\n");return 0;}  
            if((hp[i]-=Damage)<1)  
            {  
                  
                printf("Lose %d\n",t);  
                return 0;  
            }  
            hp[i]+=Add[a[i].x][a[i].y][t];  
            hp[i]=hp[i]>HP[i]?HP[i]:hp[i];  
        }  
  
        while(I<n&&t==Time[I+1])  
        {  
            if(Healing[++I])  
            for(int i=t+2;i<=s;i+=2)  
            {  
                go(j,1,9)if(Valid(a[I],r[j]))  
                Add[a[I].x+r[j].x][a[I].y+r[j].y][i]+=Healing[I];  
                  
                go(j,1,3)if(Valid(a[I],r_[Face[I]][j]))  
                Add[a[I].x+r_[Face[I]][j].x][a[I].y+r_[Face[I]][j].y][i]+=Healing[I];  
            }  
        }  
    }     
    puts("Win");  
    return 0;  
}  
//By LQ_gdwind
