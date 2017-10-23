  
/*
有最优子结构（能定下来的答案，不能模棱两可），子问题重叠（问题相同的性质的都是），有边界限定（即跳出循环的条件），子问题独立（各个子问题不互相影响),备忘录（记录下问题的状态，（通常是一个辅助的二维数组）能减少计算的次数，提升效率。
这样的问题可以用动态规划
*/







/*
以我在第1小节举的例子（S1={1,3,4,5,6,7,7,8}和S2={3,5,7,4,8,6,7,8,2}），并结合上图来说：
假如S1的最后一个元素 与 S2的最后一个元素相等，那么S1和S2的LCS就等于 {S1减去最后一个元素} 与 {S2减去最后一个元素} 的 LCS  再加上 S1和S2相等的最后一个元素。
假如S1的最后一个元素 与 S2的最后一个元素不等（本例子就是属于这种情况），那么S1和S2的LCS就等于 ： {S1减去最后一个元素} 与 S2 的LCS， {S2减去最后一个元素} 与 S1 的LCS 中的最大的那个序列。
*/

/**********
//重点在理解上面这两句话，其实代码很简单 就是对这两句话的映射。 理解的问题的关键是在理解那个公式。其实每个字符和另一个字符的比较可以认为是从0开始至比较字符的长度的字符 和另一个字符的每个长度相比  得出的最长子序列。因为是从第一个字符开始的，所以相当于从零开始。
 1.如果两个串的某个位置出现相等的字符，就是说它是整个字符串最长子序列的一员，同时也是两个字符串截止至此的的位置上最长子序列的最后一位，应该在他的位置做个标记。应该在此位置设为1。此位置的左上角是两个字符串各自减去一个字符长度的最长子序列位置。假如把他们加在一起，加到最后，正好是记录着最长子序列的长度。所以加上此位置相等，所以整体最长子序列的长度要+1；

 2.如果两个串的某个位置的字符不等,就是说两个串截止至此的字串的最长子序列出现在各自减1的位置上。由1可知，在辅助的二维数组上的位置分别为[i-1][j]或者[i][j-1]，所以当前位置依旧需要保存下截至到当前位置的最长子序列长度（选择两个长度中的最大的保存）。假如当前位置的Y轴不变X轴出现了相等的字符 那也不算 因为位置串了。不是子序列。

 3.全部算完以后，最后一个位置保存的一定是两个字符串的最长子序列的的长度。根据上面的两条特性可知，如果二维数组的的最后一个位置的的左上角X,Y坐标的位置的两个字符相等，那最后的长度就是左上角加1后的长度，既然是+1而来的，就是说这个字符也是最长子序列的一员，记录下来。如果左上角不等，那就看[j]和[i][j-1]谁大，谁大就是从谁那继承过来的，记录这个位置的字符,然后依此类推。直到二维数组中X,Y的值等于0，那么就是字序列断了。跳出循环。但是此时的字符是逆序的，需要处理。
**********/

/*
  int *p = new int(5);
  //new 出来一个5个int大小的数组
  int *p_p = new Person(4);//这是在给Person类的构造函数传参。
   int *p_p = new Person[12];//这是new一个12个Person的数组。
   //非关键字类型在new时用小括号代表说明容量。类型用小括号是代表给构造传参
   */
