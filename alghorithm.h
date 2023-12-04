#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include "time.h"
#include "open_mp_w.h"
#pragma once

void check_locks();
void timing(int *array, int size);
void shell_sort_static(int *array, int size, int threads, int iter);
void shell_sort_dynamic(int *array, int size, int threads, int iter);
void shell_sort_auto(int *array, int size, int threads);