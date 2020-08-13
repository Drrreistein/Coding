import java.util.HashMap;
import java.util.Map;

/* optimized sliding windows
define a hashmap, mapping the characters to its index.

The reason is that if s[j] have a duplicate in the range[i,j) with index j', 
we don't need to increase i little by little. 
We can skip all the elements in the range [i, j']
and let i to be j'directly.

time complexity :O(N)
space complexity: O(N)
*/
public class Solution3 {

	public static int lengthOfLongestSubstring(String s) {
		int n = s.length();
		int i=0,j=0,ans=0;
		Map<Character, Integer> map = new HashMap<>();
		for(j=0;j<n;j++) {
			
			if(map.containsKey(s.charAt(j))) {
				//即使这里map没有删除操作
				i=Math.max(i, map.get(s.charAt(j)));
			}
			
			map.put(s.charAt(j),j);
			ans = Math.max(ans, j-i);// 关键

		}
	
		return ans;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.print(lengthOfLongestSubstring("abdabcade"));

	}
}
