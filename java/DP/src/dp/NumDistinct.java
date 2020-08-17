/**
���������ַ���S��T������S�����е���T�Ĳ�ͬ�����и����ж��ٸ���
�ַ���������������ԭ�����ַ���ɾ��һЩ�ַ���Ҳ���Բ�ɾ����
�ڲ��ı����λ�õ�����µ�ʣ���ַ������磬"ACE"is a subsequence of"ABCDE"����"AEC"���ǣ�
���磺
S ="rabbbit", T ="rabbit"
����3
 * 
 */
package dp;

/**
 * @author 18817
 *
 */
public class NumDistinct {

	public static int distinctSubstring(String s, String t) {
		int m = s.length(); // father string
		int n = t.length(); // substring, to be tested
		int[][] dp = new int[n][m+1];// numbers in first row are all 0 
		for(int i=0; i<n; i++) {
			int x=0;
			for(int j=1; j<m+1; j++) {
				
				if(i==0) {// first line, 
					if(s.charAt(j-1) == t.charAt(i)) {// letters of father string and substring are matched
						dp[i][j] = dp[i][j-1] + 1;}
					else {
						dp[i][j] = dp[i][j-1];
					}
				}else {
					if(s.charAt(j-1)==t.charAt(i)) {// letters of father string and substring are matched
						dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
					}
					else {
						dp[i][j] = dp[i][j-1];
					}
				}

				
			}
		}
		displayMatrix(dp);
		return dp[n-1][m];
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
		String s = "rrabbbit";
		String t = "rabbit";
		distinctSubstring(s, t);

	}

}
