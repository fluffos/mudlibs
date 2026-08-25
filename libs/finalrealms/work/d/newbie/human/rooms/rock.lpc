#include "path.h"
inherit "/std/outside";

create()
{
   ::create();
add_property("no_undead",1);
    set_light(LIGHT);
   set_short("Isle of Havmand: Rocks.");
    set_night_long("\nIsle of Havmand : Rocks\n\n"
    "   You can see the vague outline of the rocks, but only enough to realise "
    "that they are very sharp, and you will have to be careful where you put "
    "your feet. "
    "\n\n");
    add_smell("air","The smell of salt air is very strong here.\n");
    add_item(({"rock","rocks"}),"The black, needle-sharp rock is volcanic in "
    "origin, reminding you that this island was once a live volcano.\n");
    add_feel("rocks","The rocks are very sharp, and cut into your skin.\n");
   add_item("sea","You are looking out over the Sword Sea, the biggest sea "
      "in the Realms.\n");
    add_item("spray","A fine mist-like spray caused by the action of the "
    "waves hitting the rocks.\n");
    add_taste("air","The air tastes salty because of all the sea spray.\n");
    add_property("no_undead",1);

   this_object()->setup();
   ::reset();
}
void dest_me()
{
    ::dest_me();
}
