#include <iostream>
using namespace std;

// Global shared resource
int sharedCounter = 0;

// Binary semaphore variable (0 = locked, 1 = available)
int semaphore = 1;

// Wait (P) operation
void wait()
{
    while (semaphore <= 0)
    {
        // Busy wait (skip loop iteration until semaphore is free)
    }
    semaphore--;
}

// Signal (V) operation
void signal()
{
    semaphore++;
}

// Simulated Process A
void criticalSection(string process)
{
    wait(); // Acquire semaphore
    cout << "Process " << process << " enters critical section.\n";
    sharedCounter = sharedCounter + 1;
    cout << "Shared Counter(" << process << "):" << sharedCounter << endl;
    cout << "Process " << process << " leaves critical section.\n\n";
    signal(); // Release semaphore
}

// Main function to simulate sequence
int main()
{
    // Simulate calling processes alternately
    criticalSection("A");
    criticalSection("B");
    criticalSection("C");
    criticalSection("D");

    cout << "Final Shared Counter: " << sharedCounter << endl;

    return 0;
}