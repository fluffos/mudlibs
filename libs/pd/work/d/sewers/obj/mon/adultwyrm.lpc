//Tirun Sewers Monster
//By Nightshade

#include <std.h>

inherit MONSTER;

void create() {
 ::create();
   set_name("ancient wyrm");
   set_id(({"wyrm", "monster", "ancient wyrm"}));
   set_short("Ancient Wyrm");
   set_long("This adult wyrm has been around for ages, resting peacefully in "
        "the depths of the sewers.  Its muscles ripple as it notices you approach.");
   set_race("wyrm");
   if(random(2) == 0)
     set_gender("male");
   else
     set_gender("female");
   set_body_type("worm");
   set_level(26);
   this_object()->add_money("gold", random(60));
}
