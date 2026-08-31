#include <std.h>
#include <purgatory.h>
inherit WEAPON;
int weapon_hit(object atk);
 
create() {
    ::create();
   set_short("Sword breaker");
   set_name("Sword breaker");
   set_id( ({"sword breaker", "breaker"}) );
   set_long ("This is a sword breaker, meant to catch and turn aside swords in battle with its notched edges.");
   set_weight(17);
   set_curr_value("gold", 150);
   set_wc(8);
   set_ac(1);
   set("skill level", 135);
   set_type("blunt");
   set_hit((: weapon_hit :));
    set_decay_rate(2000);
}
int weapon_hit(object atk)
{
    int result;
    if(random(100) < 10) {
        write("Your sword breaker %^BOLD%^%^RED%^smashes%^RESET%^ "+atk->query_cap_name()+" upside the head.");
        say(""+(string)this_player()->query_cap_name()+"'s sword breaker %^BOLD%^%^RED%^smashes%^RESET%^ "+atk->query_cap_name()+"'s head.");
       
result=(random(30))+((this_player()->query_level()));

    }
}
int query_auto_load() { if (this_player()->query_level() > 25) return 1; }
