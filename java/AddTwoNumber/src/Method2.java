
/*
�������� ֱ�Ӷ����������������������ӣ��Դ���10����������������⴦��
*/
public class Method2{

	
	public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		ListNode l3 = new ListNode(0);
		ListNode p=l1, q=l2;
		return l3;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
//		ListNode l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
		ListNode l1 = new ListNode(9);
		 ListNode l2 = new ListNode(1, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))));
		 ListNode l3 = addTwoNumbers(l1, l2);
	}

}