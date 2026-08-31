#include <rain.h>
#include <std.h>
inherit ROOM;

void create() {
   ::create();
   set("short", "The General store storage room");
   set("long", "All items for sale in the general store go here.");
   set_exits((["south" : ROOMS"shop1"]) );
   new(OBJ"sword2")->move(this_object());
}
