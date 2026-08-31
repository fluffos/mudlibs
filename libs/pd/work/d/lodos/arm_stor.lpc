#include <std.h>
#include <lodos.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Lodosian armour storage room");
   set_long("Syphon stores all his crap back here.");
   set_exits(([ "south" : ROOMS"armoury" ]));
   new(ARM"robe")->move(this_object());
   set_property("light", 2);
   new(ARM"helm")->move(this_object());
}
