/* N��bug����һ�����ȿ��Լ���һ��Сʱ�е�bug���ٶ�A����һ��Сʱ���ظ�����Ч��һ����๤����Сʱ��ÿ��bug��ʼ������ʱ���� t1,t2,t3,��tn���ӡ����Ƿ���Խ������е�bug��

���룺
�����������������ݡ�ÿ��������ݣ�
��һ����������������N��A��X���ֱ������Ҫ�����bug�������ȿ���֮��Ч�������ı�����һ�������Ժȵ��Ŀ�����
�ڶ�������N����������ʾ�ڲ��ȿ��ȵ�����½����Щ�˰��������ʱ��t1, t2, ��, tN
�����
������ڰ�Сʱ�ڽ����Щbug(���ʱ��ΪС��������ȡ��)��������bug��ʱ�䣬�������0

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
