#include <std.h>
#include "/d/dagger/road/short.h"
inherit ROOM;

void create(){
    ::create();
	set_terrain(OLD_MOUNTS);
	set_travel(DIRT_ROAD);
    set_property("light", 2);
    set_short("The Dagger Sea coast road bridge.");
    set_long("%^CYAN%^You are on the %^RESET%^bridge%^CYAN%^ crossing the river Shelk. To the southeast you can see where the river pours downhill into the Dagger sea, its great delta brown against the %^BOLD%^striking blue%^RESET%^%^CYAN%^ of the %^BOLD%^ocean%^RESET%^%^CYAN%^. To the northwest, the road leads towards the vibrant Yniam plains that the river drains. To the northeast you can make out the towers of the Seaport of Torm, and a little to the north of that is the rumored ghost town of Nurval.");
	set_smell("default", "%^YELLOW%^That's strange, you can smell mutton cooking.");
    set_listen("default", "%^BOLD%^%^BLUE%^You can hear the river splashing against the rocks below.");
    set_items( ([
    "road" : "It looks well traveled.",
	"sea" : "You can see the surf on the beach downhill to the east.",
	"beach" : "The deep blue water foams as it splashes as surf against the beach far below.",
	"marsh" : "It looks deep and evil, monsters will abound there in droves.",
    "bridge" : "It's made of white marble and looks very strong and sturdy. There are some metal rungs attached to one side.",
	"rungs" : "It's a ladder leading down the side of the bridge.",
	"ladder" : "It's a metal rung ladder. It leads down the side of the bridge. You could try climbing down it.",
	"river" : "The river current appears strong and the water looks cool and clean.",
	"torm" : "Along the coast below is the seaport of Torm, known for its fresh seafood, great inns and a bit of rum.",
	"nurval" : "Up to the northeast is the dreaded town of Nurval, home to Nillith and the undead",
    ]) );

    set_exits( ([
	"southwest" : RPATH "road11",
	"northeast" : RPATH "road13",
      ]) );
}

void init() {
    ::init();

    add_action("climb_ladder","climb");
}

int climb_ladder(string str) {
    if(!str) {
	write("Climb what!");
	return 1;
    }
    if((str == "ladder") || (str=="down ladder")){
	write("%^ORANGE%^You climb down the rungs and step underneath the bridge.");
	say("%^ORANGE%^"+this_player()->query_cap_name()+" climbs up a set of rungs and disappears under the bridge.");
	this_player()->move_player(RPATH "bridge2");
	return 1;
    }
}
