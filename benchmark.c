/*
*Filename: 		benchmark.c
*Author: 		Jonathan Delgado
*Description: 	Implementation of benchmark program
*/

/******************************Include******************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/******************************Definitions******************************/
//Function that takes in another function from a library
//and uses it to perform a shrewd benchmark
double benchmark_general(void (*test)(void)) {
	//Converting factor to measure in milliseconds
	const double SECS_TO_MILLI = 1000.0;
	double start, end;
	//Will measure time difference in milliseconds
	start = clock() * SECS_TO_MILLI / CLOCKS_PER_SEC;

	(*test)();

	end = clock() * SECS_TO_MILLI / CLOCKS_PER_SEC;	

	//Some output padding
	printf("\n\n");

	printf("Start time: %f ms\nEnd time: %f ms\n", start, end);
	double time_elapsed_ms = end - start;
	printf("Time elapsed: %f ms\n", time_elapsed_ms);

	//Some output padding
	printf("\n\n");

	return time_elapsed_ms;
}

double benchmark_general_multi(void (*test)(void), int runs) {
	//Array holding the time entries for each time elapsed
	double times[runs];
	//Total time for averaging
	double total_time_ms = 0;

	for(int i = 0; i < runs; i++) {
		times[i] = benchmark_general(test);
		total_time_ms += times[i];
	}

	double average = total_time_ms / runs;

	//Some output padding
	printf("\n\n");

	printf("Total amount of runs: %d\n", runs);
	printf("Total time elapsed: %f ms\n", total_time_ms);
	printf("Average time elapsed: %.10f ms\n", average);

	printf("\n\n");

	return average;
}
/******************************End Definitions******************************/