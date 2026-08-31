#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Connection of southwestern turret and temple");
   set_day_long("This is the northeastern corner of the turret. This, the "
     "souwestern turret, has a doorway connecting the turret to the main "
     "temple. The corner of the southwestern turret has a large, gaping "
     "hole in the ceiling leading onto the top platform of the turret.");
   set_night_long("A large, gaping hole gives a view of the star speckled "
     "night sky. The walls are white onyx and the floor white tile. A dark "
     "passage connects the temple to the northeast to this turret. Two "
     "other doorways go south and west. This is one of the corners of the "
     "southeastern turret.");
   set_items(([
     "sky" : "The sky can be seen through the large hole in the ceiling.",
     "hole": "Bigger than any of the other holes in the rest of the "
             "turrets, it is pretty big.",
     "corner":"You are here. <----"
   ]));
   set_properties(([ "light" : 2, "night light" : 1, "indoors" : 1 ]));
   set_exits(([
     "up"        : ROOMS"l2sw2",
     "west"      : ROOMS"l1sw1",
     "northeast" : ROOMS"l1m7",
     "south"     : ROOMS"l1sw4",
   ]));
}

void reset() {
 ::reset();
   if (!present("sage"))
     make(MOB"t2");
}
