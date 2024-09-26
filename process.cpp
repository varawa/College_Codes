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
                    idx = i; // Get the process index
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
            currentTime++; // Idle time
        }
    }
    cout << "|\n";
}

// Shortest Job First (Preemptive)
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
                    idx = i; // Get the process index
                    minBurstTime = processes[i].remainingTime;
                }
            }
        }

        if (idx != -1) {
            visualizeSchedule(currentTime, processes[idx].id);
            currentTime++;
            processes[idx].remainingTime--;
            if (processes[idx].remainingTime == 0) {
                processes[idx].completionTime = currentTime; // Update completion time
                processes[idx].completed = true;
            }
        } else {
            currentTime++; // Idle time
        }
    }
    cout << "|\n";
}

// Priority Scheduling (Non-Preemptive)
void Priority_NonPreemptive(vector<Process>& processes) {
    cout << "\nPriority Non-Preemptive Scheduling:\n";
    int currentTime = 0;
    bool allCompleted = false;

    while (!allCompleted) {
        int idx = -1, highestPriority = INT_MAX;
        allCompleted = true;

        for (int i = 0; i < processes.size(); i++) {
            if (!processes[i].completed) {
                allCompleted = false;  // Found at least one incomplete process
                if (processes[i].arrivalTime <= currentTime && processes[i].priority < highestPriority) {
                    idx = i; // Get the process index
                    highestPriority = processes[i].priority;
                }
            }
        }

        if (idx != -1) {
            visualizeSchedule(currentTime, processes[idx].id);
            currentTime += processes[idx].burstTime; // Increment time by burst time
            processes[idx].completionTime = currentTime; // Update completion time
            processes[idx].completed = true; // Mark process as completed
        } else {
            currentTime++; // Idle time
        }
    }
    cout << "|\n";
}


// Priority Scheduling (Preemptive)
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
                    idx = i; // Get the process index
                    highestPriority = processes[i].priority;
                }
            }
        }

        if (idx != -1) {
            visualizeSchedule(currentTime, processes[idx].id);
            currentTime++;
            processes[idx].remainingTime--;
            if (processes[idx].remainingTime == 0) {
                processes[idx].completionTime = currentTime; // Update completion time
                processes[idx].completed = true;
            }
        } else {
            currentTime++; // Idle time
        }
    }
    cout << "|\n";
}

// Calculate Turnaround and Waiting times
void calculateTimes(vector<Process>& processes) {
    for (int i = 0; i < processes.size(); i++) {
        processes[i].turnAroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnAroundTime - processes[i].burstTime;
    }
}

// Display process details
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

    // FCFS Scheduling
    FCFS(processes);
    calculateTimes(processes);
    displayProcesses(processes);

    // Resetting the processes for next scheduling
    for (int i = 0; i < processes.size(); i++) {
        processes[i].completed = false;
        processes[i].remainingTime = processes[i].burstTime;
    }

    // SJF Non-Preemptive Scheduling
    SJF_NonPreemptive(processes);
    calculateTimes(processes);
    displayProcesses(processes);

    // Resetting for SJF Preemptive
    for (int i = 0; i < processes.size(); i++) {
        processes[i].completed = false;
        processes[i].remainingTime = processes[i].burstTime;
    }

    // SJF Preemptive Scheduling
    SJF_Preemptive(processes);
    calculateTimes(processes);
    displayProcesses(processes);

    // Resetting for Priority Non-Preemptive
    for (int i = 0; i < processes.size(); i++) {
        processes[i].completed = false;
    }

    // Priority Non-Preemptive Scheduling
    Priority_NonPreemptive(processes);
    calculateTimes(processes);
    displayProcesses(processes);

    // Resetting for Priority Preemptive
    for (int i = 0; i < processes.size(); i++) {
        processes[i].completed = false;
        processes[i].remainingTime = processes[i].burstTime;
    }

    // Priority Preemptive Scheduling
    Priority_Preemptive(processes);
    calculateTimes(processes);
    displayProcesses(processes);

    return 0;
}
