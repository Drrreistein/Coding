/**
 * Given a string s and a dictionary of words dict, 
 * determine if s can be segmented into a space-separated sequence 
 * of one or more dictionary words.
 * For example, given
 * s ="leetcode",
 * dict =["leet", "code"].
 * Return true because"leetcode"can be segmented as"leet code".
 */
package dp;

import java.util.HashSet;
import java.util.Set;

/**
 * @author 18817
 *
 */
public class WordBreak {

	public static boolean wordBreak(String s, Set<String> dict) {
		int n = s.length();
		boolean[] dp = new boolean[n+1];
		dp[0] = true;
		for(int i=0; i<n; i++) { // for string 
			for(int j=1; j<i+2; j++) { // for dp-array
				if(dp[j-1] == true) { // µÝ½ø¹ØÏµ
					if(dict.contains(s.substring(j-1, i+1))) {
						dp[i+1] = true;
						break;
					}
				}
			}
		}
		displayArray(dp);
		return dp[n];
	}
	
	public static void displayArray(boolean[] arr) {
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

		 String s ="leetcode";
		 Set<String> dict = new HashSet<String>();
		 dict.add("lee");dict.add("let");
		 dict.add("leet");dict.add("code");
		 
		 System.out.println(wordBreak(s, dict));
	}

}
