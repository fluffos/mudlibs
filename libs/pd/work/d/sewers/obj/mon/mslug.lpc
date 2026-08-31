//Tirun Sewers Monster
//By Nightshade

#include <std.h>

inherit MONSTER;

void create() {
 ::create();
   set_name("mutant slug");
   set_id(({"slug", "monster", "mutant slug"}));
   set_short("%^BOLD%^%^YELLOW%^Mutant %^BLACK%^Slug");
   set_long("The gigantic slug nearly fills the entire passage"
        "way along the sewer lines.  It writhes towards you menacingly.");
   set_race("slug");
   if(random(2) == 0)
     set_gender("male");
   else
     set_gender("female");
   set_body_type("worm");
   set_level(22);
   this_object()->add_money("gold", random(20));
}
