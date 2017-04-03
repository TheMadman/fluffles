#ifndef FLUFFLES_H
#define FLUFFLES_H

#include <stdio.h> // FILE data type for function signatures

struct fluffle {
        char *name;
        double love,
               happiness,
               hunger;
};

int strpos(const char *, const char);
int strany(const char *, const char *);
double increase(double);
double decrease(double);
double calc_love(double, double, double);
char *input_loop(FILE *, const char *delimiters);
char *name_loop(FILE *, char, size_t);
char *get_name(FILE *);
int loop(char, struct fluffle);
void clean(struct fluffle);

#endif // FLUFFLES_H
