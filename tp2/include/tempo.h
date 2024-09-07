#ifndef TEMPO_H_INCLUDED
#define TEMPO_H_INCLUDED

#include <unistd.h>
#include <sys/resource.h>

/* Calcula o tempo de usuário */
float diffUserTime(struct rusage *start, struct rusage *end);

/* Calcula o tempo de sistema */
float diffSystemTime(struct rusage *start, struct rusage *end);

#endif