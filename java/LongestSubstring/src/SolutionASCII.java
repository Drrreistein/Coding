/*
 * amazing method
 * even much faster than hashmap because of the simplicity of 
 * an array  
*/
public class SolutionASCII {

	public static int lengthOfLongestSubstring(String s) {
		int n = s.length();
		int i=0,j=0,ans=0;
		int[] arr = new int[128];//initialize with 0
		for(j=0;j<n;j++) {
			
			i=Math.max(i, arr[s.charAt(j)]);
//			System.out.print(arr[s.charAt(j)]);
			ans = Math.max(ans, j-i);
			
			arr[s.charAt(j)] = j;

		}
	
		return ans;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.print(lengthOfLongestSubstring("abdabcade"));

	}
}
