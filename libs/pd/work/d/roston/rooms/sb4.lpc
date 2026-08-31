#include <std.h>
#include <roston.h>
inherit ROOM;
int searched;
void create() {
    ::create();
    set_name("west of roston square");
    set_properties((["light":2,"nightlight":3]));
    set_short("secret building");   
    set_long("");
    set_items((["snow"   : "A very deep white snow",
	"dirt"  : "A light brown mixture"])); 
    set_exits((["out" : ROOMS "incinerator", "northeast" : ROOMS 
	"sb5", "southeast" : ROOMS "sb6"]));
    new(MOB"couch")->move(this_object());
    searched = 0;
}

void init() {
    ::init();
    add_action("search_couch", "search");
}

int search_couch(string str) {
    if(searched)
	return 0;
    if(str != "couch")
	return 0;
    message("my_action", "You find a small ring in the raised cushion.", this_player());
    message("other_action", this_player()->query_cap_name()+" found a small ring in the raised cushion.", this_object(), ({ this_player() }));
    new(ARM "ring")->move(this_object());
    searched = 1;
    return 1;
}
