**The ? operator in Java**

x = (p  == null) ? 0 : p.val;  等效于  if(p == null) {x=0;}else {x=p.val;}

---

Java, break and continue

* break: break the loop;

* continue: break the current iteration;

---

Eclipse中文乱码

https://blog.csdn.net/timo1160139211/article/details/74908266

---

数组初始化

int[] arr = new int[128];// 所有元素自动初始化为0

---

java 常用包，

java.util，其中包括各种数据结构，Map，Set，Queue，ArrayList等

---

java input command line

Scanner input=new Scanner(System.in);
System.out.print("请输入1个字符串：");
String s=input.nextLine();