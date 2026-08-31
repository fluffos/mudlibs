#include <lodos.h>
#include <std.h>
inherit VAULT;
void look_door();

void create() {
 ::create();
   set_short("The foot of a tower");
   set_properties((["light" : 2, "night light" : 1, "indoors" : 1]));
   set_long("You are standing at the foot of a tower. A door leads "
      "east, back into the street. A second tower, right across the "
      "dirt path street can be seen through the small window on the "
      "eastern wall.");
   set_exits(([ "up" : ROOMS"wtower2",
                "east" : ROOMS"ntown7"]));
   set_items(([ "door" : (: look_door() :) ]));
   set_door("door", ROOMS"ntown7", "east", "");
}

void look_door() {
    if(query_open("door")) write("It is open.");
    else write("It has been closed.");
}
