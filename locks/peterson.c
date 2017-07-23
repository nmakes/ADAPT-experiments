#include <stdio.h>

/*
	This implementation of Peterson lock is applicable 
	for two threads. When one thread requests a lock, it
	marks itself as a requesting thread (in flag array),
	and lets the other thread execute. If the other thread
	has to execute, it waits, otherwise it executes its
	critical section.
*/

void petersonLock(int thread_id, int *turn, int flag[])
{
	// mark as lock requesting thread
	flag[thread_id] = 1;

	// let the other thread execute first
	*turn = 1 - thread_id; // 1 if 0, 0 if 1

	// if the other thread is in its critical section, wait
	while(flag[*turn]==1 && *turn==1-thread_id);

	// critical section code here
	printf("Critical section of thread %d", thread_id);

	// unmark lock request
	flag[thread_id] = 0;
}
