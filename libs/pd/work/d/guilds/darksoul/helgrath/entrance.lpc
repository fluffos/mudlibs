#include <std.h>
#include <daemons.h>
#include <guild.h>
inherit ROOM;

void create() {
    ::create();
    set_properties((["light"       : 2, 
	"indoors"     : 1, 
	"no steal"    : 1,
	"no teleport" : 1, 
	"no bump"     : 1,]));
    set_name("Entrance to the Darksouls guild");
    set_long("This is the secret entrance to the depths of the "
      "Darksouls guild.  From here down the stairs many come to "
      "participate in its rituals and become the best of Primal "
      "Darkness-II.");
    set_exits(([
	"out" : "/d/helgrath/rooms/mountaint_s05"
      ]));
}
