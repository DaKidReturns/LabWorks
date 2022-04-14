import java.util.Scanner;


class QuickSort{
    public static void quickSort(String arr[], int s,int e){
        if(s<e){
            int q = partition(arr,s,e);
            quickSort(arr,s,q-1);
            quickSort(arr,q+1,e);
        }
    }

    static int partition(String arr[], int s, int pivot){
        String x = arr[pivot];
        int i=s-1,j=s;
        String temp;
        for(;j<pivot;j++)
        {
            if(arr[j].compareTo(x)<=0){ //arr[j] <= arr[pivot] the switch
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[i+1];
        arr[i+1]=arr[pivot];
        arr[pivot] = temp;
        return i+1;
    }

    public static void main(String args[]){
        String[] arr = new String[100];
        int i = 0;

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of elements: ");
        int n = sc.nextInt();
        sc.nextLine();
        System.out.print("\nEnter the names to be sorted: ");

        while(i<n && sc.hasNextLine()){
                arr[i++] = sc.nextLine();
        }

        quickSort(arr,0,i-1);
        System.out.print("The sorted array is : ");
        for(int x=0;x<i;x++){
            System.out.print(arr[x]+" ");
        }
        System.out.println("");
    }
}
