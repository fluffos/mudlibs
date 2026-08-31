//Tirun Sewers Monster
//By Nightshade

#include <std.h>

inherit MONSTER;

void create() {
 ::create();
   set_name("man-snake");
   set_id(({"snake", "monster", "man snake"}));
   set_short("%^BOLD%^%^CYAN%^Man%^RESET%^-%^BOLD%^%^RED%^Sn%^BLUE%^a%^RED%^ke");
   set_long("This snake has legs and and arms!  It wanders towards you and flicks "
        "it's tongue out at you.");
   set_race("snake");
   if(random(2) == 0)
     set_gender("male");
   else
     set_gender("female");
   set_body_type("human");
   add_limb("tail", 0, 4, 0, 1);
   set_level(25);
   this_object()->add_money("gold", random(45));
}
