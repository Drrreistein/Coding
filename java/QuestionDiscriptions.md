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

判断s2是否为s1的乱序子串

## Recursion

### ScrambleString (not finished)

判断s2是否为s1的乱序子串