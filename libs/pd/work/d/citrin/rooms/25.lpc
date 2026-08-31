//  Created by Whit
#include <std.h>
#include <citrin.h>
inherit ROOM;
int closed;

void set_closed(int i) { closed = i; }

void create() {
    ::create();
    set_name("near a lake");
    set_short("near a lake");
    set_long("The air is dry and cool.  The ground is soft, almost muddy.  "
      "Grey puffs of smoke lightly float into the air originating somewhere "
      "to the south.  The path is well defined and is very clean.  A large "
      "set of gates lay right ahead to the south making the entrance to some "
      "sort of primative civalization.\n");
    set_exits(([
	"northwest":ROOMS"24",
	"south":ROOMS"26",
      ]));
    set_items((["ground":"The ground is soft, almost muddy.",
	"smoke":"Its grey smoke...  Duh!",
      ]));
    set_properties((["light":1,"night light":1,"forest":1,]));
}

void reset() {
    ::reset();
    if(!present("gates"))
	new(OBJ"gates")->move(this_object());
    if(random(2)) closed = 0;
}

void init() {
    ::init();
    add_action("peer", "peer");
}

int peer(string str) {
    if(str != "south") return 0;
    if(!closed) return 0;
    write("The gates block your view.\n");
    return 1;
}
