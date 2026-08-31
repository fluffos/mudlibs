// - Inferno -  Inside the town of Asgard

#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("inside the town walls");
   set_long("You are inside the silver walls of Asgard. "
            "A small, paved road leads east. Along this "
            "road are several buildings. You do not notice "
            "guards of any sort other than the ones at the "
            "gates. The town gates lie to the west of here.");
   set_exits(([
      "west" : "/d/standard/frealmz/town_ent",
      "east" : "/d/standard/frealmz/town2"
   ]));
   set_items(([
      "walls" : "The large silver gates stand to the west.",
      "road" : "The road leads west through the town.",
      "buildings" : "They seem to be stores of some sort."
   ]));
}