#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
   set_property("light", 2);
   set_property("night light", 2);
   set_property("no castle", 0);
   set_short("the slave's quarters");
   set_long("The slave quarters is an small cheap shack which has "
         "been built in the orc fortress, probably by the slaves "
         "themselves. The room is completely empty, the slaves sleep "
         "on the floor and own nothing.");
   set_exits((["out" : ROOMS"south_orcs/path3"]));
}

void reset() {
 ::reset();
  if(!present("slave")) {
    new(MOB"slave")->move(this_object());
    new(MOB"slave")->move(this_object());
    new(MOB"slave")->move(this_object());
  }
}
