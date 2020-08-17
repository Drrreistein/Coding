/**
 * https://www.nowcoder.com/practice/2bdc44bb0186468b8d8c13ea5d3a9e58?tpId=46&&tqId=29091&rp=1&ru=/ta/leetcode&qru=/ta/leetcode/question-ranking
 * ��Ŀ����һ���ַ���s1�����ǿ����õݹ�ķ������ַ����ֳ������ǿյ��Ӵ�����s1��ʾ��һ��������
������s1=��great����һ�ֶ������ı�����ʽ��
    great   /      gr    eat/     /  g   r  e   at  /   a   t
���ַ�������ķ����ǣ�ѡ������ķ�Ҷ�ӽڵ㣬���������������ӽڵ㡣
���磺�������ѡ��ڵ㡰gr�����������������ӽڵ㣬�ͻ����һ�������ַ���"rgeat".
    rgeat   /      rg    eat /     /  r   g  e   at /   a   t
���ǳ�"rgeat"��"great"��һ�������ַ�����
���Ƶģ�������Ǽ���������eat�����������ӽڵ�͡�at�����������ӽڵ㣬����������ַ���"rgtae".
    rgtae   /      rg    tae   /   r   g  ta  e   /   t   a
���ǳ�"rgtae"��"great"��һ�������ַ�����
��������������ͬ���ַ���s1 �� s2�����ж�s2�Ƿ���s1�������ַ�����
 */
package recursion;

/**
 * @author 18817
 *
 */
public class ScrambleString {
	/**
	 * nowcoder version 
	*/	
	/*
	 * public static boolean isScramble(String s1, String s2) { if(s1 == s2) return
	 * true; int[] c = new int[26]; for(int i=0;i<s1.length();i++) { c[s1.charAt(i)
	 * -'a']++; c[s2.charAt(i) -'a']--; } for(int i=0;i<26;i++) if(c[i] != 0) return
	 * false;
	 * 
	 * for(int i=1;i<s1.length();i++) { if(isScramble(s1.substring(0,i),
	 * s2.substring(0,i)) && isScramble(s1.substring(i), s2.substring(i))) return
	 * true; if(isScramble(s1.substring(0,i), s2.substring(s2.length()-i)) &&
	 * isScramble(s1.substring(i), s2.substring(0,s2.length()-i))) return true; }
	 * return false; }
	 */
	/**
	 * my verison
	
	*/
	
	  public static boolean isScramble(String s1, String s2) { 
		  int n1 = s1.length(); 
		  int n2 = s2.length();
	  
	  if(n1 == n2 && n1==1) { 
		  if(s1.equals(s2)) { 
			  return true; } } 
	  else if(n1 == n2 && n1>1) { 
		  if(s1.equals(s2)) { 
			  return true; } 
		  else { // partition string to two substrings 
			  String s11 = s1.substring(0, n1/2); 
			  String s12 = s1.substring(n1/2, n1); // System.out.println(s11 +" "+ s12); 
			  String s21 = s2.substring(0, n2/2); 
			  String s22 = s2.substring(n2/2, n2); //
			  System.out.println(s21 +" "+ s22);
	  
	  
			  boolean res1 = isScramble(s11, s22) && isScramble(s21, s12);
	  
			  System.out.println(s11 +" "+ s12 + " " + s21 +" "+ s22 +" "+res1); 
			  boolean res2 = isScramble(s11, s21) && isScramble(s12, s22); 
			  System.out.println(s11 +" "+ s21 + " " + s12 +" "+ s22 +" "+res2); 
			  if(res1 || res2) {return true;} }
	  }
	  
	  return false; }
	 
	  
	  
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s1 = "great";
//		String s2 = "rgeat";
		String s2 = "rgtae";
//		System.out.println("a"=="a");
		boolean res = false;
		if(s1 != s2) {
			res= isScramble(s1, s2);
		}
		System.out.println("String " +s1+" and "+s2+ " is scramble-string: "+ res);

	}

}
