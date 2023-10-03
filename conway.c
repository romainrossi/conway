#include <stdio.h>

#include "world.h"
#include "evolve.h"


int main()
{
    world_t *world_a, *world_b, *w;
    world_a = world_create(10);
    world_b = world_create(10);
    world_clear( world_a );

    set_cell(world_a,2,1,1);
    set_cell(world_a,3,2,1);
    set_cell(world_a,3,3,1);
    set_cell(world_a,2,3,1);
    set_cell(world_a,1,3,1);

    for (int n = 0; n < 1000; n++)
    {
        world_show_ascii(world_a);
        usleep(50000);
        world_evolve(world_a, world_b);
        // swap the two worlds for next generation
        w = world_b;
        world_b = world_a;
        world_a = w;
    }
}
