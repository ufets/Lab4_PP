#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#include "open_mp_w.h"
#include "alghorithm.h"

#define SIZE 100000
#define LIMIT 10000

int *create_array(int size, int limit)
{
    int *array = NULL;
    array = (int *)malloc(size * sizeof(int));

    if (array == NULL)
    {
        fprintf(stderr, RED_COLOR "\nMEMORY ERROR in create_array(int count)\n" RESET_COLOR);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % limit;
    }
    return array;
}


int main(int argc, char *argv[])
{
    check_openmp_support();
    check_locks();

    srand(time(NULL));
    int *array = create_array(SIZE, LIMIT);
    timing(array, SIZE);
    free(array);

    printf("\n");
    printf("\n");
    printf("\n");
    return 0;
}