//  Portal Inherit
//  Whit

#include <std.h>
inherit ROOM;

string enter, location;
int x;

void set_location(string str) { location = str; }
string query_location() { return location; }

void set_enter(string str) { enter = str; }
string query_enter(string str) { return enter; }


void init() {
    ::init();
    add_action("enter", "enter");
}

int enter(string str) {
    object ob;
    if(!location) x = 1;
    if(!enter) enter = "portal";
    if(x == 1) {
	write("Error.\n");
	return 1;
    }
    if(str != enter) {
	write("Enter what?\n");
	return 1;
    }
    if(this_player()->query_mounted()) {
	write("You cannot enter with someone mounting you!\n");
	return 1;
    }
    if(this_player()->query_riding()) {
	ob = this_player()->query_riding();
	ob->move(location);
    }
    this_player()->move_player(location);
    return 1;
}

