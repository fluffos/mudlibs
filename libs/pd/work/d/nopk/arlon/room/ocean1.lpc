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
          "animal foot prints. The ocean gets closer and there are"
          "a lot of boats docked in the distance.");
 set_listen("default", "The breeze blows on you lightly.");
 set_smell("default", "The strong smell of sea water fills the air.");

 set_exits( ([ "east" : ROOMS "plains11",
               "west" : ROOMS "ocean2" ]) );
}
