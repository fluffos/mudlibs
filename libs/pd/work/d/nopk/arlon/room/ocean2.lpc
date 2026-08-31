#include <std.h>
#include <arlon.h>

inherit ROOM;

void create()
{
 ::create();
 set_short("On a pier");
 set_long("The pier extends out to the ocean. There are many boats "
          "docked out on the pier. The pier creaks from the waves "
          "hitting against the supports. There is a small building "
          "to the northwest.");
 set_listen("default", "The breeze blows on you lightly.");
 set_smell("default", "The strong smell of sea water fills the air.");

 set_exits( ([ "east" : ROOMS "ocean1",
               "west" : ROOMS "pier"  ]) );
}
