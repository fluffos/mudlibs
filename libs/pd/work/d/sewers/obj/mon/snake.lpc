//Tirun Sewers Monster
//By Nightshade

#include <std.h>

inherit MONSTER;

void create() {
 ::create();
   set_name("snake");
   set_id(({"snake", "monster", "water snake"}));
   set_short("%^BOLD%^%^RED%^Wa%^BLUE%^te%^RED%^r S%^BLUE%^na%^RED%^ke");
   set_long("The %^BOLD%^%^BLUE%^bright blue water snake %^RESET%^slithers "
        "across the bottom of the sewer.");
   set_race("snake");
   if(random(2) == 0)
     set_gender("male");
   else
     set_gender("female");
   set_body_type("snake");
   set_level(20);
   this_object()->add_money("gold", random(14));
}
