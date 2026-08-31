#include <std.h>
inherit ROOM;
#include <sindarii.h>
void create() {
  ::create();
    set("short", "Elite Supply Storage Room");
    set("long", "This room holds all the elite crap.");
    set_exits( 
	      (["south" : ROOMS"elite"]) );
   new(OBJ"vial2")->move(this_object());
}

