#include <std.h>
#include <petzoo.h>
inherit ROOM;

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Main Intersection");
    set("long", "This is the main intersection along the path through "+
      "the petting zoo.  To the south is the main gate where you can "+
      "find the gift shops.  East and west lead to the various petting"+
      " exibits.  To the north is a huge aquarium filled with large "+
      "aquatic creatures.  With permission you can get in and swim "+
      "around with them.  Careful, though, they are big!\n\n"+
      "A sign post stands here.");
    set_exits( ([ "west" : ROOMS + "zoopath3", 
	"north" : ROOMS + "aquarium",
	"east" : ROOMS + "zoopath15",
	"south" : ROOMS + "zoopath1" ]) );
    set_items( (["sign": "--------------------------------"+
	"\n\n<--- goats, pigs, and puppies\n\n"+
	"lambs, llamas, and ponies --->\n\n"+
	"<--- raccoons, kittens and mice\n"+
	"--------------------------------"]) );
}
