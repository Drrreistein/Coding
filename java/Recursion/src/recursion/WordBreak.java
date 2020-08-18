/**
 * Given a string s and a dictionary of words dict, 
 * determine if s can be segmented into a space-separated sequence 
 * of one or more dictionary words.
 * For example, given
 * s ="leetcode",
 * dict =["leet", "code"].
 * Return true because"leetcode"can be segmented as"leet code".
 */
package recursion;

import java.util.*;
/**
 * @author 18817
 *
 */
public class WordBreak {
	
	public static boolean wordBreak(String s, Set<String> dict) {
		char c = s.charAt(0);
		for(String sub : dict) {
			if(sub.charAt(0)==c) {
				System.out.print(s + ":"+ sub);
				
				if(s.equals(sub)) {
					System.out.println(" - matched");
					return true;}
				
				String t = stringSubtract(s, sub);
				System.out.println(" "+ t);
				if(!t.equals("somethingwrong...") && wordBreak(t, dict)) {
					return wordBreak(t, dict);
				}
				else {
					continue;
				}

			}
		}
		
		return false;
	}
	
	public static String stringSubtract(String t, String s) {
		int n =s.length();
		if(t.length()>=n && t.substring(0, n).equals(s)) {
			return t.substring(n);
		}else {
			return "somethingwrong...";
		}
		
	} 
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		 String s ="cars";
		 Set<String> dict = new HashSet<String>();
		 dict.add("car");dict.add("rs");
		 dict.add("ca");//dict.add("code");
		 
		 TreeNode root = new TreeNode(s);
		 String[] t=s.split("let");
		 
		 boolean res= wordBreak(s, dict);
		 System.out.println();
		 System.out.println(s +" can be composed by words in dict: "+ res);
	}

}
