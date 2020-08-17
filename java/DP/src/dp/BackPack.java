/*
 * С���ڹ����������ÿ�����ӷ���һ����Ʒ�������Ǽ۸���Ŀ������ȣ�С���ܹ���T��Ǯ����ϣ����T���ڻ����������ȡ���ʳ�������������򣬸������ޣ������û�ˡ�

���룺
�����������������ݣ�ÿ�����ݣ�
��һ��������������T��N���ֱ����Ǯ������ʳ��������
��������N�У�ÿ��������������ai, bi, ci(1 <= i <= N) ��������ʳ�ļ۸���ʳ������ȡ���ʳ������
�����
�����������

case:input
10 2
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
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
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
			displayMatrix(food);
			
			int[][] res = new int[foodArt][money+1];
			displayMatrix(res);
			for(int i=0; i<foodArt; i++) {// food art
				for(int k=1; k<food[i][2]+1; k++) {// food number
					for(int j=1; j< money+1; j++) {// money,j��1��ʼ
					
						if(i==0) {// first row of matrix, first 
							if(j >= food[i][0]*k) {
								res[i][j] = food[i][1]*k;
							}
						}
						else {// from second row of matrix 
							if(j >= food[i][0]*k) {// money enough for second
								res[i][j] =Math.max(res[i][j], Math.max(res[i-1][j], res[i-1][j-food[i][0]*k] + food[i][1]*k)) ;
							}
							else {
								res[i][j] = res[i-1][j];
							}
							
						}
					}

				}
			}
			displayMatrix(res);
			System.out.println("best solution: " + res[foodArt-1][money]);
		}
		
		
		
			
	}
	
	
	public static void displayMatrix(int[][] matr) {
		int len = matr.length;
		for(int i=0; i<len; i++) {
			displayArray(matr[i]);
		}
		System.out.println();
	}
	
	public static void displayArray(int[] arr) {
		int len = arr.length;
		System.out.print("[\t");
		for(int i=0; i<len; i++) {
			System.out.print(arr[i] + "\t");
		}
		System.out.print("]");
		System.out.println();
	}
}
