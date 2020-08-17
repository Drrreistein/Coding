package hash;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class ApplicationHashMap {
	
	public void main(String args[]) {
		Scanner input = new Scanner(System.in);
		int m = input.nextInt();
		int n = input.nextInt();
		Map<String, String> map = new HashMap<>();
		while(--m>=0) {
			String s1 = input.next();
			int i;
			for(i=0; i<s1.length(); i++) {
				if(s1.charAt(i)==' ') {break;}
			}
			map.put(s1.substring(0,i), s1.substring(i+1,s1.length()));
		}
		
		for(int i = 0; i < n; i++) {
			String s2 = input.next();
			System.out.println(map.get(s2));
		}
		
	}
}
