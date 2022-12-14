// =================================================================
//
// File: example1.c
// Author: Pedro Perez
// Description: This file contains the code that adds all the
//				elements of an integer array. The time this
//				implementation takes will be used as the basis to
//				calculate the improvement obtained with parallel
//				technologies.
//
// Copyright (c) 2020 by Tecnologico de Monterrey.
// All Rights Reserved. May be reproduced for any non-commercial
// purpose.
//
// =================================================================

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "utils.h"

#define SIZE 1000000000 //1e9

double sum_array(int *array, int size) {
	double acum = 0;
	int i;

	for (i = 0; i < size; i++) {
		acum += array[i];
	}
	return acum;
}

int main(int argc, char* argv[]) {
	int i, *a;
	double ms, result;

	a = (int *) malloc(sizeof(int) * SIZE);
	fill_array(a, SIZE);
	display_array("a", a);

	printf("Starting...\n");
	ms = 0;
	for (i = 0; i < N; i++) {
		start_timer();

		result = sum_array(a, SIZE);

		ms += stop_timer();
	}
	printf("sum = %lf\n", result);
	printf("avg time = %.5lf ms\n", (ms / N));

	free(a);
	return 0;
}
