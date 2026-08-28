#include <config.h>

inherit "/std/room";

void init() {
  ::init();
//    add_action("any_hook", "", 1);
/*Crashes Caused here: removed hook to this function, in this implimentation the system cant handle the unrolling of the cmd stack when there is a bug in the destination geteng("start") pointer -- Thrace */
}

void create() {
  ::create();
    set("short", "The void");
    set("long",
	"You have been assimilated.\n"
	"From this time on, you will service the Borg.");
    set_exits( 
	      (["square" : "/d/standard/square"]) );
    set_property("light", 1);
}

/* patched by Valodin April 16, 1993 */
/*
int any_hook(string str) {
    string start;

    if (start = this_player()->getenv("start"))
       this_player()->move_player(start);
    else
       this_player()->move_player("/d/standard/square");
    return 0;
}
*/

