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
package dp;

/**
 * @author 18817
 *
 */
public class ScrambleString {

	public static boolean isScramble(String s1, String s2) {
		int n1 = s1.length();
		int n2 = s2.length();
		
		if(n1==n2 && s1!=s2) {// both String should be in the same length 
			
		}
		
		return false;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
