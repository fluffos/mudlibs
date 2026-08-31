#include <std.h>
#include <tirun.h>
inherit ROOM;

void init() {
    ::init();
    add_action("tap_stone", "tap");
}

void create() {
    ::create();
    set_short("West Ganthus Circle.");
    set_long(
      "Ganthus Road is a lightly-traveled road that circles around the heart of "
      "Tirun.  Because it leads through a rich neighborhood the road is as well "
      "guarded as the market.  The stones underfoot are well kept and the road "
      "is clean.  Large houses line the road to the north and south.  ");
    set_night_long(
      "Ganthus Road is deserted and peaceful at night.  To the north and south, "
      "the shadows coalesce into buildings.  The stones underfoot are hard to "
      "make out in the darkness.  The road leads off into the darkness to the "
      "west and east.  ");
    set_exits(([
	"west"  : ROOMS"nwganthus2",
	"east"  : ROOMS"nveros2",]));
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
      (["road" : "Ganthus Road runs through the heart of Tirun.",
	"houses" : "Large two story brownstone houses."]) );
}

int tap_stone(string str) {
    if(!str) {
	notify_fail("What in Stormbringer's name are you talking about?\n");
	return 0;

    }
    if(str != "stone") {
	notify_fail("You, sir, are an idiot!\n");
	return 0;
    }

    message("info", (string)this_player()->query_cap_name()+" looks shifty eyed for a minute as they do something hidden. ", this_object(), ({ this_player() }));
    message("info", "A stone flips up out of the ground.", this_player());
    add_exit("/d/guilds/acheron/entrance", "down");
    call_out("go_hole", 10);
    return 1;
}

void go_hole() {
    message("info", "The stone flips back over.",
      all_inventory(this_object()));
    remove_exit("down");
}
