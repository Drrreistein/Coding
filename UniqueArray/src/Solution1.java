public class Solution1{
	
    public static int cleanArray(int[] arr){
        int n = arr.length;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(arr[j]==arr[i]){
//                	System.out.println(arr[i] +" "+ arr[j]);
                    n = n-1;
                    int k = j;
                    while(k <= n-1){
                        arr[k] = arr[k+1];
                        k++;
                    }
                    j--;
                }
                
            }
        }
//        System.out.print(arr);
        return n;
    }
    
    public static void main(String[] args){
//    	System.out.print("haha");
    	int[] nums = {1,1,2};
        System.out.print(cleanArray(nums));
    }
}