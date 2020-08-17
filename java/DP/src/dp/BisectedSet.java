/**
 * 
 */
package dp;

/**
 * @author 18817
 *
 */
public class BisectedSet {

	public static boolean bisectingSet(int[] nums) {
		int sum = 0;
		int n= nums.length;
		for(int i=0; i<n; i++) {
			sum += nums[i];
		}
		if(sum%2==0) {sum = sum/2;} // sum of subset
		int[][] ans = new int[n][sum+1];
		for(int i=0; i<n; i++) {
			for(int j=1; j< sum+1; j++) {
				if(i == 0) {
					if(j >= nums[i]) {
						ans[i][j] = nums[i];
						
					}
				}
				else {
					if(j >= nums[i]) {// when j big enough, consider to choose the new object
						ans[i][j] = Math.max(ans[i-1][j], ans[i-1][j-nums[i]] + nums[i]);
					}
					else { // when j smaller than object i
						ans[i][j] = ans[i-1][j];
					}
				}
				// check if 
				if(ans[i][j]==sum && j==sum) {displayMatrix(ans);return true;}
			}
		}
		
		displayMatrix(ans);
		return false;
	}

	public static void displayMatrix(int[][] matr) {
		int len = matr.length;
		for(int i=0; i<len; i++) {
			displayArray(matr[i]);
		}
		System.out.println();
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
		int[] nums = {1, 5, 11, 5};
		System.out.println(bisectingSet(nums));

	}

}
