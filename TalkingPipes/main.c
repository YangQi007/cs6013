/*In this assignment you'll write a simple program that spawns a new process using fork(),
 and sends a message from a child to its parent using a pipe.*/

// Created by YANG QI on 3/22/22.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    // open a pipe
    int fd[2];
    // fd[0] -reda
    // fd[1] -write
    if (pipe(fd) == -1){
        perror("Error happened opening the pipe!");
        exit(1);
    }

    int pid = fork();

    if(pid == -1){
        perror("Error happened with fork!");
        exit(1);
    }

    if (pid == 0){
        //In child process

        close(fd[1]);
        char str_[1000];
        printf("\nPrint from child process: ");
        read(fd[0], &str_, sizeof(str_));
        if (read(fd[0], &str_, sizeof(str_)) == -1){
            perror("Error happened when reading to pipe!");
            exit(1);
        }
        close(fd[0]);

        //read from parent
        printf("%s\n",str_);


    }

    else{
        //In parent process
        printf("We are in parent process:\n");
        close(fd[0]);
        char str[1000];
        printf("Write a word from command line:");
        scanf("%s",str);
        write(fd[1], &str,sizeof(str));
        if (write(fd[1], &str,sizeof(str)) == -1){
            perror("Error happened when writing to pipe!");
            exit(1);
        }
        close(fd[1]);

    }

    int pid_number = waitpid(pid,NULL,0);
    printf("Wait for the child process %d\n",pid_number);

    return 0;
}
