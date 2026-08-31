#include <aciri.h>
#include <std.h>
inherit ROOM;

string *query_tracks();

void create() {
 ::create();
   set_short("%^BOLD%^%^BLACK%^Center of a marsh");
   set_day_long("%^BOLD%^%^BLACK%^"
     "This is just about the center of the darkened marsh. Sunlight is barely "
     "able to enter this part of the marsh. Most everything that touches the "
     "ground sinks into the thick muddy dirt. Ivy, ferns and saplings grow in "
     "the soft dirt.");
   set_night_long("%^BOLD%^%^BLACK%^"
     "Ivy and ferns grow all over the soft marshy ground. This ground is fairly "
     "firm, but still mushy enough for just about everything to sink into it. "
     "This part of the marsh is extremely dark, possibly the center of the "
     "marsh.");
   set_items(([
     "marsh"    : "This may be the center of the marsh.",
     "ground"   : "The ground is simply a firm enough mud to carefully walk on.",
     "ivy"      : "Ivy grows on the saplings.",
     "ferns"    : "Ferns grow all over the marsh floor.",
     "saplings" : "Only saplings grow here, because anything larger would either "
                  "sink into the mud or fall over."
   ]));
   set_properties((["light" : 1, "night light" : 0, "swamp" : 1 ]));
   set_exits(([
      "south" : ROOMS"marsh5",
      "north" : ROOMS"marsh7",
   ]));
}

string *query_tracks() { return ({ }); }
