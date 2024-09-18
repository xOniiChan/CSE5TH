#include<iostream>
using namespace std;

struct process {
int id;
int AT,BT,TAT,WT,RT;
sort(struct process p[],int n) {
struct process temp;

{
for (int i=0;i<n-1;i++)
  for(int j=0;j<n;j++) {
if (p[i].AT>p[j].AT){
temp=p[i];
p[i]=p[j];
p[j]=temp;
}
  }
}

void RR(struct process p[p],int n; int TQ){
  int CT=0;
int completed=0;
int ready[n];
int front=0;
int rear =0;

for (int i=0;i<n;i++)
{
ready[rear]=i;
rear++;
}


CT=p[0].AT;


while(completed<n){
int min_id=front=;
front=(front+1)mod n;

if (p[min_id].RT>0)
  if(p[min_id].RT>TQ)
    CT=CT+TQ;
p[min_id].RT=p[min_id].RT-TQ;
rear=(rear+1)mod n;
ready[rear]=min_id;
}

else completed++;
CT=CT+p[min_id].RT;
p[min_id]-RT=0;
front=(front+1)mod n;
p[min_id].TAT=CT-p[min_id].AT;
p[min_id].WT=p[min_id].TAT-p[min_id].BT;

