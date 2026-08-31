//Tirun Sewers Monster
//By Nightshade

#include <std.h>

inherit MONSTER;

void create() {
 ::create();
   set_name("wererat");
   set_id(({"wererat", "monster", "large rat"}));
   set_short("Large Wererat");
   set_long("This rat is huge!  It almost takes on the form of a human, "
        "if it weren't for it's snout and tail.  The rat glowers at you.");
   set_race("rat");
   if(random(2) == 0)
     set_gender("male");
   else
     set_gender("female");
   set_body_type("feline");
   set_level(23);
   this_object()->add_money("gold", random(40));
}
