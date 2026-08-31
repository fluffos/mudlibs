#include <std.h>
#include <lodos.h>
inherit ROOM;

void create() {
  ::create();
    set("short", "Lodos Weaponry's Storage Room");
    set("long", "Storage room for the Lodos weaponry.");
    set_exits( 
	      (["south" : ROOMS"weaponry"]) );
    new(WEA"hammer")->move(this_object());
}

