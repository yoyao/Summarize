
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

子进程结束时会给父进程发送一个SIGCHLD信号 
父进程结束时不会回收其任何子进程
sleep()时，只要有任何信号进入都会从睡眠中醒来。
pause()在收到SIGCHLD不会结束，而在SIGALRM会从睡眠中醒来，并执行相应的信号处理方法。

sigset_t 阻塞信号类型

sigemptyset  设置阻塞信号集 这样在程序执行期间 如果遇到阻塞信号集中的信号，系统将不会把信号发送给进程，而是记录在未决信号集中
，当此信号从阻塞信号集中取消时，系统会把记录在未决信号集中的信号发送给进程，进程会处理。

==================================================================================================================
pthread_cond_wait();
当急需某个条件成立时，我才能继续执行下去，这样才会使用条件变量等待其条件成立。如果我只是需要某个资源，用mutex就可以了。
#include<pwd.h>
#include <sys/types.h>

getpwnam(char* username)//通过用户名来获取密码信息

getspwnam(char* username)//通过用户名来获取shadow密码信息

crypt(char* key,char* salt);//DES加密方法  linux中的密码是用它来加密的

set-User-ID  在其他用户拥有执行权限的情况下，允许其他用户暂时以此程序的所有者的权限运行,在程序结束后恢复身份。
假如我的一个程序的所有者是root 我为这个程序设置了 chmod u+s ，那么其他用户运行此程序时，会以root权限运行。
如果这个程序的所有者是fgo,那么运行时的权限是fgo

chmod u+s 给某一个文件suid的权利

只有真实用户ID(real ID)或实际用户ID(efficktive ID)相同的进程才可以互相发送信号。

==================================================================================

UDP发送端是可以不绑定IP的默认会以本机的IP发送  但仅限于纯发送 不涉及接收 接收端是要绑定IP的 因为要让内核知道你绑定的是哪一个端口。这样才能监听指定端口。

TCP是不可以的，因为TCP的客户端连接的时候必须知道服务器端的端口才能连接，所以服务端必须指定端口 

==================================================================================================
libevent的epoll默认是水平触发模式

==================================================================================
Centos7没有有线的原因可能是MAC地址的原因 去/etc/udev/rules.d/70-xxx-cfg把里面和/etc/systemconfig/network-scripts/ifcfg-ens33里面的HWADDR同一一下还有Name也要统一一下，这样做应该是将网络托管给NetworkManager。
并且要保证NetworkManager.service的服务是 enable的 
或者用ifconfig -a的方式看一下系统分配的MAC地址 将他们统一

=========================================================================

共享内存：
 一个进程可以通过制定IPC_EXCL标记来确保他是创建IPC对象的进程，如果指定了IPC_EXCL并且与给定key对应的IPC对象已经存在，那么get调用会失败并返回EEXIST错误

==========================================================================================
socket accept收不到客户端IP  把 socket_len参数的初始化为 struct sockaddr_in的大小即可 

================================================================================================
fast_cgi在处理请求的时候，维护的是一个消息队列 当有一个新的请求到来的时候，向队列中增加一个任务，如果是单线程，那么只能处理一个消息

http请求 同一IP 同一请求路径 服务器不会做并行处理（即一个请求未处理完，另一个同样ip同样请求路径的http请求不能同时处理）
     IP和请求路径必须有一个是不相同的
=================================================================================================
“信号量用在多线程多任务同步的，一个线程完成了某一个动作就通过信号量告诉别的线程，别的线程再进行某些动作（大家都在semtake的时候，就阻塞在 哪里）。而互斥锁是用在多线程多任务互斥的，一个线程占用了某一个资源，那么别的线程就无法访问，直到这个线程unlock，其他的线程才开始可以利用这 个资源。比如对全局变量的访问，有时要加锁，操作完了，在解锁。有的时候锁和信号量会同时使用的”
================================================================================================================
三次握手的最主要目的是保证连接是双工的，可靠更多的是通过重传机制来保证的。 
=======================================================================================
mysql服务启动时报错：The server quit without updating PID file
日志内报错:Can't open the mysql.plugin table. Please run mysql_upgrade to create it.
使用下面命令解决（初始化数据库，并且要保证所有文件对mysqld的进程是可读写 sudo chown -R mysql:mysql）
sudo /usr/local/mysql/bin/mysqld --initialize-insecure
==========================================================================================

*********************************************************************************

p12(或者pfx)文件里一般存放有CA的根证书,用户证书和用户的私钥

假设我们有一个test.p12文件

在安装了openssl的linux服务器上执行以下命令:

提取用户证书:

openssl pkcs12 -in test.p12 -clcerts -nokeys -out cert.pem  //pem格式
openssl pkcs12 -in test.p12 -clcerts -nokeys -out cert.crt  //crt格式
如果需要携带秘钥,则去掉 -nokeys

openssl pkcs12 -in test.p12 -clcerts  -out cert.pem  //pem格式
openssl pkcs12 -in test.p12 -clcerts  -out cert.crt  //crt格式
 

提取私钥:

openssl pkcs12 -in test.p12 -nocerts -out key.pem
 

清除秘钥中的密码(在把秘钥部署到某些服务器上时可能需要清除密码)

openssl rsa -in key.pem -out newkey.pem


Enter Import Password:  这个是让你输入生成.p12文件时候的密码

MAC verified OK这是提示信息，正确的话会出现这个

Enter PEM pass phrase:  这句话的含义是输入一个加密密码

Verifying – Enter PEM pass phrase:  这是确认加密密码

 pass phrase 可以不用输入，这个时候生成的p12就默认没有私钥




********************************************************************************************















































































































































*/
