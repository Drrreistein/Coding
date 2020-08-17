/**
 * 
 */
package dp;

/**
 * @author 18817
 *
 */
public class ClimbStairs {

	private static int times;
	
	public ClimbStairs() {
		times=0;
	}
	
	public static int howManyWaysRecursion(int stairs) {// µ›πÈ«ÛΩ‚
		if(stairs == 0) {times++; return 1; }
		if(stairs == 1) {times++; return 1; }
		return howManyWaysRecursion(stairs-2)*2 + howManyWaysRecursion(stairs-1);
	}
	
	public static int howManyWaysDP(int stairs) {
		int[] ans = new int[stairs+1];
		for(int i=0; i<stairs+1; i++) {
			if(i==0) {ans[i] =1; }
			else if(i==1) {ans[i]=1;}
			else {ans[i] = ans[i-1]+ ans[i-2]*2;}
		}
		return ans[stairs];
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n = 10;
		System.out.println("anwser of recursion: " + howManyWaysRecursion(n));
		System.out.println("time Complexity: " + times + "; Space Complexity: " + "not sure");
		
		System.out.println("anwser of dp: " + howManyWaysDP(n));
		System.out.println("time complexity: " + (n+1) + "; space Complexity: " + (n+1));

	}

}
