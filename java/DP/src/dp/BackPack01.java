/**
 * 
 */
package dp;

/*
10 3
3 2
4 3
5 4 
*/
import java.util.Scanner;

/**
 * @author 18817
 *
 */
public class BackPack01 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		while(input.hasNext()) {
			int money = input.nextInt();
			int foodArt = input.nextInt();
			int[][] food = new int[foodArt][2];
			for(int i=0;i<foodArt; i++) {
				food[i][0] = input.nextInt(); // price
				food[i][1] = input.nextInt(); // happiness
//				food[i][2] = input.nextInt(); // how many
			}
			displayMatrix(food);
			
			int[][] res = new int[foodArt][money+1];
			displayMatrix(res);
			for(int i=0; i<foodArt; i++) {
				for(int j=1; j< money+1; j++) {// j´Ó1¿ªÊ¼
					if(i==0) {// first row of matrix, first 
						if(j >= food[i][0]) {
							res[i][j] = food[i][1];
						}
					}
					else {// from second row of matrix 
						if(j >= food[i][0]) {// money enough for second
							res[i][j] = res[i-1][j-food[i][0]] + food[i][1];
						}
						else {
							res[i][j] = res[i-1][j];
						}
						
					}
				}
			}
			displayMatrix(res);
			
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
