public class Test{
	
    public static int cleanArray(int[] arr){
        int n = arr.length;
        
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n;j++){
                if(arr[j]==arr[i]){
                    n=n-1;
                    if(j<=n){
                        int k=j;
                        while(k<n-1){
                            arr[k]=arr[k+1];
                            k++;
                        }
                    }
                    j--;
                }
                
            }
        }
        return n;
    }
    
    public static void main(){
        System.out.print(cleanArray(new int[]{1, 2, 3, 2}));
    }
}