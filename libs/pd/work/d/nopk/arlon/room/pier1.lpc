#include <std.h>
#include <arlon.h>

inherit ROOM;

void create()
{
 ::create();
 set_short("On a pier");
 set_long("The pier extends out to the ocean. There are many boats "
          "docked below the pier. The pier creaks from the waves. "
          "There is a stairwell down to the lower part of the pier.");
 set_listen("default", "The breeze blows on you lightly.");
 set_smell("default", "The strong smell of sea water fills the air.");

 set_exits( ([ "east" : ROOMS "pier",
               "down" : ROOMS "loadb" ]) );
 
}
