// we decide a pivot initially as the first element and fix the position of the pivot such that all the elements on the left are lesser than pivot and on the right are greater.

//static is used so that we can call the function without creating object

import java.util.Scanner;

public class quick_sort{
    static int A[] = new int[10];
    
    public static void swap(int a,int b){
      int tmp = A[a];
      A[a] = A[b];
      A[b] = tmp;
    }

    public static int partition(int l,int h){
    int pivot = A[l];
    int i=l+1;
    int j=h;
    while(i<=j){
        do{
            i++;
        }while(A[i]<pivot);
        do{
            j--;
        }while(A[j]>pivot);
        if(i<j)
         swap(i, j);
    }
    swap(l,j);
    return j;
    }

    public static void QuickSort(int l,int h){
       if(l<h){
        int j = partition(l,h);
          QuickSort(l,j);
           QuickSort(j+1,h);
       }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
       System.out.println("Enter the size of array: ");
        int n = sc.nextInt();

        System.out.println("Enter the array: ");
        for(int i=0;i<n;i++){
            A[i] = sc.nextInt();
        }

        QuickSort(0,n-1);

        // System.out.println(A.length);
        for(int k=0;k<n;k++)
        System.out.print(A[k]+" ");
    }
}
