#include <std.h>
#include <arlon.h>

inherit ROOM;

void create()
{
 ::create();
  set_property("plains",1);
 set_short("Plains");
 set_long("The green grass stands tall waving in the wind. The ground "
          "is a little moist and foot prints and an assortment of "
          "animal foot prints. Animals roam freely across the plains. "
          "The grass tickles you as the wind blows them against the grass.");
 set_listen("default", "The breeze blows on you lightly.");
 set_exits( ([ "west" : ROOMS "plains14",
               "south" : ROOMS "plains20",
               "north" : ROOMS "plains16" ]) );
}

void reset()
{
 ::reset();
}



