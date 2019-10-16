#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>

#define NUMBER_OF_PROCESSES 11

pthread_t scatter(int nth, pthread_t *thread_id);

int gather(pthread_t thread_id);

unsigned int
fibonacci(unsigned int n)
{
    switch (n)
    {
    case 0:
        return 0;
        break;
    case 1:
        return 1;
        break;
    default:
        return fibonacci(n - 1) + fibonacci(n - 2);
        break;
    }
}

void *fibb_wrapped(void *raw_n)
{
    void *result = malloc(sizeof(unsigned int));
    unsigned int n = *(unsigned int *)raw_n;
    *(unsigned int *)result = fibonacci(n);
    return result;
    // return fibonacci
}

int main(void)
{
    pthread_t process_ids[NUMBER_OF_PROCESSES];
    for (int i = 0; i < NUMBER_OF_PROCESSES; i++)
    {
         int rc = pthread_create(&process_ids[i], 0, fibb_wrapped, &i);
         if (rc != 0) {
             printf("unable to allocate thread. RC %d", rc);
             exit(1);
         }
    }
    
    for (int i = 0; i < NUMBER_OF_PROCESSES; i++)
    {
        void *result;
        pthread_join(process_ids[i], &result);
        printf("Fib of %d is %d\n", i, *(int *)result);
        free(result);
    }
    pthread_exit(0);
    // return 0;
}
