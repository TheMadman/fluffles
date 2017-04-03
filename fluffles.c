#include <string.h>
#include <stdlib.h>

#include "fluffles.h"

int strpos(const char *string, const char search) {
        int i = 0;
        char current;
        while (current = string[i++])
                if (current == search)
                        break;
        if (current == search)
                return i;
        else
                return -1;
}

int strany(const char *string, const char *any) {
        int i = 0,
            j = 0;
        while (i = strpos(string, any[j++]))
                if (i > -1)
                        break;
        return i;
}

double increase(double current)
{
        return 5 - (5 / (current + 2));
}

double decrease(double current)
{
        return current / 1.25;
}

double calc_love(double current, double happiness, double hunger)
{
        return current + ((happiness + hunger) / 10.0);
}

struct fluffle play(struct fluffle current)
{
        double happiness = increase(current.happiness),
               hunger = decrease(current.hunger);
        struct fluffle result = {
                current.name,
                calc_love(current.love, happiness, hunger),
                happiness,
                hunger
        };
        return result;
}

struct fluffle feed(struct fluffle current)
{
        double happiness = decrease(current.happiness),
               hunger = increase(current.hunger);
        struct fluffle result = {
                current.name,
                calc_love(current.love, happiness, hunger),
                happiness,
                hunger
        };
        return result;
}

void print_fluffle(struct fluffle fluffle)
{
        char *outformat = "%s's feelings:\n"
                "Love: %f\n"
                "Happiness: %f\n"
                "Hunger: %f\n";
        printf(
                        outformat,
                        fluffle.name,
                        fluffle.love,
                        fluffle.happiness,
                        fluffle.hunger
              );
}

int loop(char input, struct fluffle players_fluffle)
{
        struct fluffle update;
        switch (input) {
                case '\n':
                        return loop(getchar(), players_fluffle);
                case 'q':
                        clean(players_fluffle);
                        return 0;
                case 'p':
                        update = play(players_fluffle);
                        break;
                case 'f':
                        update = feed(players_fluffle);
                        break;
                case 'c':
                default:
                        update = players_fluffle;
        }
        print_fluffle(update);
        printf("Enter a command ([p]lay, [f]eed, [c]heck, [q]uit):");
        return loop(getchar(), update);
}

char *real_input_loop(FILE *stream, char input, size_t size, const char *delimiters)
{
        char *buffer;
        if (input && (strpos(delimiters, input) > -1)) {
                buffer = malloc(size + 1);
                buffer[size] = '\0';
                return buffer;
        } else {
                buffer = real_input_loop(stream, getc(stream), size + 1, delimiters);
                buffer[size] = input;
                return buffer;
        }
}
char *input_loop(FILE *stream, const char *delimiters)
{
        return real_input_loop(stream, getc(stream), 0, delimiters);
}

char *get_name(FILE *file)
{
        const char delimiters[] = { '\n', EOF, '\0' };
        return input_loop(file, delimiters);
}

void clean(struct fluffle players_fluffle)
{
        free(players_fluffle.name);
}


