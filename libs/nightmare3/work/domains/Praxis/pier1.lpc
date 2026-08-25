#include <std.h>

inherit PIER;

void create() {
    ::create();
    set_property("no castle", 1);
    set_property("light", 3);
    set_property("night light", 2);
    set_max_catch(15);
    set_max_fishing(4);
    set_chance(10);
    set_short( "Pier 1 of the Port of Praxis");
    set_long(
        "Welcome to the Port of Praxis!\n"
"The Pier 1 port is virtually bustling with activity. Ships from "
"all over the reality dock here to deliver their goods to Praxis "
"and its surrounding regions. The pier is made out of solid wood "
"which has become weathered due to the rain and salty air. Torches "
"line each side of the dockss, lighting the way at night. All along "
"the pier you can see people fishing, talking and enjoying the weather.");
      set_smell("default", "Rotting fish offend your nostrils.");
      set_smell("fish", "They smell as if they have been out for days.");
    set_items(
	(["port" : "Ships from all over Nightmare dock here to "
	    "do business in Praxis.",
	  "pier" : "Pier 1 of the port.",
	  "goods" : "Merchandise from exotic places.",
	  "torch" : "It lights up the pier at night.",
	  "torches" : "They light up the pier at night."]) );
    set_exits( 
	      (["north" : "/domains/Praxis/s_centre4" 	
           ]) );
}

void reset() {
    int i;

    ::reset();
    if(!present("stick"))
      new("/domains/Praxis/obj/misc/fishing_pole")->move(this_object());
    if(present("match")) return;
    i = 4;
    while(i--) new("/domains/Praxis/obj/misc/match")->move(this_object());
}

