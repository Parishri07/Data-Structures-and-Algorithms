import java.util.Scanner;

public class merge_sort {
    // static int[] a = new int[20];
    static int a[];

    public static void merge(int i1, int i2, int j1, int j2) {
        int i = i1, j = j1, k = 0;
        // int[] tmp = new int[50];
        int[] tmp = new int[(i2 - i1 + 1)];      

        while (i <= i2 && j <= j2) {
            if (a[i] < a[j]) {
                tmp[k++] = a[i++];
            } else {
                tmp[k++] = a[j++];
            }
        }
        while (i <= i2)// copy remaining elements of the list 1
            tmp[k++] = a[i++];
        while (j <= j2)// copy remaining elements of the list 2
            tmp[k++] = a[j++];

        for (i = i1, k= 0; i <= j2; i++, k++) {
            a[i] = tmp[k];
        }
    }

    public static void MergeSort(int l, int h) {
        if (l < h) {
            int mid = (l + h) / 2;
            MergeSort(l, mid);
            MergeSort(mid + 1, h);
            merge(l, mid, mid + 1, h);
        }
    }

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
       System.out.println("Enter the size of array: ");
        int n = sc.nextInt();

        a = new int[n];

        System.out.println("Enter the array: ");
        for(int i=0;i<n;i++){
            a[i] = sc.nextInt();
        }
        MergeSort(0,n-1);
        for(int k=0;k<n;k++)
        System.out.print(a[k]+" ");
    }
}
