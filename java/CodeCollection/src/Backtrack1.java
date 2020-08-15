// ??

import java.util.ArrayList;
import java.util.List;

public class Backtrack1 {
	
	static List<List<Integer>> res = new ArrayList<>();
	static List<Integer> path = new ArrayList<>();

    public static void permute(int[] nums) {
    	
        int len = nums.length;
        
        if (len == 0) {
            return;
        }

        boolean[] used = new boolean[len];
        
        dfs(nums, len, 0, used);
        return;
    }

    public static void dfs(int[] nums, int len, int depth, boolean[] used) {
        if (path.size() == len) {
        	System.out.println(path);
        	List<Integer> l1 = new ArrayList<>();
			/*
			 * 此处令人头秃了很久 
			 * 此处不能直接res.add(path), 因为path的值是动态变化的，
			 * 当res里的element一直指向path这个值，每次add之后，
			 * res里新旧element会被刷新成最新的path值
			*/
        	for(int i = 0; i < path.size(); i++) {l1.add(path.get(i));}
        	
        	res.add(l1);  // ?? 为什么不能把所有path保存到一个大的结构里呢
//            System.out.println(res);

        }

        for (int i = 0; i < len; i++) {
            if (!used[i]) {
                path.add(nums[i]);
                used[i] = true;
//                System.out.print(path);

                dfs(nums, len, depth + 1, used);
                used[i] = false;
                path.remove(path.size() - 1);
            }
        }
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 3};
        Backtrack1 solution = new Backtrack1();
        solution.permute(nums);
        System.out.println(res);
    }
}
