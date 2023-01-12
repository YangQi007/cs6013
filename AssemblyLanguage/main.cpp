#include <iostream>
#include <sys/time.h>

extern "C" {
void sayHello();
void myPuts(const char* string, int StringLen);
timeval myGTOD();
}

int main(int argc, const char * argv[]) {
    sayHello();
    myPuts("", 8);

    timeval myTime;
    timeval theirTime;

    myTime = myGTOD();
    gettimeofday(&theirTime, NULL);

    std::cout << myTime.tv_sec - theirTime.tv_sec << std::endl;
    std::cout <<myTime.tv_sec << "\n";
    std::cout <<theirTime.tv_sec << "\n";
}

