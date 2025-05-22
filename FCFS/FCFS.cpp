#include <iostream>
#include <algorithm>  // For sorting based on arrival time
using namespace std;

int main() {
    int n;

    // Step 1: Input number of processes
    cout << "Enter the number of processes: ";
    cin >> n;

    // Step 2: Declare arrays to store arrival times, burst times, and calculate waiting and turnaround times
    int arrival[n], burst[n], waiting[n], turnaround[n];

    // Step 3: Input arrival time and burst time for each process
    cout << "Enter arrival times and burst times for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << " Arrival Time: ";
        cin >> arrival[i];
        cout << "Process " << i + 1 << " Burst Time: ";
        cin >> burst[i];
    }

    // Step 4: Sort processes by arrival time (Simple Bubble Sort for illustration)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arrival[j] > arrival[j + 1]) {
                // Swap arrival times
                swap(arrival[j], arrival[j + 1]);
                // Swap burst times accordingly
                swap(burst[j], burst[j + 1]);
            }
        }
    }

    // Step 5: Calculate waiting time for each process
    waiting[0] = 0;  // First process has 0 waiting time

    // Calculate waiting time for all processes
    for (int i = 1; i < n; i++) {
        waiting[i] = waiting[i - 1] + burst[i - 1] + arrival[i - 1] - arrival[i];
    }

    // Step 6: Calculate turnaround time for each process (waiting time + burst time)
    for (int i = 0; i < n; i++) {
        turnaround[i] = waiting[i] + burst[i];
    }

    // Step 7: Calculate total waiting time and total turnaround time
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waiting[i];
        totalTurnaroundTime += turnaround[i];
    }

    // Step 8: Display the result
    cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t"
             << arrival[i] << "\t\t"
             << burst[i] << "\t\t"
             << waiting[i] << "\t\t"
             << turnaround[i] << "\n";
    }

    // Display average waiting time and average turnaround time
    cout << "\nAverage Waiting Time: " << (float)totalWaitingTime / n;
    cout << "\nAverage Turnaround Time: " << (float)totalTurnaroundTime / n;

    return 0;
}
