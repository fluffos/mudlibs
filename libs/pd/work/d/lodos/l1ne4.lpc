#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("One of the northeastern turret's corners");
   set_long("This is one of the corners of the northeastern turret. "
     "The turret is taller than the main temple, though not by all too "
     "much. A platform roof is accessible through a hole just barely wide "
     "enough to crawl through in the ceiling.");
//   set_night_long("   You want to do it, make my day. No more turret
//                         for me
   set_items(([
     "hole" : "Not too big, not too small, juuuust right.",
     "turret":"Just one of four.. Collect them all!",
     "roof" : "Sounds like fun, 'eh? I see waterballoons in your future."
   ]));
   set_properties(([ "light" : 2, "night light" : 1, "indoors" : 1 ]));
   set_exits(([
     "up"    : ROOMS"l2ne4",
     "north" : ROOMS"l1ne2",
     "west"  : ROOMS"l1ne3"
   ]));
}

void reset() {
 ::reset();
   if (!present("apprentice"))
     make(MOB"t4");
}
