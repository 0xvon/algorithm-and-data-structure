// 1X18C058, 堤 真聖, masato.11.soccer@ruri.waseda.jp
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int out[2], status;
    pid_t ret1, ret2;
    ret1 = fork();

    if(ret1 == 0) {
        pipe(out);
        ret2 = fork();

        if (ret2 == 0) {
            close(out[0]);
            dup2(out[1], 1);
            close(out[1]);
        } else {
            close(out[1]);
            dup2(out[0], 0);
            close(out[0]);

            execlp("wc", "wc", "-l", NULL);
        }
        execlp("uniq", "uniq", argv[1], NULL);
    } else {
        wait(&status);
    }

    return 0;
}
