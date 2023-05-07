#include<stdio.h>
 
int main()
{
 
  int cnt,j,n,t,remain,flag=0,tq;
  int wt=0,tat=0,at[10],bt[10],rt[10];
  printf("Enter Total Process:\t ");
  scanf("%d",&n);
  remain=n;
  for(cnt=0;cnt<n;cnt++)
  {
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",cnt+1);
    scanf("%d",&at[cnt]);
    scanf("%d",&bt[cnt]);
    rt[cnt]=bt[cnt];
  }
  printf("Enter Time Quantum:\t");
  scanf("%d",&tq);
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");
  for(t=0,cnt=0;remain!=0;)
  {
    if(rt[cnt]<=tq && rt[cnt]>0)
    {
      t+=rt[cnt];
      rt[cnt]=0;
      flag=1;
    }
    else if(rt[cnt]>0)
    {
      rt[cnt]-=tq;
      t+=tq;
    }
    if(rt[cnt]==0 && flag==1)
    {
      remain--;
      printf("P[%d]\t|\t%d\t|\t%d\n",cnt+1,t-at[cnt],t-at[cnt]-bt[cnt]);
      wt+=t-at[cnt]-bt[cnt];
      tat+=t-at[cnt];
      flag=0;
    }
    if(cnt==n-1)
      cnt=0;
    else if(at[cnt+1]<=t)
      cnt++;
    else
      cnt=0;
  }
  printf("\nAverage Waiting Time= %f\n",wt*1.0/n);
  printf("Avg Turnaround Time = %f",tat*1.0/n);
  
  return 0;
}



output :
Enter Total Process:     4
Enter Arrival Time and Burst Time for Process Process Number 1 :0  5 
Enter Arrival Time and Burst Time for Process Process Number 2 :1  4 
Enter Arrival Time and Burst Time for Process Process Number 3 :2  2
Enter Arrival Time and Burst Time for Process Process Number 4 :4  1
Enter Time Quantum:     2


Process |Turnaround Time|Waiting Time

P[3]    |       4       |       2
P[4]    |       3       |       2
P[2]    |       10      |       6
P[1]    |       12      |       7

Average Waiting Time= 4.250000
Avg Turnaround Time = 7.250000
