#include <std.h>
#include <lodos.h>                                         
inherit ROOM;

void create() {
 ::create();
   set_short("Southeastern corner of the turret of heart");
   set_day_long("The furthest point on the ground floor away from the main "
     "temple pointing southeast is here. This is the darkest room of the "
     "turret of heart. The walls are a murky crimson/black and a greyish "
     "midnight blue. The tiled floor is black. The very appearance of this "
     "room is silencing and breath taking, giving off an almost unholy "
     "feeling.");
   set_night_long("This room at night is awe inspiring, breath taking, and "
     "over all silencing. The black tiles and walls give a quite horrifying "
     "feeling. This room looks almost unholy, and definatly fiercly "
     "guarded. By far, this corner of the turret of heart is the hardest "
     "place to keep calm.");
   set_items(([
     "room" : "It almost looks like a chamber or prison.",
     "floor": "A dark, light-absorbing black tiled floor.",
     "walls": "Red and blue, fierce and demanding."
   ]));
   set_properties(([ "light" : 1, "night light" : 0, "indoors" : 1 ]));
   set_exits(([
     "up"    : ROOMS"l2sw3",
     "north" : ROOMS"l1sw1",
     "east"  : ROOMS"l1sw4",
   ]));
}

void reset() {
 ::reset();
   if (!present("master"))
     make(MOB"t3");
}
