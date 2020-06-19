#include "mainwindow.h"

#include <QApplication>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "sockServer.h"

/*static void sig_handler(int sig){
    int retval;
    if ( sig == SIGCHLD ){
        wait(&retval);
        printf("CATCH SIGNAL PID=%d\n",getpid());
    }
}*/

int main(int argc, char *argv[])
{
    /*signal(SIGCHLD,sig_handler);
    sockServer *sS = new sockServer();
    pid_t PID = fork();
    if (PID == 0) {
        printf("[Child] I'm Child process\n");
        printf("[Child] Child's PID is %d\n", getpid());
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        a.exec();
    }
    else if (PID==-1){
        perror("fork()");
        exit(-1);
    }
    else {
        printf("[Parent] I'm Parent process\n");
        printf("[Parent] Parent's PID is %d\n", getpid());
        sS->check();
        if (sS->runnable == false)
            return 0;
        sS->run();
    }*/
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    a.exec();
    return 0;
}
