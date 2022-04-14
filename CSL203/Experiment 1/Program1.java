/*  Java programe to find the second smallest element in an array
 *  
 *  Done By Rohit Karunakaran
*/
class Program1{
    public static void main(String args[]){
        int[] arr = {-34,2,9,34,12,9,-23,1,4,9,0};
        int arrSize=11;
        int smallest,secondSmallest;
        int i,pos=0;

        smallest=arr[0];
        
        for(i=1;i<11;i++){
            if(arr[i]<smallest){
                pos=i;
            }
        }
        
        if(pos!=0){
            secondSmallest=arr[0];
        } 
        else{
            secondSmallest=arr[arrSize-1];
        }

        for(i=0;i<11;i++){
            if(i==pos)continue;
                if(arr[i]<secondSmallest){
                    secondSmallest=arr[i];
            }
        }
        
        System.out.println("Second Smallest element is "+secondSmallest);
    }
}
