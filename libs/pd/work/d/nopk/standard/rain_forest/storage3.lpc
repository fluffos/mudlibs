#include <rain.h>
#include <std.h>
inherit ROOM;

void create() {
   ::create();
   set_short("The general store storage room");
   set_long("All items for sale in the general store go here.");
   set_exits((["south" : ROOMS"shop3"]) );
   new("/d/nopk/tirun/obj/misc/tirun_seal")->move(this_object());
   new("/d/nopk/tirun/obj/misc/tirun_seal")->move(this_object());
}

