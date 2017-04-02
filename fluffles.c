#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
        return current / ((current + 1) * 2);
}

double calc_love(double current, double happiness, double hunger)
{
        return 0;
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
        double happiness = current.happiness,
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


char *name_loop(FILE *stream, char input, size_t size)
{
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
        // return name_loop(file, getc(file), 0);
        const char delimiters[] = { '\n', EOF, '\0' };
        return input_loop(file, delimiters);
}

void clean(struct fluffle players_fluffle)
{
        free(players_fluffle.name);
}

int main(int argc, char **argv)
{
        struct fluffle players_fluffle = {
                0,
                hunger: 5.0
        };
        printf("What's your fluffle's name?\n");
        players_fluffle.name = get_name(stdin);
        printf("Right! Your fluffle's name is %s!\n", players_fluffle.name);
        return loop(0, players_fluffle);
}
