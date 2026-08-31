#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties(([ "town" : 1, "light" : 2, "night light" : 1 ]));
   set_short("Traveling further south of Lodos");
   set_day_long("The constant eastern and southern winds cool down the "
     "already cool day. This road leads north and south. North two shops "
     "can be seen, each with a sign outside it.");
   set_night_long("The night winds chill your bones, blowing from both "
     "the east and from the south. The road leads north deeper into town "
     "and south further into darkness. Two shadowy buildings can be seen "
     "just north.");
   set_items(([
     ({ "shops", "buildings" }) : "They lie directly north of here.",
     "winds" : "Winds blow constantly from the south and east.",
     "signs" : "They describe what type of shop each is."
   ]));
   set_exits(([ "north" : ROOMS"stown2",
                "south" : ROOMS"stown4" ]));
}

void reset() {
 ::reset();
   if (!present("citizen")) {
     make(MOB"citizen");
     make(MOB"citizen");
   }
   if (!present("citizen 3"))
     make(MOB"citizen");
}
