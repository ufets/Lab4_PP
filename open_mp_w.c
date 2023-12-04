#include "open_mp_w.h"

/// @brief Checking does openmp supports
void check_openmp_support()
{
#ifdef _OPENMP
    print_open_mp_info();
    return;
#endif
    fprintf(stderr, RED_COLOR "OpenMP not suppoted\n\n" RESET_COLOR);
    exit(EXIT_FAILURE);
}

void print_open_mp_info()
{
    printf("\nOpenMP vesion: %d\n", _OPENMP);

    printf("number of cores: %d\n", omp_get_num_procs());
    printf("number of threads: %d\n", omp_get_num_threads());

    // dynamic distribution of iterations between threads
    printf("dynamic enabled: %d\n", omp_get_dynamic());
    // the size of the minimum time interval that can be measured using
    printf("dynamic enabled: %.10lf\n", omp_get_wtick());
    // is nested parallelism enabled
    printf("nested parallelism enabled: %d\n", omp_get_nested());
    printf("Maximum levels of nested parallelism: %d\n", omp_get_active_level());

    omp_sched_t type;
    int chunk_size;
    omp_get_schedule(&type, &chunk_size);
    print_about_schedule(type, chunk_size);
}

void print_about_schedule(const omp_sched_t type, int chunk_size)
{
    printf("Current schedule: ");
    switch (type)
    {
    case omp_sched_static:
        printf("Static");
        break;
    case omp_sched_dynamic:
        printf("Dynamic");
        break;
    case omp_sched_guided:
        printf("Guided");
        break;
    case omp_sched_auto:
        printf("Auto");
        break;
    default:
        printf("Unknown");
        break;
    }
    printf(", %d\n", chunk_size);
}