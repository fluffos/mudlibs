#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Top corner of the northeastern turret."); 
   set_day_long("From this corner atop the northeastern turret, one could "
     "see south to the southeastern turret and east over the eastern part "
     "of the temple. The turret isn't all too much higher than the roof of "
     "the main temple. Stones have been laid across the outside edge of "
     "this turret to form a small ledge.");
   set_night_long("The night sky is easily viewable from this corner of "
     "the uncovered turret. Though it may not be quite the most pleasant "
     "place to be during the rain, this place makes for a great view of "
     "the sky on calm nights. Stones and rocks have been laid across the "
     "outside edge of this turret to form a small ledge. Another turret "
     "can be seen south of here.");
   set_items(([
     "turret" : "It can be seen pretty clearly to the south.",
     "stones" : "They line the edge of the turret.",
     "temple" : "It is partially visible from here."
   ]));
   set_properties(([ "light" : 2, "night light" : 1, "outdoors" : 1 ]));
   set_exits(([
     "down"      : ROOMS"l1ne4",
     "north"     : ROOMS"l2ne2",
     "west"      : ROOMS"l2ne3"
   ]));
}

void reset() {
 ::reset();
   if (!present("avatar"))
     make(MOB"2t4");
}
