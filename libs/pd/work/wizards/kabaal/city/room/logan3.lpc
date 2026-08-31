#include <std.h>
#include <kabaal.h>
inherit ROOM;

void create()
{
 ::create();
set_short("Logan gates");
   set_long("This is the base of a small, old looking city. Off to the "
           "northeast it looks as though there is a peak of a mountain, "
           "but trees cover up viewing the entire thing. Several "
           "old-looking buildings can be seen north. ");
set_items( 
          ([ "buildings" : "Several old-looking buildings are seen ahead.",
             "mountain": "The tip of a mountain range is seen northeast.",
             "city": "You are at the gates of a city.",
             "gates": "The large gates surround the ancient city.",
             "forest" : "Trees cover up what appears to be a mountain." ]) );
set_property("light", 3);
set_property("night light", 2);
set_listen("default", "Faint murmuring and noises from the forest intertwine with eachother.");
set_exits( (["north" : ROOMS "logan4",
	     "east" : ROOMS "logan5",
              "gates" : ROOMS "logan2"]) );
}
