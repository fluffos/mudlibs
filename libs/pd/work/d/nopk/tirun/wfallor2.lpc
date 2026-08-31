#include <std.h>
#include <tirun.h>

inherit ROOM;

int searched;

void create() {
    ::create();
    set_short("West Fallor Road.");
    set_long(
      "Fallor Road is lightly traveled.  Houses line the road to the "
      "north and south.  The ancient stones underfoot running east and "
      "west make the road easy to follow.  One stone sticks out unusually.");
    set_night_long(
      "Running east and west through the southwest section of Tirun, "
      "Fallor Road is peaceful at night.  Shadows to the north and south "
      "show themselves to be buildings.  The stones underfoot are hard "
      "to make out in the darkness.  One of the stones seems a bit odd.");

    set_exits( (["west" : ROOMS"wfallor3",
	"east" : ROOMS"wfallor1"]) );
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
      (["road" : "Ancient stones pave the ground.",
	"stones" : "Rocks carved into squares and layed to make a road.",
	"wall" : "A fortified wall that protects the city.",
	"stone" : "The stone must be covering something..."
      ]) );
    searched = 0;
}

void init() {
    ::init();
    add_action("search", "search");
}

void reset() {
    ::reset();
    searched = 0;
}

int search(string str) {
    if(str != "stone" && str != "stones")
	return 0;
    if(searched) {
	write("Someone has already found something here...");
	return 1;
    }
    write("You find a strange book underneath a stone!");
    say(this_player()->query_cap_name()+" finds a strange book!");
    new("/d/nopk/tirun/obj/misc/sbook")->move(this_player());
    searched = 1;
    return 1;
}
