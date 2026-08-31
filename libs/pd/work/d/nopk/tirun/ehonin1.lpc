#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
    ::create();
    set_short("East Honin Road.");
    set_long(
      "Running east and west through the center of Tirun, Honin Road "
      "stays busy.  To the west the road opens into a broad open square. "
      " Far to the west the western gate to the city awaits leading out of "
      "Tirun.  The building to the south has a sign with %^MAGENTA%^a fish in an "
      "ale mug%^RESET%^ painted on it hanging above the door.  The ancient stones "
      "underfoot running east and west make the road easy to follow. "
    );
    set_night_long(
      "Running east and west through the center of Tirun, Honin Road "
      "is peaceful at night.  The road leads away into the darkness to "
      "the east and west.  To the south, the shadows coalesce into a "
      "buiding.  The stones underfoot are hard to make out in the darkness. "
    );
    set_exits( 
      (["east" : ROOMS"ehonin2",
	"west" : ROOMS"square3",
        "enter tavern" : ROOMS"pub",
	"north" : "/d/guilds/forsaken/hall"
      ]) );
add_exit_alias("enter tavern", "tavern");
add_exit_alias("enter tavern", "enter pub");
add_exit_alias("enter tavern", "pub");
add_exit_alias("enter tavern", "enter");
    set_invis_exits(({"north"}));
    set_pre_exit_functions(({"north"}), ({"check_north"}));

    set_property("light", 3);
    set_property("night light", 1);
    set_items(
      (["road" : "Ancient stones pave the ground.",
	"stones" : "Rocks carved into square and layed to make a road.",
	"marketplace" : "The center of commerce in Tirun.",
	"ships" : "Big boats berthed at the Tirun Docks.",
	"mast" : "A large pole on which a sail is hung."
      ]) );
}
int check_north() {
    if(this_player()->query_original_guild() != "forsaken" && !wizardp(this_player())) {
	write("You cannot pass.");
	return 0;
    }
    write("You pass through the bushes with ease.");
    return 1;
}
void init() {
    ::init();
    add_action("lookin", "peer");
}
int lookin(string str) {
    string *disallow;
    disallow = ({ "north", "n" });
    if(member_array(str, disallow) == -1)
	return 0;
    else {
	message("info", "This hall is closed off from view.", this_player(),);
	return 1;
    }
    message("bug", "ERROR: This shouldn't happen!", this_player(), );
    return 1;
}
