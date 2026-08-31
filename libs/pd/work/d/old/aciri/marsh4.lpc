#include <aciri.h>
#include <std.h>
inherit ROOM;

string *query_tracks();

void create() {
 ::create();
   set_short("%^BOLD%^%^BLACK%^Barley in sight of the edge of the marsh");
   set_day_long("%^BOLD%^%^BLACK%^"
     "Mud and soft dirt make up the ground of the marsh. Saplings and larger trees "
     "sprout forth from the ground. Pools of collected water form in some of the "
     "lower dips in the marsh. Black barked trees grow in the marsh mud. The "
     "trees' many leaves prevent much of the daylight from entering the dark "
     "confines of the marsh.");
   set_night_long("%^BOLD%^%^BLACK%^"
     "Very little light penetrates the dark confines of the night marsh. Trees, "
     "both small and large, sprout in the mud and dirt. Pools of murky grey "
     "form in the small ditches in the marsh ground. The light from the edge of "
     "marsh can barely be seen.");
   set_items(([
     "edge"   : "Barely can the edge of the marsh be made out from here.",
     "ground" : "The marsh ground is merely a mix of mud and soft dirt.",
     "pools"  : "Small pools form in the ditches in the ground.",
     "mud"    : "A very watery mud is what most of the ground consists of.",
     "trees"  : "Trees of all sized grow here, most with vines around them."
   ]));
   set_properties((["light" : 2, "night light" : 1, "swamp" : 1 ]));
   set_exits(([
      "south" : ROOMS"marsh3",
      "north" : ROOMS"marsh5",
   ]));
}

string *query_tracks() { return ({ }); }
