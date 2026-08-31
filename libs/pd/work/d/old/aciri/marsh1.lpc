#include <aciri.h>
#include <std.h>
inherit ROOM;

string *query_tracks();

void create() {
 ::create();
   set_short("%^BOLD%^%^BLACK%^Edge of a marsh");
   set_day_long("%^BOLD%^%^BLACK%^"
     "This is the very edge of a marsh. The mud and water boil and sputter "
     "from the intense heat of the sand just south of here. The air at the "
     "ege of the marsh is humid from the boiling of the water. Sunlight streams "
     "into this part of the marsh from the south.");
   set_night_long("%^BOLD%^%^BLACK%^"
     "Moonlight lights up this part of the marsh very well. The very edge of the "
     "marsh is humid and hot from because the hot black sands to the south cause "
     "the water to boil. Mud spits up into the air from the boiling water.");
   set_items(([
     "water" : "The water bubbles and boils from the heat of the sand.",
     "mud"   : "Mud quakes and trembles as the water starts to boil.",
     "sand"  : "There is hardly any sand in the marsh.",
     "air"   : "Humid air presses against your skin, smothering you."
   ]));
   set_properties((["light" : 2, "night light" : 2, "swamp" : 1 ]));
   set_exits(([
      "south" : ROOMS"beach8",
      "north" : ROOMS"marsh2",
   ]));
}

string *query_tracks() { return ({ }); }
