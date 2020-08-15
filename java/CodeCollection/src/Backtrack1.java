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
			 * �˴�����ͷͺ�˺ܾ� 
			 * �˴�����ֱ��res.add(path), ��Ϊpath��ֵ�Ƕ�̬�仯�ģ�
			 * ��res���elementһֱָ��path���ֵ��ÿ��add֮��
			 * res���¾�element�ᱻˢ�³����µ�pathֵ
			*/
        	for(int i = 0; i < path.size(); i++) {l1.add(path.get(i));}
        	
        	res.add(l1);  // ?? Ϊʲô���ܰ�����path���浽һ����Ľṹ����
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
