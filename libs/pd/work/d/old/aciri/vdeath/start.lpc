#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("%^YELLOW%^?");
   set_long("%^BOLD%^%^BLACK%^"
	"You stand knee-deep in a lake of black fire. A strange dark "
	"green smoke rises off the lake, like a poison mist. The sky is "
	"painted in jagged streaks of red and yellow. The infernal lake "
	"spreads as far as the eye can see. A sharp rock juts out of "
        "the black fire just to the north, like a sort of island.");
   set_items(([
	"rock" : "An island amid the lake of fire.",
	({ "lake", "fire" }) : "Unnatural black flame lake.",
	"smoke" : "Like a poison mist.",
   ]));
   set_properties((["light" : 2, "night light" : 1, "no magic" : 1,
			"no teleport" : 1 ]));
   set_exits(([
      "east" : ROOMS"vdeath/e1",
      "south": ROOMS"vdeath/s1",
      "west" : ROOMS"vdeath/w1",
      "north": ROOMS"vdeath/n1"
   ]));
}

string *query_tracks() { return ({ }); }
