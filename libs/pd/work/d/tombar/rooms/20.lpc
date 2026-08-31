#include <std.h>
#include <tombar.h>
inherit ROOM;
void create() {
    ::create();
    set_name("Underwater temple");
    set_short("Underwater temple");
    set_long("The long hallways seem to last forever.  Ever sound echos "
      "throughout the long corridors of the temple.  Mostly everyhing in the "
      "hallway is wet from the leaky ceiling.");
    set_listen("default", "Sounds echo throughout the hallway.");
    set_items(([
	"ceiling" : "The ceiling is wet.",
      ]));
    set_exits(([
	"west" : ROOMS"19",
	"southeast" : ROOMS"22",
      ]));
}
