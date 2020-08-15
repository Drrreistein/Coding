import java.util.ArrayList;

public class TreeNode {
	String value;
	
	ArrayList<TreeNode> children = new ArrayList<TreeNode>();

	public TreeNode() {}
	
	public TreeNode(String value) {
		this.value= value;
	}
	
	public TreeNode(String value, ArrayList<TreeNode> children) {
		this.value = value;
		this.children = children;
	}
	

}
