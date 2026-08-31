#include <std.h>
#include <kabaal.h>
inherit ROOM;

void create()
{
 ::create();
set_short("lost in the forest");
   set_long("The jungle is now south, west, and east of here. There are "
           "cast iron gates open to the north. Through the gates a city "
           "lies. The city appears very old yet as if some still inhabit "
	   "it. ");
set_items( 
          ([ "path" : "The path is pretty much gone, but starts up south of here.",
	     "ground": "The ground is starting to solidify that it is out of the forest.",
	     "city": "A city looms north of here.",
	     "gates": "The large gates surround the ancient city.",
             "forest" : "Tall trees surround you." ]) );
set_property("light", 3);
set_property("night light", 2);
set_listen("default", "Faint murmuring and noises from the forest intertwine with eachother.");
set_exits( (["south" :ROOMS "logan1",
              "gates" : ROOMS "logan3"]) );
}
