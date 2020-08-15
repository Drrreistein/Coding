
/*
 * find out first all the combination of digits of a number;
 * {1, 2, 3} -> {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}...
 * check out if there is a combination which can be divided exact by 2;
 * we need here two separate recursion
 * here we use ArrayList to save the all final combinations
 * we can also do it with Tree,  

*/
import java.util.ArrayList;
import java.util.List;

public class PowerOfTwo {

	public static boolean checkPower(int n) {
		List<Integer> l1= new ArrayList<Integer>();
		while(n != 0 ) {
			l1.add(n%10);
			n=n/10;
			}
		int[] arr = new int[l1.size()];
		for(int i =0; i< l1.size(); i++) {arr[i]=l1.get(i);}
		
		ArrayList<Integer> res= new ArrayList<Integer>();
		combination(arr, res,  0, l1.size()-1);
		for(int i=0; i<res.size(); i++) {
			if(checkPowerOf(res.get(i), 2)) {
				return true;
			}
		}

		return false;
	}
	
	/*	
		list all combinations, and save the results in ArrayList res
		*/
	private static void combination(int[] arr,ArrayList<Integer> res, int start, int end) {
//		int n = end;
		
		for(int i =start; i<=end; i++) { 
			if(start<end) {
				// swap the first value with another
				int tmp=arr[start]; arr[start]=arr[i]; arr[i]=tmp;
				combination(arr,res, start+1, end);
				// swap it back after one iteration to make sure that
				// original array  always keeps same
				tmp=arr[start]; arr[start]=arr[i]; arr[i]=tmp;
				}

			else {// here we got every combination
				int newNum = 0;
				for(int j=0; j<=end; j++) {// print results
					System.out.print(arr[j] + " ");// print each combi
					// convert the array to the related number
					newNum = (int)(newNum + arr[j] * Math.pow(10, j));
				}
				res.add(newNum); // save each combi to the ArrayList
				System.out.println();
			}
			
		}
	} 
	
	/*
	 * using recursion, check if n can be exact divided by pw, and return true
	*/
	public static boolean checkPowerOf(int n, int pw) {
		if(n%pw == 0) {// n is divisible by pw
			if(n/pw == 1) {
				return true;
			}
			else {
				return checkPowerOf(n/pw, pw); // also returned recursively
			}
		}
		return false;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println(checkPower(8021));
	}

}
