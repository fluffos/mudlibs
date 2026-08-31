#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
   set_property("light", 2);
   set_property("night light", 1);
   set_property("no castle", 1);
   set_short("on a forest trail");
   set_long("Moss covers the ground and a canopy of leaves lets in "
         "a comfortable amount of life, lending a peaceful feel to "
         "the forest.");
   set_items(([
          "trees" : "They are growing increadibly close together."]));
   set_exits((["southwest" : ROOMS"south_orcs/forest1"]));
}

void reset() {
 ::reset();
  if(!present("deer"))
    new(MOB"deer")->move(this_object());
}
