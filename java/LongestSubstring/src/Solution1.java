/*Method 1: Brute force
 * time complexity: O(n^3)
 * space complexity: O(2*s.length());two substring to save ss and maxSS

*/
public class Solution1 {
	public static int lengthOfLongestSubstring(String s) {
		String ss = "", maxSS=""; // substring
		int max=0; // max length
		for(int i=0; i<s.length(); i++) {
			ss = ss + s.charAt(i); // local longest substring
			int len = 1;
			
			for(int j=i+1; j<s.length(); j++) {
				if(!allUnique(ss,s.charAt(j))) {// check if next char already in ss
					break;
				}else {
					len++;
					ss = ss+ s.charAt(j);
				}
			}
			if(len>max) {max=len; maxSS = ss;}// update the public longest substring
			ss = "";

		}
		
		System.out.println(maxSS);
		return maxSS.length();
	}
	
	public static boolean allUnique(String s, char c) {
		for(int i =0;i<s.length(); i++) {
			if(s.charAt(i)==c) {return false;}
		}
		return true;
	}
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		lengthOfLongestSubstring("abcabcs");

	}

}
