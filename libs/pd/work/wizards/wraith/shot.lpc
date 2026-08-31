inherit "/std/weapon";
#include <purgatory.h>
 
create() {
    ::create();
   set_id( ({"slingshot"}) );
   set_name("%^BOLD%^%^YELLOW%^A gnarly lookin slingshot%^RESET%^");
   set_short("%^BOLD%^%^YELLOW%^A gnarly lookin slingshot%^RESET%^");
   set_long ("%^BOLD%^%^YELLOW%^This is a pretty cool toy! Made from the Y of a branch"
             "%^BOLD%^%^YELLOW%^ in the true original slingshot fashion, it can fling a rock pretty hard.%^RESET%^");
   set_weight(20);
   set_curr_value("gold", 121);
   set_wc(9);
   set_ac(2);
   set("skill level", 75);
   set_type("flail");
   set_hit((: this_object(), "weapon_hit" :));

   set_wield("%^BOLD%^%^YELLOW%^You feel like a kid again!%^RESET%^");
   set_unwield("%^BOLD%^%^BLACK%^Oh crap....all these adult responsibilities make you unwield the slingshot.%^RESET%^");
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("%^BOLD%^%^RED%^You sling shot lets fly a mighty stone which smacks %^RESET%^"+atk->query_cap_name()+" %^BOLD%^%^RED%^between the eyes.%^RESET%^");
        say("%^BOLD%^%^RED%^"+(string)this_player()->query_cap_name()+"'s sling shot lets loose a stone which hits %^RESET%^"+atk->query_cap_name()+" %^BOLD%^%^RED%^between the eyes.%^RESET%^");
       
result= (random(90)+35);

    }
}
int query_auto_load() { if (this_player()->query_level() > 38) return 1; }
