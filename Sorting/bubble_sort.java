// import java.util.*;


//compare two consecutive element such that the largest bubbles up to the last
class bubble_sort{
    public static void main(String[] args) {
        int arr[] = {3,8,4,9,6};
    
        //Time complexity = O(n^2)
        for(int i=4;i>=0;i--){
          for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
          }
        }
        for(int i=0;i<=4;i++)
         System.out.print(arr[i]+" ");
    }
}