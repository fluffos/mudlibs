#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("A corner of the northeastern turret");
   set_day_long("This is a corner of the northeastern turret. There are "
     "four turrets surrounding the temple. This is the northeastern "
     "corner of the turret. A ladder and opening in the ceiling allow "
     "journey upwards to the higher part of the turret.");
   set_night_long("Night shadows coat the northeastern turret of the "
     "temple. This is one of four turrets or lookouts. A hole in the "
     "ceiling is accessable by means of a ladder. The ladder looks old, "
     "but strong enough to support quite a bit of weight.");
   set_items(([
     "ladder" : "An old wooden ladder.",
     "hole"   : "One big hole in the ceiling. A giant could fit in this.",
     "turret" : "One of four turrets.",
   ]));
   set_properties(([ "light" : 2, "night light" : 1, "indoors" : 1 ]));
   set_exits(([
     "up"    : ROOMS"l2ne1",
     "east"  : ROOMS"l1ne2",
     "south" : ROOMS"l1ne3",
   ]));
}

void reset() {
 ::reset();
   if (!present("magician"))
     make(MOB"t1");
}
