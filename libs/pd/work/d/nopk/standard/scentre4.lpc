#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 3);
    set_property("night light", 1);
    set_property("no castle", 1);
    set("short", "Tirun Commercial District");
    set("day long",
      "Centre Path leads south into the bustling Port of Tirun where it "
      "dead ends at Pier 1. Business life hurries all about you to get "
      "things done before the end of the short Tirun day. In the great "
      "Hall of Fighters northwest fighters gather both night and day. "
      "Tirun centre is northeast from here."
    );
    set("night long",
      "Even in the heart of night people are moving about the business "
      "district trying to conduct monetary affairs with those types who "
      "shy away from daylight. The shadiest of characters arrive in Tirun "
      "at Pier 1 of the Port of Tirun south under cloak of night. Fighters "
      "of all races, especially the nocturnal ones gather in the Hall of "
      "Fighters northwest. Tirun centre is northeast.");
    set_exits( 
	      (["northwest" : ROOMS"fighter_join",
		"northeast" : ROOMS"sveros3",
		"east" : ROOMS"realty",
		"south" : ROOMS"pier1"]) );
    set_items( 
	([({"path", "veros path"}) : "It is the main road winding "
	    "north and south through Tirun.",
	  ({"pier", "port", "port of tirun"}) : "Everything that "
	    "comes into Tirun from overseas comes through here.",
	  ({"hall", "hall of fighters"}) : "The fighters of this "
	    "reality often come from all over to gather there.",
	  "realty" : "High mortals by stuff to build castles with there.", 
	  "fighters" : "They are roaming aimlessly about the Hall of "
	    "Fighters.",
	  "people" : "They are going about their business in the area.",
	  "high mortals" : "The mightiest of mortals who often "
	    "comprise class leaders."])  );
    set_listen("default", "You hear many people going about their "
		      "business.");
      set_listen("fighters", "They are being really loud and rude.");
      set_smell("money", "Damn, you sure are greedy.");
      set_smell("fish", "You smell that they have been lying all over "
		       "the pier south.");
}

