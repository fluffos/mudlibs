
#include <std.h>
inherit WEAPON;

void create() {
   ::create();
   set_id( ({ "claw", "knuckle" }) );
   set_name("claw");
   set_short("Sabre Claw");
   set_long(
     "A well-made wrist-band of mithril and toughened leather. "
     "there are three blade extending from the knuckle in a rake style, "
     "fastened at the back-hand. "
   );
   set_mass(25);
   set_value(60);
   set_wc(10);
   set_ac(1);
   set_type("melee");
   set_hit( (: this_object(), "weapon_hit" :) );
}
int weapon_hit(){
   int result;
   object atk;
   atk = (object)this_player()->query_current_attacker();
   if(random(100) > 4) {
   write(
     "%^BOLD%^%^BLUE%^You slash "+ atk->query_name() +
     " horribly with your claw.%^RESET%^\n");
   say(
     "%^BOLD%^%^BLUE%^"
     + this_player()->query_cap_name() + " slashes "
     +atk->query_name()+
     " horribly with " + this_player()->query_possessive() +
     " claw. \n"
   );
   result=(random(100)) + ((this_player()->query_skill("blade")));
   return result;
   }
}



