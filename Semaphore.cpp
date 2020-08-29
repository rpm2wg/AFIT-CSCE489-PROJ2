#include <pthread.h>
#include "Semaphore.h"

/*
* Got help from: https://www.geeksforgeeks.org/mutex-lock-for-linux-thread-synchronization/
* and http://www.cs.kent.edu/~ruttan/sysprog/lectures/multi-thread/pthread_cond_init.html
*/

/*************************************************************************************
 * Semaphore (constructor) - this should take count and place it into a local variable.
 *						Here you can do any other initialization you may need.
 *
 *    Params:  count - initialization count for the semaphore
 * 
 *  Initializes mutex and initializes condition variable
 *************************************************************************************/

Semaphore::Semaphore(int count) 
{
    semCount = count;
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);
}


/*************************************************************************************
 * ~Semaphore (destructor) - called when the class is destroyed. Clean up any dynamic
 *						memory.
 *
 *  Destroys the created mutex
 *************************************************************************************/

Semaphore::~Semaphore() 
{
    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);
}


/*************************************************************************************
 * wait - implement a standard wait Semaphore method here
 *
 *************************************************************************************/

void Semaphore::wait() 
{
    pthread_mutex_lock(&lock);
    semCount--;
    if(semCount < 0)
    {
        pthread_cond_wait(&cond, &lock);
    }
    pthread_mutex_unlock(&lock);
}


/*************************************************************************************
 * signal - implement a standard signal Semaphore method here
 *
 *************************************************************************************/

void Semaphore::signal() 
{
    pthread_mutex_lock(&lock);
    semCount++;
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);
}


