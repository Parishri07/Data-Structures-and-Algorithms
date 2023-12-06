#include <iostream>
#include<time.h>
using namespace std;

int binarySearchRecursive(int arr[], int target, int left, int right) {
    if (left > right) {
        return -1; 
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid; 
    } else if (arr[mid] > target) {
        return binarySearchRecursive(arr, target, left, mid - 1); 
    } else {
        return binarySearchRecursive(arr, target, mid + 1, right); 
    }
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
    int left = 0;
    int right = sizeof(arr) / sizeof(arr[0]) - 1;

    start = clock();
    int result = binarySearchRecursive(arr, target, left, right);
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
