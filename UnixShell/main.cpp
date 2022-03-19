#include <iostream>
#include <stdio.h>
#include<sstream>
#include <vector>
#include "shelpers.hpp"


int main(int argc, const char * argv[]) {
    std::string input;
    std::vector<std::string> tokens;

    while(getline(std::cin, input)) {
        tokens = tokenize(input);
        std::vector<Command> commands = getCommands(tokens);
        std::vector<pid_t> pids;

        for (int i = 0; i < commands.size(); i++) {

            if (commands[i].execName == "exit"){
                printf("Exit from the shell!");
                exit(0);
            }

            //fork a new process
            int pid = fork();

            if (pid < 0) {
                perror("fork failed!");
            }
                // child process
            else if (pid == 0) {
                dup2(commands[i].inputFd, 0);
                if (dup2(commands[i].inputFd, 0) == -1) {
                    perror("fdIn failed!");
                    exit(1);
                }
                dup2(commands[i].outputFd, 1);
                if (dup2(commands[i].outputFd, 1) == -1) {
                    perror("fdOut failed!");
                    exit(1);
                }
                    int ret = execvp(commands[i].execName.c_str(), const_cast<char *const *>(commands[i].argv.data()));
                    if (ret == -1) {
                        perror("execvp failed");
                        exit(1);
                    }
                }

                //parent process
            else {
                if (commands[i].inputFd != 0)
                    close(commands[i].inputFd);
                if (commands[i].outputFd != 1)
                    close(commands[i].outputFd);

                pids.push_back(pid);
                int Status;

                if (!commands[i].background) {
                    for (pid_t p: pids) {
                        waitpid(p, &Status, 0);
                    }
                } else {
                    for (pid_t p: pids) {
                        std::cout << p << std::endl;
                    }
                }

                // buildin command "cd"
                if (commands[i].execName == "cd") {
                    //debugging here: if the return is "0" "cd" command works right.
                    // printf("the res is : %d", res);
                    if (commands[i].argv.size() == 2) {
                        chdir(getenv("HOME"));
                    }
                    else if (commands[i].argv.size() > 2){
                        chdir(commands[i].argv[1]);
                    }
                }
            }
        }
        input.clear();
    }
return 0;
}
