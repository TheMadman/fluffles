#include <stdio.h>
#include <stdlib.h>

struct fluffle {
        char *name;
        double love,
               happiness,
               hunger;
};

double increase(double current);
double decrease(double current);
int loop(void);

double increase(double current)
{
        return 5 - (5 / (current + 2));
}

double decrease(double current)
{
        return 5 / current;
}

int loop(void)
{
        return 0;
}

char *name_loop(FILE *stream, char input, size_t size) {
        char *buffer;
        if (input &&
                (input == '\n' ||
                 input == EOF)) {
                buffer = malloc(size + 1);
                buffer[size] = '\0';
                return buffer;
        } else {
                buffer = name_loop(stream, getc(stream), size + 1);
                buffer[size] = input;
                return buffer;
        }
}

char *get_name(FILE *file)
{
        return name_loop(file, getc(file), 0);
}

int main(int argc, char **argv)
{
        struct fluffle players_fluffle = { 0 };
        printf("What's your fluffle's name?\n");
        players_fluffle.name = get_name(stdin);
        printf("Right! Your fluffle's name is %s!\n", players_fluffle.name);
        return loop();
}
