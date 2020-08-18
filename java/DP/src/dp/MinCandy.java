/**
 * 
 */
package dp;

/**
 * @author 18817
 *
 */
public class MinCandy {

	
	public static int minCandy(int[] ratings) {

		int n = ratings.length;
		int[] candy = new int[n]; // save dp data
		candy[0] = 1; // initialize first candy number 
		
		for(int i=1; i<n; i++) {
			if(ratings[i] > ratings[i-1]) {
				candy[i] = candy[i-1]+1;
			}
			else if(ratings[i] == ratings[i-1]) {
				candy[i] = 1;
			}
			else {
				candy[i] = Math.min(candy[i-1]-1, 1);
				if(candy[i]==0) {
					candy[i]++;
					for(int j=i; j>=1; j--) {
						if(candy[j] == candy[j-1] && ratings[j-1] > ratings[j]) {
							candy[j-1] += 1;
						}
						else {
							break;
						}
					}
				}
				
			}
			
			System.out.print("ratings: ");
			displayArray(ratings);
			System.out.print("candies: ");
			displayArray(candy);
			System.out.println("#################");
		}
		
//		System.out.print("ratings: ");
//		displayArray(ratings);
		System.out.print("1candies: ");
		displayArray(candy);
		int sum=0;
		for(int i=0;i<n; i++) {sum += candy[i];}
		return sum;
		
	}
	
	public static int minCandy2(int[] ratings) {// code from nowcoder, 
		
        int len = ratings.length;
        int[] dp = new int[len];
        int sum = 0;
         
        for(int i = 0; i < len; i++){// initialization
            dp[i] = 1;
        }
         
        for(int i = 1; i < len; i++){// first dp run
            if(ratings[i] > ratings[i-1]){
                dp[i] = dp[i-1] + 1;
            }
        }
         
        for(int i = len-1; i >= 1; i--){ // second dp run
            if(ratings[i-1] > ratings[i] && dp[i-1] <= dp[i]){
                dp[i-1] = dp[i] + 1;
            }
        }
         
        for(int i = 0; i < len; i++){ // sum fo candies
            sum += dp[i];
        }
         
		System.out.print("2candies: ");
		displayArray(dp);
        return sum;
	}
	
	public static void displayArray(int[] arr) {
		int len = arr.length;
		System.out.print("[\t");
		for(int i=0; i<len; i++) {
			System.out.print(arr[i] + "\t");
		}
		System.out.print("]");
		System.out.println();
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		int[] ratings =new int[]{1, 2, 2};
		int[] ratings =new int[]{58,21,72,77,48,9,38,71,68,77,82,47,25,94,89,54,26,54,54,99,64,71,76,63,81,82,60,64,29,51,87,87,72,12,16,20,21,54,43,41,83,77,41,61,72,82,15,50,36,69,49,53,92,77,16,73,12,28,37,41,79,25,80,3,37,48,23,10,55,19,51,38,96,92,99,68,75,14,18,63,35,19,68,28,49,36,53,61,64,91,2,43,68,34,46,57,82,22,67,89};
//		int[] ratings =new int[]{3, 1, 0};
//		int[] ratings =new int[]{ 2, 2};
		
		System.out.println(minCandy(ratings));
		System.out.println(minCandy2(ratings));

	}

}
