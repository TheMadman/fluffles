#include "fluffles.h"

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
