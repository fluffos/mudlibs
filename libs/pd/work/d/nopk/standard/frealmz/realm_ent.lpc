// - Inferno -
// This room is used as the enterance to the freezer
// and a 'secret' realm beyond the mortal world

#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("within crimson mists");
   set_long("It is increadibly hard to tell where you "
            "are. A thick crimson mist envelopes your "
            "entire body, limiting sight to only a few "
            "short feet. A swirling mist looms to the "
            "north. You notice a silver rift to the south "
            "of you.");
   set_exits(([
      "south" : "/d/standard/freezer",
      "north" : "/d/standard/frealmz/mist1"
   ]));
   set_items(([
      "rift" : "A silver rift leads to the realm of carnage.",
      "south" : "To the south is a strange silver rift."
   ]));
}