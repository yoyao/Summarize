
/*
	
如果类只有一个带参数并且无默认参数的构造函数，那么new是无法new出此类的数组的。
***************************************************************
Person* p=operator new (size_t) 只申请内存，不会调用构造函数。
*******************************************************************
new(p) Person();  在p所指向的内存中调用Person的构造函数创建一个对象 (placement new 内存的定位放置)

*****************************************************************
static的成员函数是不可以访问类内的非静态成员变量的。因为static的成员在编译阶段就会给分配内存，其他的实在初始化的时候赋值。可能会访问出错。
=============***********************************************************
static的成员函数和变量是共享的 ，即 创建多少个对象，static成员都是指向最开始初始化的那一块内存。
=============================================================================
创建线程是的时候 不可以用类的成员函数 只能用全局函数。
=========================================================================
不可以同时用const和static修饰成员函数。
C++编译器在实现const的成员函数的时候为了确保该函数不能修改类的实例的状态，会在函数中添加一个隐式的参数const this*。但当一个成员为static的时候，该函数是没有this指针的。也就是说此时const的用法和static是冲突的。
========================================================================================
我们对于节点平衡有这样的定义：它是一棵空树或它的左右两个子树的高度差的绝对值不超过1，并且左右两个子树都是一棵平衡二叉树。而这里提到的高度差，就是我们下面会引入的平衡因子：BF。

     平衡二叉树旋转时有没有什么规则,比如是绕着哪个旋转,是左转还是右转...?
	 
在这里平衡的定义是：每个根节点的的左右子树的深度之差小于等于1.先构造二叉树,这个你会吧,之后在不平衡的地方旋转.规则是让该处根节点平衡,并且要满足二叉树的性质,即根节点左子树小于根节点,右子树大于根节点.
===================================================================================================


*/























































































































































