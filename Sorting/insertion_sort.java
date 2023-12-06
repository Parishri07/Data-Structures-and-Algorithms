import java.util.Scanner;

//we have two parts - sorted and unsorted, we take one element from unsorted and place it at it's right pos in sorted array.
public class insertion_sort {
    public static void main(String[] args) {
       Scanner sc = new Scanner(System.in);
       System.out.println("Enter the size of array: ");
       int n = sc.nextInt();
        int arr[] = new int[n];

        System.out.println("Enter the array: ");
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }

        for(int i=1;i<arr.length;i++){
            int current = arr[i];
            int j = i-1;
            while(j>=0 && arr[j]>current){
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = current;
        }

        for(int k=0;k<n;k++)
         System.out.print(arr[k]+" ");
    }
}
