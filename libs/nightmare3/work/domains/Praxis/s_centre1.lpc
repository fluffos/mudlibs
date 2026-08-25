#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_listen_string("default", "Raucus noise is coming from "
		      "inside the pub west.");
    set_short( "Centre Path outside Lars' Pub");
    set_long(
"Centre Path leads through the heart of the business district "
"of Praxis, and down towards the famous Port of Praxis. "
"Rowdy customers can be seen heading west towards Lar's Pub. "
"The building is very old and worn. The abuse of many drunken "
"adventurer's has began to take its toll on the establishment. "
);
    set_exits( 
	      (["north" : "/domains/Praxis/square",
		"south" : "/domains/Praxis/s_centre2",
		"west" : "/domains/Praxis/pub"]) );
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["path" : "Centre Path leads to Monument Square south and out "
	    "of town north.",
	  "road" : "Boc La Road is the main east-west road.",
	  "pub" : "Lars Pub, now mostly obsolete, but it is the original.",
	  "square" : "The central square of Praxis."]) );
    set_property("no castle", 1);
}

