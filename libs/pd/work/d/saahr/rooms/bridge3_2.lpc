
#include <std.h>
#include <saahr.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 1, "indoors" : 0, "plain" : 1]));
  set_short("a bridge over the river");
  set_long("The bridge is long and quite solid. Wide enough for two full-sized people "
    "to cross at once, the planks across the bottom have almost no visible cracks. "
    "The ropes across the sides and bottom are as thick as a man's arm. The bridge "
    "moves and creaks very slightly as it is crossed. Off to the west, a plain can "
    "be seen, and the bridge continues to the east.");
  set_items(([
    "bridge" : "A sturdy bridge across the river.",
    "planks" : "Large, solid lengths of wood that provide good footing.",
    "rope" : "The ropes hold the bridge together and form handholds on either side.",
    "east" : "The bridge extends to the east.",
    ({"plain","west"}) : "Sunburnt plains fill the western side of the river."
  ]));
  set_listen("default","The sound of the river mixes with the creaking of the bridge.");
  set_exits(([
    "west" : VPROOMS "p2_2",
    "east" : VPROOMS "bridge4_2"
  ]));
}
