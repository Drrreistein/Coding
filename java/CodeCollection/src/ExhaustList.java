/* {1, 2, 3} -> {}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}

*/
public class ExhaustList {
	 
    public static void main(String[] args) {
        int data[] = {1,2,3};   // ����ٵ��б�
        int flag[] = {0,0,0};   //
        printCompose(data,flag);
    }
 
    /**
     * ѭ������ 2^n �η���
     * �ж� flag �����е�״̬���
     * ÿѭ��һ�θ���һ�������е�Ԫ�ص�ֵ
     * @param data
     * @param flag
     */
    private static void printCompose(int[] data, int[] flag) {
        int len = (int)Math.pow(2,data.length);
        while(len--!=0){
            System.out.print("{ ");
            for(int i=0;i<flag.length;i++){
                if(flag[i]==1)
                    System.out.print(data[i]+" ");
            }
            change(flag); //
            System.out.println("}");
        }
    }
 
    /**
     * ��ת����������ÿ�ν������е������з�ת
     * @param flag
     */
    private static void change(int flag[]){
        for (int i = 0; i <flag.length ; i++) {
            if(flag[i]==1)
                flag[i]=0;
            else {
                flag[i] = 1;
                break;// �����ǹؼ�
            }
        }
    }
}