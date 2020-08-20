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

int numberOfPoints=input.nextInt();

input.hasNext(); // return boolean, 可作为while的判断，用来多组数据的输入

---

java round

Math.round(11/2) = 5; // 四舍五入, 返回int类型

Math.floor(11/2) = 5.0; // round down, 返回double类型，

Math.ceil(11/2)=5.0;  // round up, 返回double类型

Math.ceil((double)11/2) = 6.0; // you must convert (int)11 to (double)11 first

---

Arrays.copyOfRange(arr, i, j)

---

java - for loop, another way to get the element of an array.

int[] arr = {1, 2, 3 };

**for(int i : arr){}**

---

```java
// 这是回溯算法的一道题
List<Integer> l1 = new ArrayList<>();
/*
			 * 此处不能直接简单的使用res.add(path), 因为path的值是动态变化的，
			 * 当res里的element一直指向path这个值，每次add之后，
			 * res里新旧element会被刷新成最新的path值
			*/
for(int i = 0; i < path.size(); i++) {l1.add(path.get(i));}

res.add(l1);  // ?? 为什么不能把所有path保存到一个大的结构里呢
```

---

java字符串String用双引号，"a"

java字符char用单引号，‘a’

---

error, never command lines directly after a "return "

---

java, check 2 string equals or not

1. don't use s1==s2, because, not only the content but also their IDs must equal, then return true
2. use, s1.equals(s2), when contents equal, it'll return true. 

---

java display matrix and array

```java
public static void displayMatrix(int[][] matr) {
	int len = matr.length;
	for(int i=0; i<len; i++) {
		displayArray(matr[i]);
	}
	System.out.println();
}

public static void displayArray(int[] arr) {
	int len = arr.length;
	System.out.print("[\t");
	for(int i=0; i<len; i++) {
		System.out.print(arr[i] + "\t");
	}
	System.out.print("]");
	System.out.println();
}

	public static void displayString(String s) {
		int len = arr.length;
		System.out.print("[\t");
		for(int i=0; i<len; i++) {
			System.out.print(arr[i] + "\t");
		}
		System.out.print("]");
		System.out.println();
	}
```

---

java 回溯算法中的形参变量的手动恢复

在回溯算法的递归过程中，一个变量作为函数形参进入到函数里面再出来之后，它的值都会被函数改变。因此当其再次回到当前递归层次时，需要手动恢复该变量进入函数体之前的值

```java
public static void backTracking(int start, String s ,ArrayList<int[]> edge) {
    // tmp的值不用手动恢复：因为他是每次递归的时候重新定义的变量。
    // 不是edge作为初始的形参变量
	String tmp = s.concat(Integer.toString(start));
	if(edge.size()==0) {
		edgeList.add(tmp);
	}
	else {
		for(int i=0; i<edge.size(); i++) {
			if(start == edge.get(i)[0] || start == edge.get(i)[1]) {
				int newStart = start;
				if(start == edge.get(i)[0] ) {
					newStart = edge.get(i)[1];
				}else{
					newStart = edge.get(i)[0];
				}
				int[] arr = edge.get(i); 
				edge.remove(i);
				backTracking(newStart, tmp, edge);
                
				edge.add(i, arr);// ***手动恢复edge在下一次递归前的值
			}
		}
	}
}
```
---

java data structures, 

Hashtable<key, value>

Differences btw. Hashtable and HashMap (注意二者的正确写法)

1. HashMap is non synchronized. It is not-thread safe and can’t be shared between many threads without proper synchronization code whereas Hashtable is synchronized. It is thread-safe and can be shared with many threads.??
2. **HashMap allows one null key and multiple null values** whereas Hashtable doesn’t allow any null key or value.
3. HashMap is generally preferred over HashTable if thread synchronization is not needed

