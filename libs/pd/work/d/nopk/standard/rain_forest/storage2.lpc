#include <rain.h>
#include <std.h>
inherit ROOM;

void create() {
   ::create();
   set_short("The Armour store storage room");
   set_long("All items for sale in the armour store go here.");
   set_exits((["south" : ROOMS"shop2"]) );
   new(OBJ"arm")->move(this_object());
}

