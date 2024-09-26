#include <bits/stdc++.h>
using namespace std;

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime; 
    int priority;
    int completionTime;
    int waitingTime;
    int turnAroundTime;
    bool completed;

    Process(int pid, int at, int bt, int pri) {
        id = pid;
        arrivalTime = at;
        burstTime = bt;
        remainingTime = bt;
        priority = pri;
        completionTime = 0;
        waitingTime = 0;
        turnAroundTime = 0;
        completed = false;
    }
};

void visualizeSchedule(int time, int id) {
    cout << "| T" << time << ": P" << id << " ";
}

void FCFS(vector<Process>& processes) {
    cout << "\nFCFS Scheduling:\n";
    int currentTime = 0;
    for (int i = 0; i < processes.size(); i++) {
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }
        visualizeSchedule(currentTime, processes[i].id);
        currentTime += processes[i].burstTime;
        processes[i].completionTime = currentTime;
        processes[i].completed = true;
    }
    cout << "|\n";
}

void SJF_NonPreemptive(vector<Process>& processes) {
    cout << "\nSJF Non-Preemptive Scheduling:\n";
    int currentTime = 0;
    bool allCompleted = false;

    while (!allCompleted) {
        int idx = -1, minBurstTime = INT_MAX;
        allCompleted = true;

        for (int i = 0; i < processes.size(); i++) {
            if (!processes[i].completed) {
                allCompleted = false;  
                if (processes[i].arrivalTime <= currentTime && processes[i].burstTime < minBurstTime) {
                    idx = i;
                    minBurstTime = processes[i].burstTime;
                }
            }
        }

        if (idx != -1) {
            visualizeSchedule(currentTime, processes[idx].id);
            currentTime += processes[idx].burstTime;
            processes[idx].completionTime = currentTime;
            processes[idx].completed = true;
        } else {
            currentTime++;//idle
        }
    }
    cout << "|\n";
}


void SJF_Preemptive(vector<Process>& processes) {
    cout << "\nSJF Preemptive Scheduling:\n";
    int currentTime = 0;
    bool allCompleted = false;

    while (!allCompleted) {
        int idx = -1, minBurstTime = INT_MAX;
        allCompleted = true;

        for (int i = 0; i < processes.size(); i++) {
            if (!processes[i].completed) {
                allCompleted = false;
                if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0 && processes[i].remainingTime < minBurstTime) {
                    idx = i; 
                    minBurstTime = processes[i].remainingTime;
                }
            }
        }

        if (idx != -1) {
            visualizeSchedule(currentTime, processes[idx].id);
            currentTime++;
            processes[idx].remainingTime--;
            if (processes[idx].remainingTime == 0) {
                processes[idx].completionTime = currentTime; 
                processes[idx].completed = true;
            }
        } else {
            currentTime++; 
        }
    }
    cout << "|\n";
}


void Priority_NonPreemptive(vector<Process>& processes) {
    cout << "\nPriority Non-Preemptive Scheduling:\n";
    int currentTime = 0;
    bool allCompleted = false;

    while (!allCompleted) {
        int idx = -1, highestPriority = INT_MAX;
        allCompleted = true;

        for (int i = 0; i < processes.size(); i++) {
            if (!processes[i].completed) {
                allCompleted = false;  
                if (processes[i].arrivalTime <= currentTime && processes[i].priority < highestPriority) {
                    idx = i; 
                    highestPriority = processes[i].priority;
                }
            }
        }

        if (idx != -1) {
            visualizeSchedule(currentTime, processes[idx].id);
            currentTime += processes[idx].burstTime; 
            processes[idx].completionTime = currentTime; 
            processes[idx].completed = true; 
        } else {
            currentTime++; 
        }
    }
    cout << "|\n";
}


void Priority_Preemptive(vector<Process>& processes) {
    cout << "\nPriority Preemptive Scheduling:\n";
    int currentTime = 0;
    bool allCompleted = false;

    while (!allCompleted) {
        int idx = -1, highestPriority = INT_MAX;
        allCompleted = true;

        for (int i = 0; i < processes.size(); i++) {
            if (!processes[i].completed) {
                allCompleted = false;
                if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0 && processes[i].priority < highestPriority) {
                    idx = i; 
                    highestPriority = processes[i].priority;
                }
            }
        }

        if (idx != -1) {
            visualizeSchedule(currentTime, processes[idx].id);
            currentTime++;
            processes[idx].remainingTime--;
            if (processes[idx].remainingTime == 0) {
                processes[idx].completionTime = currentTime; 
                processes[idx].completed = true;
            }
        } else {
            currentTime++; 
        }
    }
    cout << "|\n";
}


void calculateTimes(vector<Process>& processes) {
    for (int i = 0; i < processes.size(); i++) {
        processes[i].turnAroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnAroundTime - processes[i].burstTime;
    }
}


void displayProcesses(const vector<Process>& processes) {
    cout << "\nProcess\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n";
    for (int i = 0; i < processes.size(); i++) {
        cout << "P" << processes[i].id << "\t" 
             << setw(7) << processes[i].arrivalTime << "\t" 
             << setw(5) << processes[i].burstTime << "\t" 
             << setw(8) << processes[i].priority << "\t" 
             << setw(10) << processes[i].completionTime << "\t" 
             << setw(10) << processes[i].turnAroundTime << "\t" 
             << setw(8) << processes[i].waitingTime << "\n";
    }
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes;

    for (int i = 0; i < n; i++) {
        int arrivalTime, burstTime, priority;
        cout << "\nEnter arrival time, burst time, and priority for process " << i + 1 << ": ";
        cin >> arrivalTime >> burstTime >> priority;
        processes.emplace_back(i + 1, arrivalTime, burstTime, priority);
    }

    FCFS(processes);
    calculateTimes(processes);
    displayProcesses(processes);

    for (int i = 0; i < processes.size(); i++) {
        processes[i].completed = false;
        processes[i].remainingTime = processes[i].burstTime;
    }

  
    SJF_NonPreemptive(processes);
    calculateTimes(processes);
    displayProcesses(processes);

    
    for (int i = 0; i < processes.size(); i++) {
        processes[i].completed = false;
        processes[i].remainingTime = processes[i].burstTime;
    }

    SJF_Preemptive(processes);
    calculateTimes(processes);
    displayProcesses(processes);

   
    for (int i = 0; i < processes.size(); i++) {
        processes[i].completed = false;
    }

    
    Priority_NonPreemptive(processes);
    calculateTimes(processes);
    displayProcesses(processes);

    
    for (int i = 0; i < processes.size(); i++) {
        processes[i].completed = false;
        processes[i].remainingTime = processes[i].burstTime;
    }

    Priority_Preemptive(processes);
    calculateTimes(processes);
    displayProcesses(processes);

    return 0;
}
