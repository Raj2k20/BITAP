#ifndef BITAP_H
#define BITAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <omp.h>
// #include <cstdio>

#define TEXTMAX 100000

int k;

void tick(struct timeval *t);
double tock(struct timeval *t);
void SearchString(int *array, const char *text, const char *pattern);
void SearchString_pragma(int *a, const char *text, const char *pattern);
void SearchString_opt(int* a, const char *text, const char *pattern);
void SearchString_opt_pragma(int* a, const char *text, const char *pattern);

#endif