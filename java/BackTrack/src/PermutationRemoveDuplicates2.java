/*
 * 不同于第一种方法，这里多了去重的命令，效率显著提升

*/

import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
public class PermutationRemoveDuplicates2 {
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
		}
		for(int i=start; i<nums.length; i++) {
			swap(nums, start, i);
			dfs(nums, i+1);
			swap(nums, start, i);
		}
	}
	
	private static void swap(int[] nums, int a, int b) {
		int tmp = nums[a];
		nums[a] = nums[b];
		nums[b] = tmp;
	}
	
	public static void main(String args[]) {
		int[] nums = {1, 3,  2};
		
		System.out.println(permutate(nums));
	}


}
