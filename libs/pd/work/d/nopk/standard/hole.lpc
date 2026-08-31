#include <std.h>
#include <sindarii.h>

inherit ROOM;

void create() {
    set_property("light", -1);
    set_short("A hole in the ground");
    set_long(
	"You are in a deep hole in the ground. The light is very poor "
	"down here.");
    set_no_clean(1);
    add_money("gold", 50 + random(20));
    add_money("platinum", random(12));
    add_money("copper", 120 + random(20));
    set_exits(([ ]));
}

void fixing_a_hole() {
   remove_exit("up");
   set_property("light", -1);
}

void digging() {
   add_exit(ROOMS "wesroad2", "up");
   set_property("light", 0);
}
