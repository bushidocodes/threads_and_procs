#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "fibonacci.h"

#define NUMBER_OF_PROCESSES 11

__pid_t scatter(int nth);
int gather(__pid_t process_id);

// unsigned int
// fibonacci(unsigned int n)
// {
//     switch (n)
//     {
//     case 0:
//         return 0;
//         break;
//     case 1:
//         return 1;
//         break;
//     default:
//         return fibonacci(n - 1) + fibonacci(n - 2);
//         break;
//     }
// }

int main(void)
{
    __pid_t process_ids[NUMBER_OF_PROCESSES];
    for (int i = 0; i < NUMBER_OF_PROCESSES; i++)
    {
        process_ids[i] = scatter(i);
    }
    for (int i = 0; i < NUMBER_OF_PROCESSES; i++)
    {
        printf("Fib of %d is %d\n", i, gather(process_ids[i]));
    }
    return 0;
}

__pid_t scatter(int nth)
{
    __pid_t process_id = fork();
    if (process_id == 0)
    {
        exit(fibonacci(nth));
    }
    return process_id;
}
int gather(__pid_t process_id)
{
    int *status = malloc(sizeof(int));
    waitpid(process_id, status, 0);
    return WEXITSTATUS(*status);
}