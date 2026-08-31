#include <std.h>
#include <sindarii.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("indoors", 1);
    set_property("no castle", 1);
    set_listen("default", "Sounds taunt you from every direction.");
    set_smell("default", "Musty odors arise from deeper into the "
      "mountain.");
    set("short", "Tunnel entrance under the Daroq Mountains");
    set("long",
        "You are inside the poorly lit tunnel of goblins under the Daroq "
        "Mountains.  The only source of light is the opening to the outside.  "
        "As the tunnel drops down deeper into the mountain, it gets even darker."
	"  On the east wall a thick clump of bushes has grown up in "
	"front of a small cave making it difficult to see it. "
	"Off to the northeast you can see a rocky path.");
    set_items(
        (["tunnel" : "It is very dim.",
	  "light" : "There is not much of it.",
	  "opening" : "It leads to the outside world.",
	  "mountain" : "You feel evil throughout it."]) );
    set_exits( 
              (["out" : ROOMS "spass4",
                "down" : ROOMS "mountains/tunnel1"]) );
}
