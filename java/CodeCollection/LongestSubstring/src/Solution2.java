import java.util.HashSet;
import java.util.Set;

/*Method 2: Sliding Window
in method 1, many iterations are not necessary 
and we use here HashSet to tell if a char exists or not
time complexity: O(2*N), only one loop, much better 
space complexity: O(N)
*/

public class Solution2 {
	public static int lengthOfLongestSubstring(String s) {
		int n = s.length();
		int i=0,j=0,ans=0;
		Set<Character> set = new HashSet<>();
		while(j<n && i<n) {
			
			if(set.contains(s.charAt(j))) {
				set.remove(s.charAt(i));
				i++;
			}
			else {
				set.add(s.charAt(j++));
				ans = Math.max(ans, j-i);
			}
		}
	
		return ans;
	}
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.print(lengthOfLongestSubstring("abcabcade"));

	}

}
