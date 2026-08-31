#include <std.h>
#include <arlon.h>

inherit ROOM;

void create()
{
 ::create();
  set_property("plains",1);
 set_short("A path");
 set_long("The green grass stands tall waving in the wind. The ground "
          "is a little moist and foot prints and an assortment of "
          "animal foot prints. There are a couple short trees "
          "scattered around. You can see the town more clearly to the "
          "south");
 set_listen("default", "The breeze blows on you lightly.");
 set_exits( ([ "north": ROOMS "plains8",
               "south": ROOMS "plains10" ]) );
}


