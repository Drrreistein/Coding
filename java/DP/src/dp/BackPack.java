/*
 * С���ڹ����������ÿ�����ӷ���һ����Ʒ�������Ǽ۸���Ŀ������ȣ�С���ܹ���T��Ǯ����ϣ����T���ڻ����������ȡ���ʳ�������������򣬸������ޣ������û�ˡ�

���룺
�����������������ݣ�ÿ�����ݣ�
��һ��������������T��N���ֱ����Ǯ������ʳ��������
��������N�У�ÿ��������������ai, bi, ci(1 <= i <= N) ��������ʳ�ļ۸���ʳ������ȡ���ʳ������
�����
�����������

case:input
100 2
1 1 1
1 1 1
100 3
26 100 4
5 1 4
5 2 2
output
2
306 
*/
package dp;

import java.util.Scanner;
public class BackPack {
	
	
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		
		while(input.hasNext()) {
			int money = input.nextInt();
			int foodArt = input.nextInt();
			int[][] food = new int[foodArt][3];
			for(int i=0;i<foodArt; i++) {
				food[i][0] = input.nextInt(); // price
				food[i][1] = input.nextInt(); // happiness
				food[i][2] = input.nextInt(); // how many
			}
			
			
			return;
		}
		
	}
}
