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




















////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

struct process {
    int id;
    int AT;
    int BT;
    int TAT;
    int WT;
    int RT;
};

void sort(process p[], int n) {
    process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].AT > p[j].AT) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}

void RR(process p[], int n, int TQ) {
    int CT = 0;
    int completed = 0;
    int front = 0;
    int rear = 0;
    int ready[n];

    for (int i = 0; i < n; i++) {
        p[i].RT = p[i].BT;
    }

    for (int i = 0; i < n; i++) {
        ready[rear++] = i;
    }

    CT = p[0].AT;

    while (completed < n) {
        int min_id = ready[front++];
        if (front >= rear) {
            front = 0;
        }

        if (p[min_id].RT > 0) {
            if (p[min_id].RT > TQ) {
                CT += TQ;
                p[min_id].RT -= TQ;
            } else {
                CT += p[min_id].RT;
                p[min_id].RT = 0;
                completed++;
                p[min_id].TAT = CT - p[min_id].AT;
                p[min_id].WT = p[min_id].TAT - p[min_id].BT;
            }
            if (p[min_id].RT > 0) {
                ready[rear++] = min_id;
                if (rear >= n) {
                    rear = 0;
                }
            }
        }
    }
}

void printProcesses(process p[], int n) {
    cout << "Process ID\tArrival Time\tBurst Time\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].id << "\t\t" << p[i].AT << "\t\t" 
             << p[i].BT << "\t\t" << p[i].TAT << "\t\t" << p[i].WT << "\n";
    }
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    process p[n];

    for (int i = 0; i < n; i++) {
        cout << "Enter Arrival Time and Burst Time for process " << (i + 1) << ": ";
        cin >> p[i].AT >> p[i].BT;
        p[i].id = i + 1;
    }

    int TQ;
    cout << "Enter Time Quantum: ";
    cin >> TQ;

    sort(p, n);
    RR(p, n, TQ);
    printProcesses(p, n);

    return 0;
}

