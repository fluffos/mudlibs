#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("A single-windowed room of the southeastern turret");
   set_day_long("Bright daylight flows into this corner of the southeastern "
     "turret, lighting up the entire room, from a single window in the "
     "western wall and a hole in the ceiling leading to the top level of "
     "the turret. The turrets are just barely taller than the main "
     "temple.");
   set_night_long("This corner of the southeastern turret is fairly well "
     "illuminated by a single window in the western wall and a hole in the "
     "ceiling. Beams of moonlight stream stream into the room and shine "
     "onto the ground. This turret is just barely higher than the rest of "
     "the temple.");
   set_items(([
     "window" : "But a single window in the western wall. You can see "
                "across a grassy hill to another turret.",
     "hole"   : "In the ceiling. It's a way of going up.",
     "light"  : "A beam of light shines through the window and rests on "
                "the ground."
   ]));
   set_properties(([ "light" : 2, "night light" : 1, "indoors" : 1 ]));
   set_exits(([
     "up"    : ROOMS"l2se3",
     "north" : ROOMS"l1se1",
     "east"  : ROOMS"l1se4",
   ]));
}

void reset() {
 ::reset();
   if (!present("master"))
     make(MOB"t3");
}
