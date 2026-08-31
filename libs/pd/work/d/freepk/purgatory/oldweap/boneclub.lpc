inherit "/std/weapon";
#include <purgatory.h>
 
create() {
    ::create();
   set_short("%^BOLD%^%^WHITE%^A %^RESET%^%^WHITE%^Fe%^BOLD%^%^WHITE%^mur%^RESET%^");
   set_name("%^BOLD%^%^WHITE%^A %^RESET%^%^WHITE%^Fe%^BOLD%^%^WHITE%^mur%^RESET%^");
   set_id( ({"bone"}) );
   set_long ("%^BOLD%^%^WHITE%^A leg bone from some large mammal.%^RESET%^");
   set_weight(90);
   set_curr_value("gold", 0);
   set_wc(10);
   set_ac(2);
   set("skill level", 150);
   set_type("blunt");
   //set_hit((: this_object(), "weapon_hit" :));
   set_decay_rate(2000);
   set_wield("You wield a heavy looking bone.");
   set_unwield("You unwield a heavy looking bone.");
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("%^BOLD%^%^WHITE%^You beat past "+atk->query_cap_name()+"'s defenses and deliver a crushing blow.");
        say("%^BOLD%^%^WHITE%^"+(string)this_player()->query_cap_name()+" rushes tward "+atk->query_cap_name()+" and delivers a crushing blow.");
       
result= (random(60)+random(40))+((this_player()->query_level()));

    }
}
int query_auto_load() { if (this_player()->query_level() > 58) return 1; }


