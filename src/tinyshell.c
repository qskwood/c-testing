#include <sys/wait.h>
#include <unistd.h>

extern int small_execve(const char * __file, char * const * __argv, char * const * __envp);
extern void small_exit(int);
extern pid_t small_fork(void);
extern ssize_t small_read(int, void *, size_t);
extern int small_waitid(idtype_t idtype, id_t id, siginfo_t *infop, int options, void*);
extern ssize_t small_write(int __fd, const void * __buf, size_t __nbyte);

int main(void) {
    char command[255];
    while ( 1 ) {
        small_write (1, "tinyshell# ", 11);
        int command_characters = small_read(0, command, 255);
        command[command_characters -1] = 0;
        pid_t fork_result = small_fork();
        if ( fork_result == 0 ) {
            small_execve(command, 0, 0);
            break;
        } else {
            siginfo_t info;
            small_waitid(P_ALL, 0, &info, WEXITED, 0);
        }
    }

    small_exit(0);
}
