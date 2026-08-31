#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
  ::create();                       

set_name("armory storage");
set_properties((["light":2 , "night light":3]));
set_short("storage room");
set_long("This is the storage room for the armory of roston");

set_exits( ([ "east" : ROOMS"roston8" ]));
 
   new("/d/nopk/tirun/obj/misc/tirun_seal_new")->move(this_object());
   new("/d/nopk/tirun/obj/misc/tirun_seal_new")->move(this_object());
   new("/d/nopk/tirun/obj/misc/tirun_seal_new")->move(this_object());
}   
