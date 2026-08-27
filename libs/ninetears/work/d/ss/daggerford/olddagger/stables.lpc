#include "path.h"
inherit "/std/room";
 
#define NUM 2
 
setup() {
 set_light(60);
 set_short("Stables");
 set_long("You are in the stables. You can leave horses here.\n");

 add_exit("south", ROOM+"hill2", "gate");
 set_zone("stables");
}

void reset() {
	call_out("ca_reset", 0);
}

void ca_reset() 
{
 object shovel;

 if (!present("shovel", this_object())) 
 {
   shovel = clone_object("/std/object");
   shovel->set_name("shovel");
   shovel->set_main_plural("shovels");
   shovel->set_long("A small relatively dirty shovel.  It is used to muck "+
    "out the stables.\n");
   shovel->set_weight(60);
   shovel->set_value(150);
   shovel->add_property("digger", 1);
   shovel->move(this_object());
 }
}
