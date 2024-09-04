#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
    int priority;
};

void completion_time(int n, process p[]) {
    int current_time = 0;
    int min_index = 0;
    int min_priority = 9999;
    int completed = 0;
    bool isRunning = false;

    while (completed != n) {
        isRunning = false;
        min_priority = 9999;
        for (int i = 0; i < n; i++) {
            if (p[i].at <= current_time && p[i].rt > 0) {
                if (p[i].priority < min_priority) {
                    isRunning = true;
                    min_index = i;
                    min_priority = p[i].priority;
                }
            }
        }

        if (isRunning) {
            current_time++;
            p[min_index].rt--;
            if (p[min_index].rt == 0) {
                completed++;
                p[min_index].ct = current_time;
            }
        } else {
            current_time++;
        }
    }
}

void findTurnaroundTime(int n, process p[]) {
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
    }
}

void findWaitingTime(int n, process p[]) {
    for (int i = 0; i < n; i++) {
        p[i].wt = p[i].tat - p[i].bt;
    }
}

void calculateAverageTimes(int n, process p[], double& avg_tat, double& avg_wt) {
    double total_tat = 0;
    double total_wt = 0;
    
    for (int i = 0; i < n; i++) {
        total_tat += p[i].tat;
        total_wt += p[i].wt;
    }
    
    avg_tat = total_tat / n;
    avg_wt = total_wt / n;
}

void printProcessInfo(int n, process p[]) {
    cout << "PID\tAT\tBT\tPriority\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << p[i].pid << "\t" << p[i].at << "\t" << p[i].bt << "\t" << p[i].priority << "\t\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << "\n";
    }
}

int main() {
    process p[] = {
        {1, 0, 4, 0, 0, 0, 4, 2},
        {2, 1, 3, 0, 0, 0, 3, 1},
        {3, 2, 1, 0, 0, 0, 1, 3},
        {4, 3, 2, 0, 0, 0, 2, 4}
    };

    int n = sizeof(p) / sizeof(p[0]);

    completion_time(n, p);
    findTurnaroundTime(n, p);
    findWaitingTime(n, p);

    double avg_tat, avg_wt;
    calculateAverageTimes(n, p, avg_tat, avg_wt);

    printProcessInfo(n, p);

    cout << "Average Turnaround Time: " << avg_tat << endl;
    cout << "Average Waiting Time: " << avg_wt << endl;

    return 0;
}
