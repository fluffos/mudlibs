#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Southeastern turret of the temple");
   set_day_long("This room is one of the corners of the southeastern "
     "turret. A doorway connects this room to the temple northwest of "
     "here. The stunning appearance of the stained glass windows from the "
     "main temple has been replaced with the silent splendor of the "
     "otherwise undecorated turret.");
   set_night_long("The walls are empty and the ground spotless. The silent "
     "and majestic silence of the turret more than makes up for it's lack "
     "of decor. Dim light and a white tower gives an almost romantic air to "
     "the temple's turrets. The appearance of the turret is greatly "
     "majestic, even though the night darkness makes it hard to see all "
     "of the room.");
   set_items(([
     "walls" : "Undecorated white onyx makes up the turret's walls."
   ]));
   set_properties(([ "light" : 2, "night light" : 1, "indoors" : 1 ]));
   set_exits(([
     "up"        : ROOMS"l2se1",
     "northwest" : ROOMS"l1m9",
     "east"      : ROOMS"l1se2",
     "south"     : ROOMS"l1se3",
   ]));
}

void reset() {
 ::reset();
   if (!present("magician"))
     make(MOB"t1");
}
