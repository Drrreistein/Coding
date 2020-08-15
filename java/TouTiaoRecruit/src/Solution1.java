import java.util.Scanner;
import java.util.Arrays;

public class Solution1 {
	public static int howManyMore(int nums, int[] arr) {
		int n = arr.length;
//		Arrays.sort(arr); // ascending sort
		for (int i = 0; i < n-1; i++) {// ascending sort
			for(int j = i+1; j > 0; j--) {
				if(arr[j-1] > arr[j]) {
					int tmp = arr[j-1];arr[j-1]=arr[j];arr[j]=tmp;
				}
				else {break;}
			}
			
		}
		int dist1;
		int more =0;
		for(int i=0;i < n; i++) {
			System.out.println(" " + arr[i]);

			if(i+1<n) {//compare the first and second number
				dist1 = arr[i+1]-arr[i];
//				System.out.println(" " + dist1);
				if(dist1 >= 20) {// when distance bigger than 20
					more += 2; // we need two more
				}
				else if(dist1 >10 && dist1 <=20) { // when distance bigger than 10
					more++; // we need one more
					i++; // and move i one step forward
				}
				else if(dist1 <=10) {// when dist close enough
					if(i+2<n) {// compare the third with the second
						int dist2 = arr[i+2]-arr[i+1]; //
						if(dist2 <= 10) { //when close enough 
							i += 2; // move i two steps forward
						}
						else if(dist2 >10 ) { // if bigger than 10
							more++; // one more needed
							i++; // move i one step forward
						}
					}
					else {// if there is no third number
						more++;i++;
					}
					
				}
			}
			else { // if there is no second number
				more += 2;
				
			}
			
		}
		return more;
	}

	public static void main(String arg[]) {
		/*
		 * Scanner input = new Scanner(System.in);
		 * System.out.print("input number of questions: "); int nums = input.nextInt();
		 * System.out.println(nums); int[] arr = new int[nums];
		 * System.out.println("input how hard each question: "); for(int i=0; i<nums;
		 * i++) { arr[i] = input.nextInt(); System.out.println(arr[i]); }
		 */
		int nums = 4;
		int[] arr = new int[] {40, 35, 23, 20};
		System.out.println(howManyMore(nums, arr) + " more questions are needed");
		
		
	}
}
