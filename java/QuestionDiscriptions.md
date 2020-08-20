## dp

解决思路：

1. 大的问题拆分为子问题，并找到递归关系；
2. 建立一张表，来存储子问题的最优解。

### Backpack01

01背包问题，n种物品，每种数量只有一个；尽可能的装在有限容量的包里，使得收益最高。

### Backpack

n中物品，每种数量不止1个；尽可能的装在有限容量的包里，使得收益最高。

### BisectedSet

将一个整数数组二等分，使得两个子集和相等。返回true或者false

### ClimbStairs

爬楼梯的方法，一次可以跨一个台阶或者两个台阶；very easy

### NumDistinct

判断s的多少种t的子序列等于t字符串。s的子序列是通过删减部分s中的字母形成，剩余字母顺序不变

S ="rabbbit", T ="rabbit"，返回3。

S = "ABCDE", T="AEC"， 返回0。

### ScrambleString (not finished)

判断s2是否为s1的乱序子串（不知道怎么用dp的方法）

### WordBreak

判断字符串s是否可有字典dict中的单词组合而成

### MinCandy

给一排不同ratings的孩子分糖，要求发的糖最少。两个方法

### MinDistanceOfWords

返回两个单词的最近距离。

### PartitionPalindrome (not finished)

分割字符串s为多个回文串的最简分割方法，return int

（一开始的方向就错了。。。

## Recursion

### ScrambleString (not pefect run in nowcoder)

判断s2是否为s1的乱序子串

### WordBreak

判断字符串s是否可有字典dict中的单词组合而成， not succeed in nowcoder because running out of time

## Greedy

### WildCardMatching (not finished)

通配符匹配，

## BackTrack

### RestoreIPAdresses

将包含数字的字符串转化为IP的形式

"25525511135",
返回["255.255.11.135", "255.255.111.35"].

### PermutationRemoveDuplicates

找到一个列表元素所有不同的排列组合。

{1, 1, 2}  ->  {1, 1, 2}, {1, 2, 1上}, {2, 1, 1}

### SolveSudoku (copied)

very cool

### EulerKreis

08/20 # succeed one round

08/20 # succeed finally

判断是否存在这样的圆，经过所有的边；如果有，起点终点是？输出所有的可能。

<img src="C:\Users\18817\AppData\Roaming\Typora\typora-user-images\image-20200819232341776.png" alt="image-20200819232341776" style="zoom:18%;" />

### PermutationSequence

输出一端字符串全组合排列，特定位置的组合

two methods implemented