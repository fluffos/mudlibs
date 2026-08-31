#include <std.h>
#include <guild.h>

inherit ROOM;

void create() {
    ::create();
     set_name("a small cave");
     set_short("A small cave");
     set_long("A huge heart, with sections of it sliced away, sits behind the "
"counter, still beating.  At the end of the counter, a small "
"dragon-like creature sits besides a large pile of scales, weeding "
"out the bad ones.");
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "no bump"     : 1,
                    "light"       : 2,
                    "night light" : 2,
		    "no teleport" : 1,
		    "no scry" : 1,
		    "indoors" : 1,
                    "no steal"    : 1 ]) );


 set_exits( (["south" : ROOMS"dw/hallway", 
]) );

set_listen("default", "The beat of the heart echos throughout the room");
    set_items( ([
        "heart" : " A huge beating heart",
        "scales" : "A large pile of dragons scales",
        "hallway"  : "Large gouges in the rock line the hallway, they look almost like they were made by a dragons claws.",
        "stairs" : "These stairs lead back down into the heart of the guild.",
      ]) );

}

void reset() {
 ::reset();
  if (!present("temguin", this_object()))
    new(ROOMS"dw/temguin" )->move(this_object());
}
