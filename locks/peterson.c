#include <stdio.h>

void petersonLock(int thread_id, int &turn, int * flag)
{
	flag[thread_id] = 1;
	turn = 1 - thread_id; // 1 if 0, 0 if 1

	while(flag[turn]==1 && turn==1-thread_id);

	// critical section code here

	flag[thread_id] = 0;
}