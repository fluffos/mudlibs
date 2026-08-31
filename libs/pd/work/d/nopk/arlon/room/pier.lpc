#include <std.h>
#include <arlon.h>

inherit ROOM;

void create()
{
 ::create();
 set_short("On a pier");
 set_long("The pier extends out to the ocean. There are many boats "
          "docked below the pier. The pier creaks from the waves. "
          "There is a small shack to the north with a sign on the door.");
 set_listen("default", "The breeze blows on you lightly.");
 set_smell("default", "The strong smell of sea water fills the air.");

 set_exits( ([ "east" : ROOMS "ocean2",
               "west" : ROOMS "pier1", 
               "north" : ROOMS "store" ]) );
 set_items( ([ "sign" : "We sell boats for cheap!" ]) );
}
