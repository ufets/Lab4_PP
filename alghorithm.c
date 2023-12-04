#include "alghorithm.h"

void check_locks()
{
    omp_lock_t sum_lock;
    omp_init_lock(&sum_lock);

    int sum = 0;
#pragma omp parallel
    {
        for (int i = 0; i < 10; ++i)
        {
            omp_set_lock(&sum_lock);
            sum++;
            omp_unset_lock(&sum_lock);
        }
    }
    omp_destroy_lock(&sum_lock);
    printf("sum of array = %d\n", sum);
}

void timing(int *array, int size)
{
    int num = 100;
    double result;
    for (int iter = 10; iter < 100000; iter *= 5)
    {
        printf("static[%d]\n", iter);
        result = 0;
        for (int i = 1; i <= 7; i++)
        {
            for (int j = 0; j < num; j++)
            {
                double start = omp_get_wtime();
                shell_sort_static(array, size, i, iter);
                double end = omp_get_wtime();
                result += end - start;
            }

            printf("%lf\n", result / num);
            result = 0;
        }
        printf("\n");
    }

    for (int iter = 10; iter < 100000; iter *= 5)
    {
        printf("\ndynamic[%d]\n", iter);
        result = 0;
        for (int i = 1; i <= 7; i++)
        {
            for (int j = 0; j < num; j++)
            {
                double start = omp_get_wtime();
                shell_sort_dynamic(array, size, i, iter);
                double end = omp_get_wtime();
                result += end - start;
            }

            printf("%lf\n", result / num);
            result = 0;
        }
        printf("\n");
    }

    result = 0;
    printf("\nauto\n");
    for (int i = 1; i <= 7; i++)
    {
        for (int j = 0; j < num; j++)
        {
            double start = omp_get_wtime();
            shell_sort_auto(array, size, i);
            double end = omp_get_wtime();
            result += end - start;
        }

        printf("%lf\n", result / num);
        result = 0;
    }
}

void shell_sort_static(int *array, int size, int threads, int iter)
{
    for (int step = size / 2; step > 0; step /= 2)
    {
#pragma omp parallel for shared(array, size, step) num_threads(threads) schedule(static, iter)

        for (int i = step; i < size; i++)
        {
            for (int j = i - step; j >= 0 && array[j] > array[j + step]; j -= step)
            {
                int temp = array[j];
                array[j] = array[j + step];
                array[j + step] = temp;
            }
        }
    }
}

void shell_sort_dynamic(int *array, int size, int threads, int iter)
{
    for (int step = size / 2; step > 0; step /= 2)
    {
#pragma omp parallel for shared(array, size, step) num_threads(threads) schedule(dynamic, iter)
        for (int i = step; i < size; i++)
        {
            for (int j = i - step; j >= 0 && array[j] > array[j + step]; j -= step)
            {
                int temp = array[j];
                array[j] = array[j + step];
                array[j + step] = temp;
            }
        }
    }
}

void shell_sort_auto(int *array, int size, int threads)
{
    for (int step = size / 2; step > 0; step /= 2)
    {
#pragma omp parallel for shared(array, size, step) num_threads(threads) schedule(auto)
        for (int i = step; i < size; i++)
        {
            for (int j = i - step; j >= 0 && array[j] > array[j + step]; j -= step)
            {
                int temp = array[j];
                array[j] = array[j + step];
                array[j + step] = temp;
            }
        }
    }
}