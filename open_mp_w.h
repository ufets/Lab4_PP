#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#pragma once

#define RED_COLOR "\x1b[31m"
#define RESET_COLOR "\x1b[0m"

/// @brief Different codes of errors
enum CODES
{
    ERROR,
    OK
};

void check_openmp_support();
void print_open_mp_info();
void print_about_schedule();
void print_about_schedule(omp_sched_t type, int chunk_size);