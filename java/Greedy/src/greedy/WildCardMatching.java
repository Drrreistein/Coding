package greedy;

/** '?'and'*'.的通配符模式匹配
'?' 列（匹配任何单个字符）。
'*' 列（匹配任何字符序列）。
返回两个字符串是否匹配
函数声明为：
bool isMatch(const char *s, const char *p)
下面给出一些样例：
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
 */

/**
 * @author 18817
 *
 */
import java.util.*;
public class WildCardMatching {

	public static boolean isMatch(String s, String p) {
//		return match(s,p) || match(p,s);
		return match(p,s);
	}

	public static boolean match(String s, String p) {
		if(s.length()==0 || p.length()==0) {
			return false;
		}
		if(s.charAt(0) == '?') {
			return match(s.substring(1), p.substring(1));
		}
		else if(s.charAt(0)=='*') {
			if(p.length()==1) {
				return true;
			}
			if(s.length() > p.length()) {
				return false;
			}
			if(s.length() == p.length() && s.charAt(1)==p.charAt(1)) {
				return match(s.substring(1),p.substring(1));
			}
			if(s.substring(1).equals(p.substring(1))) {
				return true;
			}
			if(s.length()==1) {
				return true;
			}
			else if(s.charAt(1)==p.charAt(1)) {
				if(match(s.substring(1), p.substring(1))){
					return true;
				}else{
					return match(s, p.substring(1));
				}
			}else {
				return match(s, p.substring(1));
			}

		}
		else if(s.charAt(0) == p.charAt(0)){
			if(s.length()==p.length() &&s.length()==1) {
				return true;
			}else {
				return match(s.substring(1), p.substring(1));
			}
			
		}else {
			return false;
		}
		
//		return false;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<String> ls = new ArrayList<>();
		ArrayList<String> lp = new ArrayList<>();

//		ls.add("abevaa");ls.add("aaa");
		ls.add("aa");ls.add("aa");ls.add("ab");ls.add("aab");
//		lp.add("*e*a");  lp.add("aa"); 
		lp.add("*"); lp.add("a*");lp.add("?*");lp.add("c*a*b");
		
		for(int i=0; i<ls.size(); i++) {
			System.out.println(isMatch(ls.get(i), lp.get(i)));
			
		}
	}

}
