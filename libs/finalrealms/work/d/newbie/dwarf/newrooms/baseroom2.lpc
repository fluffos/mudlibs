#include "path.h"
inherit "/std/room";
string * npcs = ({"cave_rat","bat","spider","snake","lizard"});
#define MAXNPC 4

void my_setup()
{
   add_property("no_undead",1);
   add_clone(CHAR+npcs[random(sizeof(npcs))],random(MAXNPC));
}
