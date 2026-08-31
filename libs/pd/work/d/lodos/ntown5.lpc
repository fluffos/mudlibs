#include <lodos.h>
#include <std.h>
inherit VAULT;
void look_door();

void create() {
 ::create();
   set_short("In the shadow of a tower");
   set_long("You stand here, in the shadow of a tower that "
            "stands tall to the east. The small, wooden door "
            "has withstood all kinds of strong magic, but is "
            "thinner than the door on a peasant's hut. The "
            "dirt path leads north and south.");
   set_properties((["town" : 1, "outdoors" : 1, "light" : 2 ]));
   set_exits(([ "south" : ROOMS"town4",
                "north" : ROOMS"ntown6",
                "east" : ROOMS"tower1"]));
   set_items(([ "door" : (: look_door() :) ]));
   set_door("door", ROOMS"tower1", "east", "");
}

void look_door() {
  if(query_open("door")) message("my_action", "It is open.", this_player());
    else message("my_action", "It has been closed.", this_player());
}
