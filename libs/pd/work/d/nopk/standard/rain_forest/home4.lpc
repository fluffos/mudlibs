#include <std.h>
#include <rain.h>
inherit ROOM;

create() {
    ::create();
    set_properties( ([ "light" : 3, "night light" : 1, "town" :1 ]) );
    set_short("fourth house on the block");
    set_long("A small hut.  There are other "
      "houses located here. Off to the southeast, "
      "the town gates are guarding the palace.");
    set_exits((["north" : ROOMS"home1",
	"east" : ROOMS"home5",
	"west" : ROOMS"home6",
	"enter" : ROOMS"house4"]));
    set_items((["gates" : "These are tall gates which stand wide "
	"open"]));
}
