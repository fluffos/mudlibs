#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Northwestern turret");
   set_day_long("This is one of the corners of the temple's northwestern "
     "turret. The turret barley reaches above the temple. This may be the "
     "security of the temple. To the east is an exit out of this turret, "
     "back into the main temple.");
   set_night_long("The dark night turns the normally white turret dark "
     "grey. East is a passage into the main temple and south is another "
     "part of the turret. A hole in the ceiling insures that people are "
     "able to get to the top of the turrets without all too much trouble.");
   set_items(([
     "hole" : "How the bloody hell does someone squeeze through that??",
     "exit" : "The exit is past the eastern doorway."
   ]));
   set_properties(([ "light" : 2, "night light" : 1, "indoors" : 1 ]));
   set_exits(([
     "up"        : ROOMS"l2nw3",
     "north"     : ROOMS"l1nw1",
     "east"      : ROOMS"l1nw4",
   ]));
}

void reset() {
 ::reset();
   if (!present("master"))
     make(MOB"t3");
}
