/**
Given a string s, 
partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s ="aab", return1, 
since the palindrome partitioning["aa","b"]could be produced using 1 cut.
 */
package dp;

/**
 * @author 18817
 *
 */
public class PartitionPalindrome {

	public static int minCut(String s) {
		int n = s.length();
		displayString(s);
		char[] chs = s.toCharArray();
		
		int[] dp = new int[n-1];
		
		for(int i=0; i<n-1; i++) { // initialization
			dp[i] = i+1;
		}
		
		displayArray(dp);
		for(int i = 0; i < n-1; i++) {
			extendCheck(chs, i, i, dp);
			displayArray(dp);
			extendCheck(chs, i, i+1, dp);
			displayArray(dp);
		}

		return dp[n-2];
	}
	
	private static void extendCheck(char[] chs, int i, int j, int[] dp) {
		while(i >= 0 && j< chs.length && chs[i]==chs[j]) {
			if(i!=j) {

				if(i>=2) {
					dp[j-1] = Math.min(Math.min(dp[i-2]+1, dp[j-2]+1), dp[j-1]);
				}else if(i==1) {
					dp[j-1] = 1;
				}else {
					dp[j-1] = 0;
				}

			}

			i--;
			j++;
		}
		
		return;
	}
	
	private static boolean isPalindrome(String s) {
		if(s.length()<=1) {
			return true;
		}
		else if(s.charAt(0) == s.charAt(s.length()-1)) {
			return isPalindrome(s.substring(1, s.length()-1));
		}
		
		return false;
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

	public static void displayString(String s) {
		int len = s.length();
		System.out.print("[\t");
		for(int i=0; i<len; i++) {
			System.out.print(s.charAt(i) + "\t");
		}
		System.out.print("]");
		System.out.println();
	}
	/**
	 * nowcoder version
	
	*/
    public static int minCut2(String s) {
        char[] chs = s.toCharArray();
        int[] dp = new int[chs.length + 1];
        for(int i = 0; i < dp.length; ++i) dp[i] = i - 1;
        for(int i = 0; i < chs.length; ++i) {
            expand(chs, i, i, dp);
			displayArray(dp);

            expand(chs, i, i + 1, dp);
			displayArray(dp);

        }
        return dp[chs.length];
    }
       
    private static void expand(char[] chs, int i, int j, int[] dp) {
        while(i >= 0 && j < chs.length && chs[i] == chs[j]) {
            dp[j + 1] = Math.min(dp[j + 1], dp[i] + 1);
            --i;
            ++j;
        }
        return;
    }
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

//		String s= "abccb";
//		String s= "abccbbc";
		String s="adabdcaebdcebdcacaaaadbbcadabcbeabaadcbcaaddebdbddcbdacdbbaedbdaaecabdceddccbdeeddccdaabbabbdedaaabcdadbdabeacbeadbaddcbaacdbabcccbaceedbcccedbeecbccaecadccbdbdccbcbaacccbddcccbaedbacdbcaccdcaadcbaebebcceabbdcdeaabdbabadeaaaaedbdbcebcbddebccacacddebecabccbbdcbecbaeedcdacdcbdbebbacddddaabaedabbaaabaddcdaadcccdeebcabacdadbaacdccbeceddeebbbdbaaaaabaeecccaebdeabddacbedededebdebabdbcbdcbadbeeceecdcdbbdcbdbeeebcdcabdeeacabdeaedebbcaacdadaecbccbededceceabdcabdeabbcdecdedadcaebaababeedcaacdbdacbccdbcece";

		
		// test function isPalindrome
		System.out.println(isPalindrome("ababa"));
		System.out.println(minCut2(s));
		
	}

}
