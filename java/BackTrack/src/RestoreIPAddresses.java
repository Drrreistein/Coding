/**
 * 现在有一个只包含数字的字符串，将该字符串转化成IP地址的形式，返回所有可能的情况。
例如：
给出的字符串为"25525511135",
返回["255.255.11.135", "255.255.111.35"]. (顺序没有关系)

*/
import java.util.*;
 
 
public class RestoreIPAddresses {
	
//    /**
//     * nowcoder version
//     * @param s string字符串
//     * @return string字符串ArrayList
//     */
//    public static ArrayList<String> restoreIpAddresses (String s) {
//        // write code here
//        ArrayList<String> resultList = new ArrayList<>();
//        if (s == null || s.length()<4) {
//            return resultList;
//        }
//        f(s, 1, new StringBuffer(), resultList);
//        return resultList;
//         
//    }
//     
//    public static void f(String s, int deep, StringBuffer stringBuffer, ArrayList<String> resultArrayList) {
//        if (deep > 3) {
//            // 
//            if ("".equals(s)) {
//                return;
//            }
//            if (s.length()>1 && s.startsWith("0")) {
//                return;
//            }
//            int val = Integer.valueOf(s);
//            if (val >= 0 && val < 256) {
//                stringBuffer.append(s);
//                resultArrayList.add(stringBuffer.toString());
//            }
//        } else {
//            for (int i = 1; i <= 3 && i<=s.length(); i++) {
//                String curr = s.substring(0, i);
//                if (curr.length()>1 && curr.startsWith("0")) {
//                    continue;
//                }
//                String next = s.substring(i);
//                int val = Integer.valueOf(curr);
//                if (val >= 0 && val < 256) {
//                    StringBuffer sb = new StringBuffer(stringBuffer);
//                    sb.append(curr).append(".");
//                    f(next, deep + 1, sb, resultArrayList);
//                }
//            }
//        }
//    }
//    
	public static ArrayList<String> restoreIpAddresses(String s){
		ArrayList<String> resultsLists = new ArrayList<>();
		int deep = 1;
		String buffer = "";
		f(s, deep, buffer, resultsLists);
		return resultsLists;
	}
	
	private static void f(String s, int deep, String buffer, ArrayList<String> resultsLists) {
		if(deep >3) {
			if(s.equals("")) {
				return;
			}
			if(s.length()>1 && s.startsWith("0")) {
				return;
			}
			int val = Integer.valueOf(s);
			if(val>=0 && val<= 255) {
				resultsLists.add(buffer+s);
				return;
			}
		}else {
			
			for(int i =1; i<s.length()&& i<=3; i++) {
				String sub = s.substring(0,i);
				String ss = s.substring(i);
				if(sub.length()>1 && sub.startsWith("0")) {
					return;
				}
				int val = Integer.valueOf(sub);
				if(val >= 0 && val <=255) {
					String newBuffer = buffer+sub+"."; // 这里必须申明一个新的string，不能直接更新buffer
					System.out.println(newBuffer);
					f(ss, deep+1, newBuffer, resultsLists);
				}
			}
		}
	}
    
    public static void main(String args[]) {
    	String ip1= "25525511135";
    	String ip2="010010";
    	ArrayList<String> ipLists = new ArrayList<>();
    	ipLists.add(ip1);ipLists.add(ip2);
//    	String tmp= ip+"."+"23";
//    	System.out.print(tmp);
    	for(String s: ipLists) {
    		System.out.println(restoreIpAddresses(s));
    	}
    	
    	
    }
}