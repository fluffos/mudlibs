inherit "/std/weapon";
#include <purgatory.h>
 
create() {
    ::create();
   set_short("Barbarian War Axe");
   set_name("Barbarian War Axe");
   set_id( ({"axe"}) );
   set_long ("This axe looks like it could do considerable damage with its large half-moon blade on one end and a horrible looking serrated spike from the other.");
   set_weight(97);
   set_curr_value("gold", 345);
   set_wc(9);
   set_ac(2);
   set("skill level", 175);
   set_type("axe");
   set_hit((: this_object(), "weapon_hit" :));

   set_wield("You stumble around tryin to hold the axe up.");
   set_unwield("You drop the axe from your tired hands.");
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("%^BOLD%^%^RED%^The axe rips a hole in "+atk->query_cap_name()+".%^RESET%^");
        say("%^BOLD%^%^RED%^"+(string)this_player()->query_cap_name()+" rips a hole in "+atk->query_cap_name()+" with their axe.%^RESET%^");
       
result=(random(100)+40)+((this_player()->query_level()));


    }
}
int query_auto_load() { if (this_player()->query_level() > 54) return 1; }
