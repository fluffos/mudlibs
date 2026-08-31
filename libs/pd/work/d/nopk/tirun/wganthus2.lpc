#include <std.h>
#include <tirun.h>
inherit ROOM;

void init() {
    ::init();
    add_action("move_tapestry", "step");
    add_action("down", "south");
}

void create() {
    ::create();
    set_short("West Ganthus Circle.");
    set_long(
      "Ganthus Road is a lightly-traveled road that circles around the heart of "
      "Tirun.  Because it leads through a rich neighborhood the road is as well "
      "guarded as the market.  The stones underfoot are well kept and the road "
      "is clean.  Large houses line the road to the north and south.  ");
    set_night_long("Ganthus Road is deserted and peaceful at night.  To the north and south, "
      "the shadows coalesce into buildings.  The stones underfoot are hard to "
      "make out in the darkness.  The road leads off into the darkness to the "
      "east and west.  ");
    set_exits(([
	"west"  : ROOMS"swganthus",
	"east"  : ROOMS"wganthus1",
      ]) );
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
      (["road" : "Ganthus Road runs through the heart of Tirun.",
	"houses" : "Large two story brownstone houses."]) );
}

int move_tapestry(string str) {
    if(!str) {
	notify_fail("step what?\n");
	return 0;

    }
    if(str != "stone") {
	notify_fail("You step on that!\n");
	return 0;
    }

    say(this_player()->query_cap_name()+" steps on a stone and a entrance appears to the south");
    write("The stone sinks into the ground opening a secret passage "
      "to the south");
    add_exit("/d/guilds/scorpio/entrance", "south");
    call_out("go_hole", 15);
    return 1;
}

void go_hole() {
    message("info", "A secret passage moves to the south.",
      all_inventory(this_object()));
    remove_exit("south");
}

int down() {
    if(this_player()->query_guild()!="scorpio" && !wizardp(this_player())) {
	notify_fail("A gust of wind prevents you from entering.");
	say("A gust of wind blows as "+this_player()->query_cap_name()+" tries "
	  "to go south but fails.");
	return 1;
    }
    this_player()->move_player("/d/guilds/scorpio/entrance");
    return 1;
}

