/*
 * find out all the combination;
 * {1, 2, 3} -> {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}...
 * we can also do it with Tree,  

*/
import java.util.ArrayList;

public class ExhaustPermutation{
	
	static TreeNode root = new TreeNode();
	static ArrayList<ArrayList<String>> list = new ArrayList<>();
	
	// permutate, to build a tree
	private static void permutation(TreeNode rootNode, ArrayList<String> arr, ArrayList<String> origin) {
		int n = arr.size(); // length of the ArrayList
		if(n != 0) {
			for(int i=0; i< n; i++) {
				TreeNode node = new TreeNode(arr.get(i));
				rootNode.children.add(node);
				System.out.print(node.value + " ");
				String x = arr.remove(i);
				permutation(node, arr, origin);
				arr.add(i, x);
			}
		}
		else {
			System.out.println(",");
		}
	}
	
	// depth first search, to display all combinations, but not quite successful
	public static void dfs(TreeNode node, ArrayList<String> path) {
		
		if(node.children.isEmpty()) {
			System.out.println(path);
		}
		else {
			for(TreeNode node2 : node.children) {
				path.add(node2.value);
//				System.out.print(node2.value);
				dfs(node2, path);
				path.remove(path.size()-1);
			}
		}
	}
	
	public static void main(String args[]) {
		String s1 = "abc";
		ArrayList<String> al = new ArrayList<String>();
		for(int i =0; i<s1.length();i++) {
			al.add(s1.substring(i, i+1));
		}
		
		permutation(root, al, al);
		System.out.println("");
		ArrayList<String> path = new ArrayList<String>();
		dfs(root, path);
//		System.out.print(list);
	}
	
}