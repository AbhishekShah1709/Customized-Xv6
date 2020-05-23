#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
    int pid;
    int k,n;
    int x, z;
    int *rtime = malloc(sizeof(int));
    int *wtime = malloc(sizeof(int));
    if (argc != 2)
    {
        printf(2, "usage: %s n\n", argv[0]);
    }
    n = atoi(argv[1]);
    if (fork() == 0)
    {
        for (k = 0; k < n; k++)
        {
            pid = fork();
            if (pid < 0)
            {
                exit();
            }
            else if (pid == 0)
            {
                chpr(80-k);
                sleep(1000);
                // printf(1,"child=%d\n",getpid());
                for (z = 0; z < 10000000; z++)
                {
                    x = (x + 25 * 65); // useless calculations to consume CPU time
                    x = 0;
                    printf(1,"");
                }
                exit();
            }
        }

        for (k = 0; k < n; k++)
        {
            int pid = waitx(wtime, rtime);
            printf(1,"Process with pid=%d wtime=%d rtime=%d\n",pid,*wtime,*rtime);
        }
        
        exit();
    }
    else
    {
        int pid=waitx(wtime,rtime);
        printf(1,"time=%d\n",(*rtime)+(*wtime));
        printf(1,"pid -- %d\n",pid);
    }
    
    exit();
}
