#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("%^BOLD%^%^BLACK%^Western limits of a marsh");
   set_day_long("%^BOLD%^%^BLACK%^"
     "The marsh underbrush grows under every tree, behind every bush, and "
     "pretty much everywhere one looks. Trees grow scattered out through out "
     "the marsh. The ground is wet and muddy.");
   set_night_long("%^BOLD%^%^BLACK%^"
     "Thick mud is what the ground consists of. Puddles of water rest on the "
     "ground. The moonlight lets in a surprizing ammount of light to this part "
     "of the marsh. The night air makes the cool marsh seem very cold. Trees and "
     "underbrush grow all over the place.");
   set_items(([
     "underbrush" : "Ferns, cattails, grass, all kinds of stuff.",
     "ground"     : "The ground consists mostly of mud.",
     "mud"        : "The thick mud is all over the place.",
     "trees"      : "Trees grow scattered about, sparsely.",
     "puddles"    : "Puddles rest near the bases of the trees."
   ]));
   set_properties((["light" : 2, "night light" : 2, "swamp" : 1 ]));
   set_exits(([
      "south" : ROOMS"wmarsh2"
   ]));
}

string *query_tracks() { return ({ }); }
