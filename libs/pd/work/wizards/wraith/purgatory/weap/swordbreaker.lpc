inherit "/std/weapon";
#include <purgatory.h>
 
create() {
    ::create();
   set_short("Sword breaker");
   set_name("Sword breaker");
   set_id( ({"sword breaker", "breaker"}) );
   set_long ("This is a sword breaker, meant to catch and turn aside swords in battle with its notched edges.");
   set_weight(68+random(15));
   set_curr_value("gold", 125+random(10));
   set_wc(3+random(4));
   set_ac(1);
   set("skill level", 100+random(35));
   set_type("blunt");
   set_hit((: this_object(), "weapon_hit" :));
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("Your sword breaker %^BOLD%^%^RED%^smashes%^RESET%^ "+atk->query_cap_name()+" upside the head.");
        say(""+(string)this_player()->query_cap_name()+"'s sword breaker %^BOLD%^%^RED%^smashes%^RESET%^ "+atk->query_cap_name()+"'s head.");
       
result=(random(100)+40)+((this_player()->query_level()));

    }
}
int query_auto_load() { if (this_player()->query_level() > 45) return 1; }
