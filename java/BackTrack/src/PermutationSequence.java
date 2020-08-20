/**
The set[1,2,3,…,n]contains a total of n! unique permutations.
By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the k th permutation sequence.
Note: Given n will be between 1 and 9 inclusive.
 */

/**
 * @author 18817
 *
 */
import java.util.*;
public class PermutationSequence {
	private static int seq = 0;
	private static String res;
	
	/*
	 * 链接：https://www.nowcoder.com/questionTerminal/186c35e87f7b45beaa556dbbf670759e
	 * 来源：牛客网
	 */

		public static String getPermutation2(int n, int k) {
		        String res="";
		        ArrayList<Integer> list =new ArrayList<>();
		        for(int i=0;i<n;i++)
		            list.add(i+1);
		        int[] f = new int[n];
		        f[0]=1;
		        k--;
		        for(int i=1;i<n;i++) f[i]=f[i-1]*i;
		        for(int i=n;i>=1;i--){
		            int j=k/f[i-1];
		            k%=f[i-1];
		            res+=list.get(j);
		            System.out.println(res);
		            list.remove(j);
		        }
//		        System.out.println(res);
		        return res;
		    }
		
			/**
			 * backtracking method
				
				*/
	public static String getPermutation(int n, int k) {
		String s = "";
		for(int i =0; i<n; i++) {
			s = s.concat(Integer.toString(i+1));
		}
		String ss = "";
		backTracking(s, ss, k);
		return res;
	}
	
	public static void backTracking(String s, String ss, int k) {
		if(s.length()==0) { // 
			seq++; // 当前组合的序列号
			if(seq==k) { // 当当前组合序列号为要求输出的序列号时
				System.out.println(ss + " " + seq);
				res = ss;
			}
			
		}else {
			for(int i=0; i<s.length(); i++) {
				backTracking(s.substring(0, i) + s.substring(i+1), ss.concat(s.substring(i,i+1)), k);
//				ss = ss.substring(0,ss.length()-1); // recover the original value of ss
			}
		}
		
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		char c;System.out.println(c);

		System.out.println(getPermutation2(4,2));
	}

}
