//  Created by Whit
#include <std.h>
#include <citrin.h>

inherit ROOM;

int search;

void create() {
    ::create();
    set_name("Citrin Forest");
    set_short("entrance to a shack");
    set_long("The entrance to a small, rundown shack is here.  The roof of "
      "the shack has many holes and the walls of the shack seem to "
      "be rotten and about to collapse.");
    set_items(([
	({"house", "wall", "walls","roof"}):"There are many holes in the roof and "
	"the walls are about to collapse.  There is a small pipe running off the roof "
	"that empties out onto the ground.",
	"pipe":"It runs from the roof.",
      ]));
    set_exits(([
	"north":ROOMS"10",
	"enter":ROOMS"shack1",
      ]));
    set_properties((["light":1,"night light":1,"forest":1,]));
}

void init() {
    ::init();
    add_action("search", "search");
}

int search(string str) {
    if(str != "pipe") return 0;
    if(search) return 0;
    if(!"/d/citrin/rooms/shack1"->query_tmp()) return 0;
    write("You find a key in the pipe.\n");
    say(this_player()->query_cap_name()+" finds a key in the pipe.\n");
    new("/d/citrin/obj/quest/key")->move(this_player());
    search=1;
    return 1;
}

