
/*
方法二： 直接对两个链表的数进行依次相加，对大于10（溢出）的数做特殊处理
*/
public class Method2{
	
	public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		ListNode l3 = new ListNode(0);
		ListNode tmp = l3;
		ListNode p=l1, q=l2;
		int c, x, y;
		int overflow =0;
		while(p != null || q!=null) {
			//if(p == null) {x=0;}else {x=p.val;}
//			if(q == null) {y=0;}else {y=q.val;}
			x = (p  == null) ? 0 : p.val;
	        y = (q != null) ? q.val : 0;

			c = x + y + overflow;
			ListNode next = new ListNode(c%10);
			tmp.next = next;
			tmp = tmp.next;
			
			overflow =c/10;
			
			if(p != null) {p = p.next;}
			if(q != null) {q = q.next;}
		}
		
		if(overflow > 0) {tmp.next = new ListNode(overflow);}
		
		return l3.next;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		ListNode l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
//		ListNode l2 = new ListNode(4, new ListNode(8, new ListNode(7)));
		ListNode l1 = new ListNode(9);
		 ListNode l2 = new ListNode(1, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))));
		 ListNode l3 = addTwoNumbers(l1, l2);
		 while(l3 != null) {
			 System.out.print("->" + l3.val);
			 l3 = l3.next;
		 }
		 
	}

}