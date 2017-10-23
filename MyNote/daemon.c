#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <pwd.h>
#include <sys/signal.h>
#include <time.h>
#include <sys/time.h>

#define FILENAME_FORMAT "%s/template/%s.%d-%02d-%02d-%02d-%02d-%02d"
#define UMASK_MODE 0002
#define BUFFSIZE 256
void AlermFunc(int sig)
{
    char buf[BUFFSIZE]={0};

    //"%s/template/%s.%d%d%d"
    time_t ttime=time(NULL);
    struct tm* locatime;
    locatime= localtime(&ttime);
    //七点二十退出
    if(locatime->tm_hour==19&&locatime->tm_min==20)
    {
        exit(0);
    }

    sprintf(buf,FILENAME_FORMAT,getenv("HOME"),"main.out",(1900+locatime->tm_year),(locatime->tm_mon+1),locatime->tm_mday,locatime->tm_hour,locatime->tm_min,locatime->tm_sec);
    sigset_t nmask,oldmask;
    sigemptyset(&nmask);
    //获取原先的阻塞信号集并保存
    sigprocmask(SIG_BLOCK,NULL,&oldmask);
    nmask=oldmask;
    //添加SIGALRM信号至阻塞信号集
    sigaddset(&nmask,SIGALRM);
    //暂时屏蔽SIGALRM信号 以免来的时候这个还没处理完
    sigprocmask(SIG_BLOCK,&nmask,NULL);

    int fd =open(buf,O_RDWR|O_CREAT|O_APPEND,0666);
    if(fd<0)
    {
        perror("open error");
        exit(-1);
    }
    //mm:dd hh:mi:ss 程序名 [进程号]：消息内容
    sprintf(buf,"%02d:%02d %02d:%02d:%02d %s [%d]：%s \n",(locatime->tm_mon+1),locatime->tm_mday,locatime->tm_hour,locatime->tm_min,locatime->tm_sec,"main.out",getpid(),"这是消息");

    write(fd,buf,strlen(buf));
    close(fd);
    //处理完以后再恢复以前的状态
    sigprocmask(SIG_BLOCK,&oldmask,NULL);

}


int main(int argc, char *argv[])
{
    if(fork()>0)
    {
        exit(0);
    }
    //设置会话ID 自己当会长
    setsid();



    char buf[BUFFSIZE]={0};
     //切换工作目录
    chdir(getenv("HOME"));

    getcwd(buf,BUFFSIZE);
    puts(buf);

    //修改umask
    umask(UMASK_MODE);
    //执行逻辑
    //关闭资源描述符
    close(STDERR_FILENO);
    close(STDIN_FILENO);
    struct itimerval itimer={{30,0},{30,0}};
    setitimer(ITIMER_REAL,&itimer,NULL);


    struct sigaction action;
    sigemptyset(&action.sa_mask);
    action.sa_flags=0;
    action.sa_handler=AlermFunc;
    sigaction(SIGALRM,&action,NULL);
    close(STDOUT_FILENO);

    for(;;);


    //退出

    return 0;
}
