
/*


========================================================================

exec函数族中：
不带e的函数给定的执行命令要是绝对路径。
exec函数族是会替换当前进程的所有资源的。

===========================================================================

vim:
 v选中后 d是剪切 dd是剪切一整行  y是复制  yy是复制一整行  
 ：f是查看当前文件名 
 :!pwd 查看当前文件的全路径
 O 当前行的上一行插入一行
 x 删除光标所在的单个字符
=================================================================================================
 
 jobs 查看正在后台运行的程序
 
 ==================================================================================================
 
 信号：
   如果有进程发出任何一个信号，但是没有捕获的进程，那么当前进程立即停止，并生成核心转存文件。
 
 ========================================================================================================
 
程序的唯一的区别就在于一个/n回车符号，为什么结果会相差这么大呢？
    这就跟printf的缓冲机制有关了，printf某些内容时，操作系统仅仅是把该内容放到了stdout的缓冲队列里了,并没有实际的写到屏幕上。

但是,只要看到有/n 则会立即刷新stdout,因此就马上能够打印了。
    运行了printf("fork!")后,“fork!”仅仅被放到了缓冲里,程序运行到fork时缓冲里面的“fork!”  被子进程复制过去了。因此在子进程度stdout

缓冲里面就也有了fork! 。所以,你最终看到的会是fork!  被printf了2次！！！！

===========================================================================================================

信号的安排很重要，有时候等待一个信号，可是在等待指令（如 pause）还没有执行的时候可能信号就已经发过了，这可能导致程序在等待一个不会发生的事情 这样是没有意义的。

==============================================================================================================

alarm函数是向当前进程发送SIGALRM信号

==============================================================

int sigfillset(sigset_t* set)//将set设置为所有已定义的信号
int sigemptyset(sigset_t* set)//将set置空
int sigdelset(sigset_t* set,int signo)//将signo从set中删除
int sigaddset(sigset_t* set,int signo)//将signo添加到set中
int sigismember(sigset_t* set,int signo)//判断signo是否是set中的一员

所有函数都是成功返回0 失败返回-1
==============================================================

sigaction是不会阻塞进程的。

sigprocmask 是修改当前进程的屏蔽信号集

==============================================================

fork()出来的进程是会拷贝一份其父进程的副本 但是它的调度是和父进程同级别的 拥有自己独立的堆栈和PID

新的线程pthread 有自己独立的栈，但是和所在进程共享全局函数，全局变量，文件描述符

======================================================================================================

Ubuntu 下默认使用的是NPTL 使用线程的时候要在最后加上 -lpthread
Centos 下默认使用的是NPTL 使用线程的时候要在最后加上 -lpthread

======================================================================================================

对一个互斥量加锁时，如果这个互斥量已经加了锁（pthread_mutex_lock()) 那么线程进入阻塞状态，直到此资源被释放，
它会继续按步骤向下执行

======================================================================================================

当线程设置了PTHREAD_CANCEL_ENABLE属性的时候
当它接收到pthread_cancel信号的时候会立即结束自己（即使是在睡眠），但是阻塞状态下不行

线程函数可以当普通函数调用 但是函数内不能有操作线程的语句，这样容易出错 造成死循环
===============================================================================================================










*/
