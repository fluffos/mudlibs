//Dragon quest area
//Nightshade

#include <std.h>
inherit ROOM;

string foot;

void create() {
    ::create();
    set_short("Stone Hallway");
    set_properties( (["light" : 2, "night light" : 2]) );
    set_property("indoors", 1);
    set_property("no teleport", 1);
    set_listen("default", "A small rock can be heard tumbling somewhere.");
    set_long("After a distance, the flow of water bubbles up into a small pond.  The room here seems to have been carved out of the stone, as the walls are flat and smooth, coming to precise corners.  There are magnificent carvings of dragons framing the hallway that continues to the east.");
    set_exits( (["east" : "/d/tirun/monastery"]) );
    add_pre_exit_function("east", "go_east");
    if(random(2) == 0)
	foot = "right";
    else
	foot = "left";
    set_items( ([ "pond" : "The pond is a few meters wide, it must be used as a well of some sort."
	,"walls" : "The walls are smooth and chiseled, with a few designs carved into them in a few places."
	,"dragons" : "They are incredibly accurate, as if a dragon actually posed for the artist."
	,"hallway" : "The hallway leads into another room of somesort.  A flickering red glow can be seen, probably from a torch."
	,"designs" : "One of the designs looks like an odd picture."
	,"picture" : "The picture depicts a humanoid hopping on it's "+foot+" foot.  How curious."
      ]) );
}

void init() {
    ::init();
    add_action("hop", "hop");
    add_action("peer", "peer");
}

int peer(string str) {
    if(str != "east")
	return 0;
    write("Only the flickering red glow of a fire can be seen.");
    return 1;
}

int hop(string str) {
    string which;
    if(!str) return 0;
    if(sscanf(str, "on %s foot", which) != 1)
	return 0;
    if(which != foot) {
	write("%^BOLD%^%^RED%^THE FLOOR CUMBLES BENEATH YOU!!!%^RESET%^");
	return 1;
    }
    write("You hop on your "+which+" foot down the hallway until you reach the other room.");
    call_out("do_move", 2, this_player());
    return 1;
}

int go_east() {
    write("%^BOLD%^%^RED%^THE FLOOR CUMBLES BENEATH YOU!!!%^RESET%^");
    return 1;
}

void do_move(object tp) {
    tp->move_player("/d/quests/dragon/three", "east");
}
