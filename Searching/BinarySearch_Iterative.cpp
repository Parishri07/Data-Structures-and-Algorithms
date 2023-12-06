#include <iostream>
#include<time.h>
using namespace std;

int binarySearchIterative(int arr[], int target, int size) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; 
        } else if (arr[mid] > target) {
            right = mid - 1; 
        } else {
            left = mid + 1;
        }
    }

    return -1; 
}

int main() {
  clock_t start, end;
    int n,target;
    cout<<"Enter size of array: ";
    cin>>n;
     int arr[n];
    cout<<"Enter array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Enter target: ";
    cin>>target;
    int size = sizeof(arr) / sizeof(arr[0]);

   start = clock();
    int result = binarySearchIterative(arr, target, size);
    end = clock();

    if (result != -1) {
        cout << "Element found at index " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }

       double time = (double)(end-start)/ CLOCKS_PER_SEC;
    cout<<"Time is: "<<time;
    return 0;
}


