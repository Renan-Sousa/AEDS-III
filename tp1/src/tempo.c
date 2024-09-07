#include <stdio.h>
#include "tempo.h"

/* Calcula o tempo de usuário em segundos*/
float diffUserTime(struct rusage *start, struct rusage *end) {
    return (end->ru_utime.tv_sec - start->ru_utime.tv_sec) +
        1e-6*(end->ru_utime.tv_usec - start->ru_utime.tv_usec);
}

/* Calcula o tempo de sistema em segundos*/
float diffSystemTime(struct rusage *start, struct rusage *end) {
    return (end->ru_stime.tv_sec - start->ru_stime.tv_sec) +
        1e-6*(end->ru_stime.tv_usec - start->ru_stime.tv_usec);
}
