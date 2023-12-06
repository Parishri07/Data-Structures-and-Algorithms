#include <iostream>
#include <vector>

using namespace std;

class Heapify {
public:
    void downHeapify(vector<int>& heap, int parent, int size) {
        int largest = parent;
        int leftChild = 2 * parent + 1;
        int rightChild = 2 * parent + 2;

        if (leftChild < size && heap[leftChild] > heap[largest])
            largest = leftChild;
        if (rightChild < size && heap[rightChild] > heap[largest])
            largest = rightChild;
        if (parent != largest) {
            swap(heap, parent, largest);
            downHeapify(heap, largest, size);
        }
    }

    void upHeapify(vector<int>& arr, int index) {
        int parent = (index - 1) / 2;

        // While the current element is smaller than its parent and not the root
        while (index > 0 && arr[index] < arr[parent]) {
            swap(arr, index, parent); // Swap the current element with its parent
            index = parent;           // Move to the parent node
            parent = (index - 1) / 2;  // Recalculate the parent index
        }
    }

    void swap(vector<int>& arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    void buildMaxHeap(std::vector<int>& arr, int size) {
        // Perform down-heapify for each non-leaf node in reverse order.
        for (int i = size / 2 - 1; i >= 0; i--) {
            downHeapify(arr, i, size);
        }
    }

    void buildMinHeap(std::vector<int>& arr, int size) {
        // Traverse the array in reverse order and perform up-heapify for each element
        for (int i = size - 1; i >= 0; i--) {
            upHeapify(arr, i);
        }
    }
};

int main() {
    cout << "Enter the number of elements in the binary tree: ";
    int n;
    cin >> n;

    vector<int> a(n);
    cout << "Enter a binary tree in level order traversal: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    Heapify hp;
    // hp.buildMaxHeap(a, n);
    hp.buildMinHeap(a, n);

    cout << "Heap after heapify:" << endl;
    for (int value : a) {
        cout << value << " ";
    }

    return 0;
}
