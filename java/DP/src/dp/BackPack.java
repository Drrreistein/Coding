/*
 * 小明在购物架买东西，每个格子放着一种物品，上面标记价格，数目和满意度，小名总共有T的钱，他希望在T以内获得最大的满意度。零食必须整数倍购买，个数有限，卖完就没了。

输入：
输入包含多组测试数据，每组数据：
第一行输入两个整数T、N，分别代表钱数和零食种类数。
接下来的N行，每行输入三个整数ai, bi, ci(1 <= i <= N) ，代表零食的价格、零食的满意度、零食的数量
输出：
求出最大满意度

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
					for(int j=1; j< money+1; j++) {// money,j从1开始
					
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
