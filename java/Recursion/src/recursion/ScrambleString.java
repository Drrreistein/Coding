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
	 * my verison
	 * 
	 */
	public static boolean isScramble(String s1, String s2) {
		int n1 = s1.length();
		int n2 = s2.length();

		if (n1 == n2) {
			if (s1.equals(s2)) {
				return true;
			} else { // partition string to two substrings

				for (int i = 1; i < n1; i++) { // find all scramble-substring combi using for-loop
					boolean res1 = isScramble(s1.substring(0, i), s2.substring(0, i))
							&& isScramble(s1.substring(i), s2.substring(i));
					System.out.println(s1.substring(0, i) + " " + s2.substring(0, i) + " " + s1.substring(i) + " "
							+ s2.substring(i) + " " + res1);

					boolean res2 = isScramble(s1.substring(0, i), s2.substring(s2.length() - i))
							&& isScramble(s1.substring(i), s2.substring(0, s2.length() - i));
					System.out.println(s1.substring(0, i) + " " + s2.substring(s2.length() - i) + " " + s1.substring(i)
							+ " " + s2.substring(0, s2.length() - i) + " " + res2);
					if (res1 || res2) {
						return true;
					}
				}

			}

		}

		return false;
	}

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
		if (s1 != s2) {
			res = isScramble(s1, s2);
		}
		System.out.println("String " + s1 + " and " + s2 + " is scramble-string: " + res);

	}

}
