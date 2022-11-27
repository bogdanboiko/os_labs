#include "sys/wait.h"
#include "stdio.h"
#include "unistd.h"

int main() {
    int pid0 = fork();

    if (pid0 == 0) {
        sleep(3);
        fork();
        sleep(3);
    } else {
        int pid1 = fork();

        if (pid1 == 0) {
            int pid2 = fork();

            if (pid2 == 0) {
                sleep(3);
            } else {
                fork();
                sleep(3);
            }
        } else
            fork();
            sleep(3);
        }
    return 0;
}
