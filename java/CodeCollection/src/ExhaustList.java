/* {1, 2, 3} -> {}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}

*/
public class ExhaustList {
	 
    public static void main(String[] args) {
        int data[] = {1,2,3};   // 待穷举的列表
        int flag[] = {0,0,0};   //
        printCompose(data,flag);
    }
 
    /**
     * 循环遍历 2^n 次方次
     * 判断 flag 数组中的状态输出
     * 每循环一次更改一次数组中的元素的值
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
     * 反转函数，用于每次将数组中的数进行反转
     * @param flag
     */
    private static void change(int flag[]){
        for (int i = 0; i <flag.length ; i++) {
            if(flag[i]==1)
                flag[i]=0;
            else {
                flag[i] = 1;
                break;// 这里是关键
            }
        }
    }
}