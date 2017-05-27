#include <omp.h>
#include <iostream>

using namespace std;


/*

	// BASIC LAYOUT OF A PARALLEL CONSTRUCT IS AS FOLLOWS
	// WHOEVER ENCOUNTERS THIS PARALLEL CONSTRUCT IS THE MASTER

	#pragma omp parallel				\
	if(condition)						\
	private(var1, var2)					\	// each thread will have a private copy of var1 and var2
											// ANY DECLARATIONS INSIDE THE SCOPE IS PRIVATE AND WE CANNOT MAKE IT SHARED
	firstprivate(var3, var4)			\	// each thread will have a private copy of var3 and var4, and they will be initialized with the master's copy : like a broadcast of these two variables to every thread
	default(private | shared | none)	\	// by default, this is shared, for all variables (everything that is getting used)
	shared(var5, var6)					\	
	copyin(var7,var8,var9)				\	// similar to first private, except it can come from any one of the threads (need not come from master)
											// destination is EVERYONE, source needs to be specified somehow
	reduction(operator:list)			\	// how to collate the results
	num_threads(n)						\	// how many threads to run
	{
		//.. scope
	}
*/

/* 

	// PARALLEL FOR CONSTRUCT

	#pragma omp for 					\	// expecting this to be in a parallel construct (so we don't write #pragma omp parallel for)
	private(i,j,k)						\
	firstprivate(i,j,k)					\
	lastprivate(i,j,k),					\
	reduction(operator:list),			\
	ordered,							\	// ordered construct has to be executed in order (implicit locking)
											// one thread finishes and then the next thread executes
											// different threads execute concurrently until they encounter the ordered region, which is then executed sequentially in the same order as it would get executed in a serial loop.
	schedule(kind[,chunk_size])			\	// kind is what type of distro to do. chunk_size is how many chunks
											// instead of saying thread0 should take i=0, thread1 should take i=1 etc etc.. we can say, thread0 goes from i=0 to 3, thread1 goes from i=4 to i=7 etc
	nowait								

	for(int i=0; i<10; i++)
	{}

	// Restrictions:
	//	- same loop control expression for all threads in the team
	//	- at most one schedule, nowait, ordered clause
	//	- chunk_size must be a loop / construct invariant, +ve integer
	//	- ordered clause required if any ordered region inside

*/

int main()
{
	int numProcessors = omp_get_num_procs();
	cout << numProcessors << endl;
	return 0;
}