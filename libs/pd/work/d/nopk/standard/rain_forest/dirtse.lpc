#include <rain.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
set_properties( ([ "light" : 3, "night light" : 1, "forest" :1 ]) );
   set_long("This path in the forest is surround on all sides by trees."
            " There are various fruits up in the trees. Here just like"
            " the rest of the forest there are vines all over all the"
            " trees. The path continue's further southeast.");
   set_short("Heavy Forest");
   set_items((["fruits" : "There are many fruits all different colors, sizes, and shapes",
               "trees" : "There are trees everywhere and all around you."]));
   set_exits((["northwest" : ROOMS"dirt3",
               "southeast" : ROOMS"amatrail"]));
}           

void reset() {
   ::reset();
    if(!present("warrior"))
    new(MOB"amazon")->move(this_object());
 }
