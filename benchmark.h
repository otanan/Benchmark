/*
*Filename: 		benchmark.h
*Author: 		Jonathan Delgado
*Description: 	Public functions for using the benchmark program
*/


/*
*Function: benchmark_general
*-----------------------------
*General test function. Takes a time difference from before a function
*passed in is run, versus when it completed runnings
*
*void (*test)(): 	Function pointer, pointing to the function to be benchmarked
*arg2: 	arg2 is the second argument
*
*returns: 		returns the time elapsed for the benchmark
*/
double benchmark_general(void (*test)(void));

/*
*Function: benchmark_general_multi
*-----------------------------
*Runs the general test function multiple times to improve the
*average and gather more informed statistics. Prints information about
*the running and average to stdout
*
*void (*test)(): 	Function pointer, pointing to the function to be benchmarked
*int runs: 			The amount of times for the benchmark to be run
*
*returns: 			Reteurns the average time to run the function
*/
double benchmark_general_multi(void (*test)(void), int runs);