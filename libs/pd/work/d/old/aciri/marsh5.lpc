#include <aciri.h>
#include <std.h>
inherit ROOM;

string *query_tracks();

void create() {
 ::create();
   set_short("%^BOLD%^%^BLACK%^Nearing the center of a marsh");
   set_day_long("%^BOLD%^%^BLACK%^"
     "Most of the ground is mud here, absorbing footprints and any other would-"
     "be ditches. Underbrush is scattered around on fairly softer spots in the "
     "marsh. Ivy covers much of several of the trees and ground here. Any twigs "
     "or branches that fall onto the ground sink into the watery mud.");
   set_night_long("%^BOLD%^%^BLACK%^"
     "Most of the ground here is very watery mud. During the night, the mud "
     "gives the impression of standing on water. Ivy has grown over almost "
     "everything in this part of the marsh. Trees and underbrush alike are "
     "mostly completely enveloped in ivy.");
   set_items(([
     "ivy"    : "Ivy grows all over the place right here.",
     "ground" : "Very soft and watery, the ground is almost muddy water.",
     "mud"    : "Just thick enough to be solid, the mud covers the ground.",
     "trees"  : "Many different types of trees grow in the soft marsh ground."
   ]));
   set_properties((["light" : 2, "night light" : 1, "swamp" : 1 ]));
   set_exits(([
      "south" : ROOMS"marsh4",
      "north" : ROOMS"marsh6",
   ]));
}

string *query_tracks() { return ({ }); }
