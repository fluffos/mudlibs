#include <std.h>
#include <arlon.h>

inherit ROOM;

void create()
{
 ::create();
 set_short("Plains");
 set_long("The green grass starts to get taller as you wander "
          "farther away. Trees start to be more common and "
          "make it a bit darker. Animals are scurring away "
          "as you make your presence in the area. There is a "
          "giant plateau to the east of you.");
 set_listen("default", "The breeze blows on you lightly.");
 set_exits( ([ "west" : ROOMS "plains19",
               "east" : ROOMS "den",
               "up"   : ROOMS "plateau" ]) );
}




