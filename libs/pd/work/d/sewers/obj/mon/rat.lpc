
//Tirun Sewers Monster
//By Nightshade

#include <std.h>

inherit MONSTER;

void create() {
 ::create();
   set_name("rat");
   set_id(({"rat", "monster", "dirty rat"}));
   set_short("Dirty Rat");
   set_long("The filthy rat has been scurrying about, trying to collect "
        "as much junk as it can find.");
   set_race("rat");

   if(random(2) == 0)
     set_gender("male");
   else
     set_gender("female");
   set_body_type("ferrel");
   set_level(18);
   this_object()->add_money("gold", random(20));
}
