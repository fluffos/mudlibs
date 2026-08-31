#include <lodos.h>
#include <std.h>
inherit VAULT;

void create() {
 ::create();
   set_properties((["town" : 1, "outdoors" : 1, "light" : 2 ]));
   set_short("On a dirt path before a large tower");
   set_long("The dirt path heading north ends here, leading only to "
      "the south. Directly to the north is a huge tower, reaching up "
      "past the clouds. A wind whirls around the tower.");
   set_items(([
      "clouds" : "The clouds provide a ceiling to the world.",
      "path" : "The dirt path has come to an end here.",
      "wind" : "The wind is concentrated around the tower.",
      "tower" : "This tower reaches high up, even past the clouds."
   ]));
   set_exits(([ "south" : ROOMS"ntown7",
                "west"  : ROOMS"wgarden1",
               "east"  : ROOMS"egarden1",
                "enter" : ROOMS"ntower1"]));
   set_door("door", ROOMS"ntower1", "enter", "");
}
