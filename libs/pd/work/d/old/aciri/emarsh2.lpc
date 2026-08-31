#include <aciri.h>
#include <std.h>
inherit ROOM;

string *query_tracks();

void create() {
 ::create();
   set_short("%^BOLD%^%^BLACK%^The edge of a marsh");
   set_day_long("%^BOLD%^%^BLACK%^"
     "Weeds and grass grow all over the muddy ground. The mud on the floor of "
     "the marsh is wet and has puddles of water in it. Ferns grow around many of "
     "the trees providing the thin canopy of leaves above the marsh. Almost "
     "no daylight makes it through deeper into the marsh, but here, at the edge, "
     "is fairly bright.");
   set_night_long("%^BOLD%^%^BLACK%^"
     "Moonlight shines through large gaps in the thin canopy of trees above. "
     "Ferns and other underbrush seems to have a faint glow to them from the "
     "angle of the moonlight. This part of the marsh is pretty well luminated at "
     "night.");
   set_items(([
     "ferns" : "They grow in clusters around the trees along witht the moss.",
     "moss"  : "Moss grows on the trees.",
     "trees" : "Several trees growing out of the mud provide a thin canopy.",
     "underbrush":"The underbrush grows everywhere in the marsh."
   ]));
   set_properties((["light" : 2, "night light" : 0, "swamp" : 1 ]));
   set_exits(([
      "south" : ROOMS"ebeach4"
   ]));
}

string *query_tracks() { return ({ }); }
