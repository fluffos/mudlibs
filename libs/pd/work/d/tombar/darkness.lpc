// Coded by Whit
#include <std.h>
#include <tombar.h>
inherit ROOM;

string query_long() {
    int i;
    object *o;
    o=all_inventory(this_object());
    for(i=0; i < sizeof(o); i++) {
        if(present("orb_quest_tombar", o[i]) && present("orb_quest_tombar", o[i])->query_color() == "blue") return "The light from "+
	    o[i]->query_cap_name()+" allows you to see.\n"+::query_long();
    }
    return "It is too dark to see anything.";
}

