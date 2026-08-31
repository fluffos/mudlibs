//Tirun Sewers Monster
//By Nightshade

#include <std.h>

inherit MONSTER;

void create() {
 ::create();
   set_name("slug");
   set_id(({"slug", "monster"}));
   set_short("%^BOLD%^%^BLACK%^Slug");
   set_long("The slug slides across the ground slowly, trying to worm it's"
        " way along the sewer lines.");
   set_race("slug");
   if(random(2) == 0)
     set_gender("male");
   else
     set_gender("female");
   set_body_type("worm");
   set_level(18);
   this_object()->add_money("gold", random(10));
}
