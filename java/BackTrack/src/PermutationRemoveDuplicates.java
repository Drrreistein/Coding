/*
 * find out all combination of{1, 1, 2}, no duplicates
 * -> {1, 1, 2}, {1, 2, 1}, {2, 1, 1}
 * 
 * 这里的方法，利用到了HashSet里元素均是独一无二的特性，
 * 自动过滤掉了重复的组合。
 * 但是因为将所有可能性，包括不必要的重复组合都列举了出来，效率下降
 * 更高效的见方法二(PermutationRemoveDuplicates2)
*/
import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
public class PermutationRemoveDuplicates {
	static Set<List<Integer>> set = new HashSet();
	
	public static List<List<Integer>> permutate(int[] nums){
		dfs(nums, 0);
		List<List<Integer>> list = new ArrayList<>(set);
		return list;
	}
	
	private static void dfs(int[] nums, int start) {
		 
		if(start == nums.length) {
			List<Integer> l1 = new ArrayList<>();
			for(int i : nums) {
				l1.add(i);
			}
			set.add(l1); // add list to HashSet, HashSet will automatically unique its elements  
			System.out.println(l1);
//			return;
		}else {
			for(int i=start; i<nums.length; i++) {
				swap(nums, start, i);
				displayArray(nums);System.out.print("start:"+start+";"+"i:"+i +"; ");
				dfs(nums, i+1);
				swap(nums, start, i);
				
				displayArray(nums);System.out.print("start:"+start+";"+"i:"+i +"; ");
				System.out.println();System.out.println();
			}
		}
		
	}
	private static void displayArray(int[] arr) {
		System.out.print("array:");
		for(int i =0; i< arr.length; i++) {
			System.out.print(arr[i]+ " ");
		}
	} 
	
	private static void swap(int[] nums, int a, int b) {
		int tmp = nums[a];
		nums[a] = nums[b];
		nums[b] = tmp;
	}
	
	public static void main(String args[]) {
		int[] nums = {1, 2, 3};
		
		System.out.println(permutate(nums));
	}


}
