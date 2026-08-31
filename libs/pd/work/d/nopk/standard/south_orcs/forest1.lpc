#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
   set_property("light", 2);
   set_property("night light", 1);
   set_property("no castle", 1);
   set_short("a small clearing");
   set_long("You are on a trail leading through the forest around "
          "the orc fortress. The trees grow very closely together "
          "and prevent you from going in almost any direction other "
          "than where the trail has been cut out of the thick "
          "foliage. The trail leads to the northeast.");
   set_items(([
          "trees" : "They are growing increadibly close together."]));
   set_exits((["northeast" : ROOMS"south_orcs/forest2",
             "west" : ROOMS"south_orcs/path3"]));
}
