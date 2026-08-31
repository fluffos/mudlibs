// Coded by Whit

#include <std.h>
#include <tombar.h>

inherit ROOM;
int no_orb;

void init() {
    ::init();
    add_action("climb", "climb");
    add_action("search", "search");
}

void create() {
    ::create();
    set_name("a room with a fountain");
    set_long("The stale smell seems to be coming from a large fountain "
      "sitting on the side of the south wall.  There is a high platform "
      "flying over the fountain.  There seems to be nothing but magic "
      "that holds it up.  There is a ladder that leads up to the platform."
      "  The water looks almost %^RED%^red%^RESET%^.  There is a steady "
      "stream of water that pours from the ceiling that feeds the fountain "
      "with its water.");
    set_listen("default", "The sound of dripping water is near.");
    set_smell("default", "There is a stale smell in this room.");
    set_exits(([
	"northeast" : ROOMS"4",
      ]));

    set_items(([
	(({ "walls", "wall" })) : "The walls are damp and musty from the "
	"constant exposure to moisture.",
	"ceiling" : "Water drips into the fountain feeding it with water.",
	"fountain" : "The fountain contains a red colored water.",
	"platform" : "The platform hovers magical over the fountain.",
	"ladder" : "The ladder leads up to the platform.  It looks steep "
	"and hard to climb.",
      ]));

}

int climb(string str) {
    if(!str) return notify_fail("Climb what?\n");
    if(!this_player()->query_stats("dexterity") > 30 ) return notify_fail("You "
	  "will tire out too quickly.\n");
    if(!this_player()->query_stats("strength") > 30 ) return notify_fail("You "
	  "are too weak.\n");
    write("You climb strenouslessly up the ladder.\n");
    this_player()->move_player(ROOMS"platform");
    say(this_player()->query_cap_name()+" climbs up the ladder.");
    return 1;
}

int search(string s) {
    if(s != "fountain") return 0;
    if(no_orb) {
	this_player()->add_hp(-20);
	write("Your skin burns as you search the fountain, but find nothing.");      
	return 1;
    }
    no_orb=1;
    new(OBJ"orb")->move(this_player());
    this_player()->add_hp(-20);
    write("Your skin burns as you search the fountain, and find an orb!");
    return 1;
}

void reset() {
    ::reset();
    no_orb=0;
}

