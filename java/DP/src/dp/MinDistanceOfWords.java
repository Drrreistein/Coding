/**
给定两个单词word1和word2，请计算将word1转换为word2至少需要多少步操作。
你可以对一个单词执行以下3种操作：
a）在单词中插入一个字符
b）删除单词中的一个字符
c）替换单词中的一个字符
 */

package dp;

/**
 * @author 18817
 *
 */
class MinDistanceOfWords {
	
	/**
	 * @param s1, String
	 * @param s2, String
	 * @return, int
	*/ 
	public static int DistanceOfWords(String s1, String s2) {
		int m = s1.length();
		int n = s2.length();
		int[][] dp = new int[m+1][n+1];
		
		for(int i=0; i<m+1; i++) {// initialize the first column
			dp[i][0] = i;
		}
		for(int j=0; j<m+1; j++) {// initialize the first row
			dp[0][j] = j;
		}

		for(int i=1; i<m+1; i++) {// start from the second row
			for(int j=1; j<n+1; j++) { // start from the second column
				
				if(s1.charAt(i-1)==s2.charAt(j-1)) {// when two char matched
					dp[i][j] = dp[i-1][j-1];
				}
				else {// when chars not matched
					dp[i][j] = Math.min(Math.min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
				}
				
			}
		}
		displayMatrix(dp);
		return dp[m][n];
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
		String s1 = "abcd";
		String s2 = "bcde";
		System.out.println("Distance between " + s1 +" and "+ s2+ " is: "+ DistanceOfWords(s2, s1));
	}

}
