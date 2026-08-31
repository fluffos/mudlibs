#include <std.h>
#include <marsh.h>
#include <daemons.h>
inherit DOCKS;
void create()
{
 ::create();
 set_short("Mystic Marsh's Docks");
 set_long("An abandoned pier rots away slowly as it sits out in the water.   "
          "The pier is pieced together with long wooden planks that sags "
          "dangerously in the center.  There is one narrow walkway that "
          "leads inland towards a swampy marsh."
);
 set_listen("default", "The pier squeaks loudly as the tides come in.");
 set_smell("default", "A heavy scent of old mud lingers in the air.
");
 set_exits( ([ 
"north" : MARSH "docks4",
"west"  : MARSH "docks",
"east"  : MARSH "docks3",
]) );
 set_letter("C");
}
