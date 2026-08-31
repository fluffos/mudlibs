#include <std.h>
#include <zexor.h>
inherit ROOM;

void create() {
   ::create();
   set_short("In a forest");
   set_long("The Zexorion forest. There is one tall "
       "tree blocking the path to the south. There are bushes, "
       "leaves and grass strewn all over the forest floor.");
   set_items((["tree" : "A giant tree blocking the road to the south",
       "trees" : "Many different trees",
       ({"bushes", "leaves", "grass"}) : "Just foilage on the ground"]));
   set_listen("default", "You hear roars all around you");
   set_exits((["north" : ROOMS"path2",
       "southwest" : ROOMS"path4"]));
}

void reset() {
   ::reset();
   if(!present("bear")) {
     new(MOB"bear")->move(this_object());
     new(MOB"bear")->move(this_object());
     new(MOB"bear")->move(this_object());
}
}
