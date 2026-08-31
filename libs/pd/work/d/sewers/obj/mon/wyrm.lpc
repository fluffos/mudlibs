//Tirun Sewers Monster
//By Nightshade

#include <std.h>

inherit MONSTER;

void create() {
 ::create();
   set_name("wyrm");
   set_id(({"wyrm", "monster"}));
   set_short("Sewer Wyrm");
   set_long("This wyrm has taken residence in the sewers because of the"
        " damp climate.  It seems to be relaxing under a stream of cool water");
   set_race("wyrm");
   if(random(2) == 0)
     set_gender("male");
   else
     set_gender("female");
   set_body_type("worm");
   set_level(21);
   this_object()->add_money("gold", random(35));
}
