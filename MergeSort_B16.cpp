#include <iostream>

using namespace std;

// Function to merge two halves of the array
void merge(float arr[], int left, int mid, int right) {
    int n1 = mid - left + 1; // Size of left subarray
    int n2 = right - mid;    // Size of right subarray

    // Temporary arrays
    float L[n1], R[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0; // Initial indexes of left and right subarrays
    int k = left;    // Initial index of merged subarray

    // Merge the temp arrays back into arr
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to implement Merge Sort
void mergeSort(float arr[], int left, int right) {
    if (left < right) {
        int mid =(left + right) / 2; // Find the middle point

        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to display top 5 scores
void displayTop5(float arr[], int n) {
    cout << "Top 5 scores: " << endl;
    int count = 0;
    for (int i = n - 1; i >= 0 && count < 5; i--, count++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    float percentages[n];
    cout << "Enter the percentages of students: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> percentages[i];
    }

    // Sort the array using Merge Sort
    mergeSort(percentages, 0, n - 1);

    cout << "Percentages in ascending order: " << endl;
    for (int i = 0; i < n; i++) {
        cout << percentages[i] << " ";
    }
    cout << endl;

    // Display the top 5 scores
    displayTop5(percentages, n);

    return 0;
}
