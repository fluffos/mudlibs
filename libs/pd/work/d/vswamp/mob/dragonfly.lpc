#include <std.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("dragonfly");
   set_id( ({ "dragonfly", "fly" }) );
   set_short("Dragonfly");
   set("aggressive", 3+random(4));
   set_level(4);
   set_long("The shiny dragonfly zips around, looking for a good "
           "place to land and sun itself.");
   set_body_type("insctwgd");
   set("race", "dragonfly");
   if(random(2) == 0)
     set_gender("male");
   else
     set_gender("female");
}
