package recursion;

import java.util.HashSet;
import java.util.Set;

public class TreeNode{
	public String value;
	public String matchedValue;
	public Set<TreeNode> children = new HashSet<TreeNode>();
	
	TreeNode(){}
	
	TreeNode(String value){
		this.value = value;
	}
	
	
//	public String value() {return value;}
	// add child node
	public void addChild(TreeNode child) {
		children.add(child);
	}
}
