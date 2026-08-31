#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties((["town" : 1, "forest" : 1, "light" : 2 ]));
   set_short("West entrance to a beautiful garden");
   set_day_long("This is the western entrance to a beautiful garden. "
     "The shrubs, foliage, and flowers are magnificent within the "
     "garden. Northeast of this entrance is the tall northern tower "
     "of Lodos. Stepping stones have been layed out leading north, "
     "into the garden.");
   set_night_long("This is the western entrance to the lusterous "
     "garden surrounding the northern tower in Lodos. In the darkened "
     "light, the outlines of bushes and other various foliage can be "
     "seen against the dark-bluish tinge of the tower northeast of "
     "here. Something has been lined up, leading north, but what it "
     "is cannot be seen in the night.");
   set_items(([
      "stones" : "They are made to look like small cuts out of a tree.",
      "tower"  : "The tower casts a dark shadow across this entrance.",
      "foliage": "Many trees, shrubs, hedges, and other plants are "
                 "all over the place.",
   ]));
   set_exits(([ "east" : ROOMS"ntown8",
                "north": ROOMS"wgarden2"
   ]));
}

void reset() {
 ::reset();
   if(!present("squirrel"))
     make(MOB"squirrel");
}
