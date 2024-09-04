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
            min_priority = p[min_index].priority;

            if (p[min_index].rt == 0) {
                completed++;
                p[min_index].ct = current_time;
                isRunning = false;
                min_priority = 9999;
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

void findAverageWaitingTime(int n, process p[]) {
    for (int i = 0; i < n; i++) {
        p[i].wt = p[i].tat - p[i].bt;
    }
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
    printProcessInfo(n, p);

    return 0;
}