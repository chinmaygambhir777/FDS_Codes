/*Name: Chinmay Gambhir
Class: SE2
Roll Number: 81
PRN Number: F24122008

Problem Statement
Queues are frequently used in computer programming, and
a typical example is the creation of a job queue by an operating system. If the operating system does not use
priorities, then the jobs are processed in the order they enter the system. Write C++ program for simulating job
queue. Write functions to add job and delete job from queue. 
*/
#include <iostream> 
#include <string> 
using namespace std; 
// Structure to represent a job 
class Job { 
public:
int jobId; 
string jobName; 
Job* next; // Pointer to the next job in the queue 
}; 
// Class to represent the job queue 
class JobQueue { 
private: 
Job* front; // Pointer to the front of the queue 
Job* rear;  // Pointer to the rear of the queue 
public: 
JobQueue(){
front=NULL;
rear=NULL;
} 
// Function to add a job to the queue 
void addJob(int id,string name) { 
Job* newJob = new Job; 
newJob->jobId = id; 
newJob->jobName = name; 
newJob->next = NULL; 
if (rear == NULL) { // If the queue is empty 
            front = rear = newJob; 
        } else { 
            rear->next = newJob; // Link the new job at the end 
            rear = newJob;       // Update the rear pointer 
        } 
        cout << "Job added: " << name << " (ID: " << id << ")\n"; 
    } 
 
    // Function to delete a job from the queue 
    void deleteJob() { 
        if (front == NULL) { // If the queue is empty 
            cout << "No jobs to delete. The queue is empty.\n"; 
            return; 
        } 
        Job* temp = front; // Store the front job 
        front = front->next; // Move front pointer to the next job 
         if (front == NULL) { // If the queue is now empty 
            rear = NULL; // Update rear to NULL 
        }
        cout << "Job deleted: " << temp->jobName << " (ID: " << temp->jobId << ")\n"; 
        delete temp; // Free the memory of the deleted job 
    } 
    // Function to display the jobs in the queue 
    void displayJobs() { 
        if (front == NULL) { 
            cout << "No jobs in the queue.\n"; 
            return; 
        } 
        Job* current = front; 
        cout << "Jobs in the queue:\n"; 
        while (current != NULL) { 
            cout << "Job ID: " << current->jobId << ", Job Name: " << current->jobName << "\n"; 
            current = current->next; // Move to the next job 
        } 
    } 
    
}; 
 
int main() { 
    JobQueue queue; 
    int choice, id; 
    string name; 
    do { 
        cout << "\nJob Queue Menu:\n"; 
        cout << "1. Add Job\n"; 
        cout << "2. Delete Job\n"; 
        cout << "3. Display Jobs\n"; 
        cout << "4. Exit\n"; 
        cout << "Enter your choice: "; 
        cin >> choice; 
        switch (choice) { 
            case 1: 
                cout << "Enter Job ID: "; 
                cin >> id; 
                cout << "Enter Job Name: "; 
                cin.ignore(); // Clear the input buffer 
                getline(cin, name); 
                queue.addJob(id, name); 
                break; 
            case 2: 
                queue.deleteJob(); 
                break; 
            case 3: 
                queue.displayJobs(); 
                break; 
            case 4: 
                cout << "Exiting...\n"; 
                break; 
            default: 
                cout << "Invalid choice. Please try again.\n"; 
        } 
    } while (choice != 4); 
    return 0; 
}
