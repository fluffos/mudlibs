#include <std.h>
#include <arlon.h>

inherit ROOM;

void init() {
    ::init();
     add_action("go_up","up");

}

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set("short", "The Hall of Fighters");
    set("long",
      "You are at the Arlon fighter hall.\n"
      "The Hall of Fighters is decorated with ornate tapestries of "
      "men and women engaged in combat of all traditions.  Adventuring "
      "fighters are gathered around discussing glory at the base of a "
      "spiraling staircase which leads up through a magically lit hole "
      "in the ceiling.");
    set_items( 
	([({"tapestry", "tapestries", "wall"}) : "The walls are all "
	    "covered with some of the most ornate tapestries from "
	    "all over.  The one you are looking at depicts a heroic "
	    "battle between a dragon and a human combatant.",
	  ({"hole", "light", "opening", "ceiling"}) : "Up in the ceiling, "
	    "the staircase leads through a mystical light up "
	    "to the second floor.",
	  "staircase" : "It leads through the opening in the ceiling "
	    "to the second floor.",
	  "fighters" : "They are loud and obnoxious." ]) );
    set_exits( 
        (["south" : ROOMS"wsquare3",
          "up" : "(: up :)"]) );
    set_listen("default", "Fighters are yelling and screaming and "
      "being generally obnoxiously loud.");
}



int go_up() {
    if((string)this_player()->query_class() != "fighter") {
	write("You cannot penetrate the force field that blocks the passage.");
	say(this_player()->query_cap_name()+" tries to get into the "
	    "fighter's sanctuary, but fails.", this_player());
	return 1;
    }
    this_player()->move_player(ROOMS"fighter_hall", "through the light in the passage");
    return 1;
}

