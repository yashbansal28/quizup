//SJF
#include<stdio.h>

int min(int a[][6] ,int n,int t)
{
int i, m=0;
for(i=0;i<n;i++)
    {
        //find minimum burst time
        if(a[i][1]<a[m][1] && a[i][0]<=t)
            m=i;
        //if 2 process have equal burst time
        else if(a[i][1]==a[m][1]&& a[i][0]<=t)
        {

               if(a[i][0]<a[m][0])
                m=i;
        }
    }
    //if processor is idle
    if(a[m][0]>t )
        return -1;
return m;
}

int main()
{
int i,n,x,e=0,t=0;
float tat=0,wt=0;
printf("input no of process");
scanf("%d",&n);
int p[n][6],b[n];
for(i=0;i<n;i++)
    {
        printf("input arrival and burst time of process %d:  ",i+1);
        scanf("%d%d",&p[i][0],&p[i][1]);
        b[i]=p[i][1];
    }

while(e<n)
{
    
    x=min(p,n,t);
   if(x>=0)
   {
    e++;
    t+=p[x][1];
    p[x][2]=t;
    p[x][1]=1000;
    
  
   }
   else t++;
    
}
for(i=0;i<n;i++)
{
    p[i][1]=b[i];
}

printf("\nat\tbt\tct\ttat\twt\n");
for(i=0;i<n;i++)
{
    p[i][3]=p[i][2]-p[i][0];
    p[i][4]=p[i][3]-p[i][1];
    tat+=p[i][2]-p[i][0];
    wt+=p[i][2]-p[i][0]-p[i][1];
   for(int j=0;j<5;j++)
        printf("%d\t",p[i][j]);
    printf("\n");
}
 printf("\ncontact switch=%d\naverage tat=%f\naverage wt=%f\n",n-1,tat/n,wt/n);
}