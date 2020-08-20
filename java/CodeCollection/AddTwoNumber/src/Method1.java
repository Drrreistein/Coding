

/*You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/*
方法一： 将两个链表依次转换为对应的整数，再将两个整数的和还原成链表的形式
*/
public class Method1{

	public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		// convert linked list l1 into integer a
        int i=0;
        int a=0;
        while(l1 != null){
            a = (int) (a + l1.val* Math.pow(10,i));
            i++;
            l1 = l1.next;
        }
        
        // convert linked list l2 into integer b
        i=0;
        int b=0;
        while(l2 != null){
            b = (int)(b+ l2.val*Math.pow(10,i));
            i++;
            l2 = l2.next;
        }
        
        int c =a+b;
        // convert sum of a and b back to linked list
        ListNode l3 = addToList(c);
        
        return l3;
        
    }
    
    private static ListNode addToList(int c){
        if(c/10 != 0){
            return new ListNode(c%10, addToList(c/10));
        }else{
            return new ListNode(c%10);
        }
    }
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		ListNode l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
		ListNode l1 = new ListNode(9);
		 ListNode l2 = new ListNode(1, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))));
		 ListNode l3 = addTwoNumbers(l1, l2);
		 while(l3 != null) {
			 System.out.print("->" + l3.val);
			 l3 = l3.next;
		 }
	}

}
