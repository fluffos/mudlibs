//Made using Room generator by Nightshade
//Created by Whit for Primal Darkness
#include <std.h>
#include <keep.h>
inherit ROOM;
void create() {
    ::create();
    set_short("Path to the Keep");
    set_properties( (["light" : 3, "night light" : 2]) );
    set_long("The walls of the keep surround the entrance from the bridge.  The only passage into the keep is by the bridge making it easy to defend from intruders.  There seems to be alot of business taking place in the keep nowadays.");
    set_exits( (["north" : GARDEN+"55"
	,"south" : ROOMS+"e7"
      ]) );
    set_items( ([ "keep" : "The keeps black stone seems to suck in what light there is."
	,"bridge" : "The bridge crosses the ravine."
	,"ravine" : "The expansion of the ravine surrounds the keep, making it hard to sneak into it."
      ]) );
    set_pre_exit_functions( ({"north"}), ({"go_north"}) );
}
int go_north() {
    write("As you walk past the massive walls guarding the keep, a "
      "strange magical force washes over you.\n");
    return 1;
}
