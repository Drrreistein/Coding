/* N个bug，喝一杯咖啡可以加速一个小时中调bug的速度A倍，一个小时内重复喝无效。一天最多工作八小时。每个bug初始的所需时间是 t1,t2,t3,…tn分钟。问是否可以解完所有的bug。

输入：
输入包含多组测试数据。每组测试数据：
第一行输入三个整数：N、A、X，分别代表需要解决的bug数量、喝咖啡之后效率提升的倍数、一天最多可以喝掉的咖啡数
第二行输入N个整数，表示在不喝咖啡的情况下解决这些八阿哥所需的时间t1, t2, …, tN
输出：
如果能在八小时内解决这些bug(如果时间为小数，向上取整)，输出解决bug的时间，否则输出0

case:input:
8 2 8
60 60 60 60 60 60 60 60
4 3 3
333 77 100 13
output:
240
175
*/
import java.util.Scanner;

public class CoffeeAndBug {
	
	public static void main (String args[]) {
		Scanner input = new Scanner(System.in);
		while(input.hasNext()) {
			int n = input.nextInt(); // record input data
			int a = input.nextInt();
			int x = input.nextInt();
			int bugs = 0;
			for(int i=0; i<n;i++) {
				bugs += input.nextInt();
			}
			int ans, allTime;
			
			if(x <= 8) {allTime = a*x*60;}
			else{allTime = a*8*60;}
			
			ans = (int) Math.ceil((double)bugs/a);
			if(allTime > bugs) {
				System.out.println("all bugs can be solved in " + ans + " minutes");
			}
			else {
				System.out.println("bugs can't be solved in " + ans + "minutes"); 
			}
			
		}
	}

}
