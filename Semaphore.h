#ifndef SEMAPHORE_H
#define SEMAPHORE_H

class Semaphore 
{
public:

	Semaphore(int count);
	~Semaphore();

	void wait();
	void signal();
	
	int semCount;

private:

	pthread_cond_t cond;
	pthread_mutex_t lock;

};

#endif
