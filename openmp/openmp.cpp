#include <omp.h>
#include <iostream>

using namespace std;


/*

	// BASIC LAYOUT IS AS FOLLOWS

	#pragma omp parallel				\
	if(condition)						\
	private(var1, var2)					\
	firstprivate(var3, var4)			\
	default(private | shared | none)	\
	shared(var5, var6)					\
	copyin(var7,var8,var9)				\
	reduction(operator:list)			\
	num_threads(n)						\
	{
		//.. code goes here
	}
*/


int main()
{

	return 0;
}