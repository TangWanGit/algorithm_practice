[TOC]
> 数据结构基本算法与练习

# 1. 数据结构学习过程中的算法
## 1.1 经典结构操作集
### 1-1 线性表的顺序存储结构实现
代码位置：ds/classic/1-1.c

### 1-2 线性表的链式存储结构实现
代码位置：ds/classic/1-2.c

### 1-3 堆栈的顺序存储结构实现
代码位置：ds/classic/1-3.c

### 1-4 堆栈的链式存储结构实现
代码位置：ds/classic/1-4.c

### 1-5 队列的顺序存储结构实现
代码位置：ds/classic/1-5.c

### 1-6 队列的链式存储结构实现
代码位置：ds/classic/1-6.c

### 1-7 二叉树的实现
ds/practice/6-9.c实现了递归算法
这里使用堆栈进行遍历

代码位置：ds/classic/1-7.c

### 1-8 线索二叉树的实现

代码位置：ds/classic/1-8.c

### 1-9 平衡二叉树的实现
实现了insert，未实现delete，且未确定insert是否正确

代码位置：ds/classic/1-9.c

### 1-10 最大堆的实现
代码位置：ds/classic/1-10.c

### 1-11 哈弗曼树构建

### 1-12 图的建立（邻接矩阵）
代码位置：ds/classic/1-12.c

### 1-13 图的建立（邻接表）
代码位置：ds/classic/1-13.c

### 1-14 最短路径

### 1-15 最小生成树


## 1.2 经典算法
### 2-1 最大子序列和
代码位置：ds/classic/2-1.c

### 7-2 一元多项式的乘法与加法运算
代码位置: ds/practice/7-2.c

### 2-2 计算ABCD按顺序入栈，有多少种pop结果
然后我们来考虑f(4), 我们给4个元素编号为a,b,c,d, 那么考虑：元素a只可能出现在1号位置，2号位置，3号位置和4号位置(很容易理解，一共就4个位置，比如abcd,元素a就在1号位置)。 
1) 如果元素a在1号位置，那么只可能a进栈，马上出栈，此时还剩元素b、c、d等待操作，就是子问题f(3) 
2) 如果元素a在2号位置，那么一定有一个元素比a先出栈，即有f(1)种可能顺序（只能是b），还剩c、d，即f(2) 
3) 如果元素a在3号位置，那么一定有两个元素比1先出栈，即有f(2)种可能顺序（只能是b、c），还剩d，即f(1) 
4) 如果元素a在4号位置，那么一定是a先进栈，最后出栈，那么元素b、c、d的出栈顺序即是此小问题的解，即 f(3)

结合所有情况，即f(4) = f(3) + f(2) * f(1) + f(1) * f(2) + f(3) 
为了规整化，我们定义f(0) = 1；于是f(4)可以重新写为： 
f(4) = f(0) * f(3) + f(1) * f(2) + f(2) * f(1) + f(3) * f(0) 
然后我们推广到n，推广思路和n=4时完全一样，于是我们可以得到： 
f(n) = f(0)*f(n-1) + f(1)*f(n-2) + … + f(n-1)*f(0) 
即


### 2-3 双向堆栈实现（使用数组实现）

代码位置：ds/classic/2-3.c

### 2-4 递归实现树的遍历（先序，中序，后序）
ds/practice/6-9.c实现了递归算法

### 2-5 非递归实现树的遍历（先序，中序，后序，层次）
这里使用堆栈进行遍历

代码位置：ds/classic/1-7.c

### 2-6 给出中序和后序，写出前序


# 2. PTA-数据结构与算法题目集
## 1. fn函数题
### 6-1. 单链表逆转
![link](https://pintia.cn/problem-sets/15/problems/724)

代码位置：ds/practice/6-1.c

### 6-2 顺序表操作集
![link](https://pintia.cn/problem-sets/15/problems/725)

代码位置：ds/practice/6-2.c

### 6-3 求链式表的表长
![](https://pintia.cn/problem-sets/15/problems/726)

代码位置：ds/practice/6-3.c

### 6-4 链式表的按序号查找
![](https://pintia.cn/problem-sets/15/problems/727)

代码位置：ds/practice/6-4.c

### 6-5 链式表操作集
![](https://pintia.cn/problem-sets/15/problems/728)

代码位置：ds/practice/6-5.c

### 6-6 带头结点的链式表操作集 
![](https://pintia.cn/problem-sets/15/problems/729)

代码位置：ds/practice/6-6.c

### 6-7 在一个数组中实现两个堆栈
![](https://pintia.cn/problem-sets/15/problems/730)

代码位置：ds/practice/6-7.c

### 6-8 求二叉树高度
![](https://pintia.cn/problem-sets/15/problems/731)

代码位置：ds/practice/6-8.c

### 6-9 二叉树的遍历
![](https://pintia.cn/problem-sets/15/problems/732)

代码位置：ds/practice/6-9.c

### 6-10 二分查找
![](https://pintia.cn/problem-sets/15/problems/923)

代码位置：ds/practice/6-10.c

### 6-11 先序输出叶结点
![](https://pintia.cn/problem-sets/15/problems/925)

代码位置：ds/practice/6-11.c

### 6-12 二叉搜索树的操作集
https://pintia.cn/problem-sets/15/problems/927

代码位置：ds/practice/6-12.c


## 2. 编程题

### 7-1 最大子列和问题 
![](https://pintia.cn/problem-sets/15/problems/709)

代码位置: ds/practice/7-1.c

### 7-2 一元多项式的乘法与加法运算 
![](https://pintia.cn/problem-sets/15/problems/710)

代码位置: ds/practice/7-2.c

### 7-3 树的同构
![](https://pintia.cn/problem-sets/15/problems/711)

代码位置: ds/practice/7-3.c

### 7-4 是否同一棵二叉搜索树 
![](https://pintia.cn/problem-sets/15/problems/712)

代码位置: ds/practice/7-4.c

### 7-5 堆中的路径
![](https://pintia.cn/problem-sets/15/problems/713)

代码位置: ds/practice/7-5.c

### 7-6 列出连通集 
![](https://pintia.cn/problem-sets/15/problems/714)

使用矩阵表示图，然后分别使用BFS和DFS遍历图

代码位置: ds/practice/7-6.c

### 7-7 六度空间
![](https://pintia.cn/problem-sets/15/problems/715)

代码位置: ds/practice/7-7.c

### 7-8 哈利·波特的考试
![](https://pintia.cn/problem-sets/15/problems/716)

代码位置: ds/practice/7-8.c

### 7-9 旅游规划
![](https://pintia.cn/problem-sets/15/problems/717)

代码位置: ds/practice/7-9.c

### 7-10 公路村村通 
![](https://pintia.cn/problem-sets/15/problems/718)

代码位置: ds/practice/7-10.c

### 7-14 电话聊天狂人 
![](https://pintia.cn/problem-sets/15/problems/722)


代码位置: ds/practice/7-14.c


# 3. PTA-数据结构与算法题目集-英文
## 1. fn函数题
### 6-1 Deque 双端队列
![](https://pintia.cn/problem-sets/16/problems/696)
使用一个Head结点作为头结点，Front结点始终指向Head结点，Rear结点指向最后一个结点，当链表为空时，Front和Rear同时指向Head结点

代码位置：ds/practice/en/6-1.c

### 6-2 Two Stacks In One Array 使用数组实现双堆栈
![](https://pintia.cn/problem-sets/16/problems/697)

代码位置：ds/practice/en/6-2.c

### 6-3 Add Two Polynomials
![](https://pintia.cn/problem-sets/16/problems/698)
Write a function to add two polynomials. Do not destroy the input. Use a linked ds implementation with a dummy head node. Note: The zero polynomial is represented by an empty ds with only the dummy head node.

写一个函数来添加两个多项式。不要破坏输入。使用带有伪头节点的链表实现。注意:零多项式由一个空列表表示，只有伪头节点。

代码位置：ds/practice/en/6-3.c

### 6-4 Reverse Linked ds
![](https://pintia.cn/problem-sets/16/problems/699)
Write a nonrecursive procedure to reverse a singly linked ds in O(N) time using constant extra space.
编写一个非递归过程，使用固定的额外空间在O(N)时间内反转单链表。

nonrecursive 
非递归

代码位置：ds/practice/en/6-4.c

### 6-5 Evaluate Postfix Expression 
![](https://pintia.cn/problem-sets/16/problems/700)

代码位置：ds/practice/en/6-5.c


## 2. 编程题
### 7-8 File Transfer
![](https://pintia.cn/problem-sets/16/problems/670)

代码位置：ds/practice/en/7-8.c

# 4. 中国大学MOOC-陈越、何钦铭-数据结构-起步能力自测题
## 自测-1 打印沙漏
![](https://pintia.cn/problem-sets/17/problems/260)



汇编语言 王爽版
深入理解计算机系统 Computer Systems
现代操作系统 Modern Operating Systems
计算机网络 自顶向下方法 Computer Networking
离散数学及其应用
数据库系统概念
C++程序设计语言
编码：隐匿在计算机软硬件背后的语言

C 语言程序设计语言
C Primer Plus
C和指针
C陷阱与缺陷



