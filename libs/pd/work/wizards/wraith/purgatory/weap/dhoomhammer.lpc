inherit "/std/weapon";
#include <purgatory.h>
 
create() {
    ::create();
   set_short("%^BOLD%^%^RED%^Dh%^RESET%^%^RED%^oo%^BOLD%^%^RED%^m Ha%^RESET%^%^RED%^mm%^BOLD%^%^RED%^er%^RESET%^");
   set_name("%^BOLD%^%^RED%^Dh%^RESET%^%^RED%^oo%^BOLD%^%^RED%^m Ha%^RESET%^%^RED%^mm%^BOLD%^%^RED%^er%^RESET%^");
   set_id( ({"hammer"}) );
   set_long ("%^BOLD%^%^RED%^Made in the forges of the dreaded Dhoom Magi, this hammer can deliver blows that incapcitate its victims.%^RESET%^");
   set_weight(99);
   set_curr_value("gold", 121);
   set_wc(10);
   set_ac(2);
   set("skill level", 75);
   set_type("blunt");
   set_hit((: this_object(), "weapon_hit" :));

   set_wield("%^CYAN%^You stagger and stumble until you get used to the offset weight of the hammer.%^RESET%^");
   set_unwield("%^BOLD%^%^BLACK%^Your arms are too tired to wield the hammer anymore.%^RESET%^");
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("%^BOLD%^%^CYAN%^You bring your hammer down on "+atk->query_cap_name()+"'s head, crushing their skull.%^RESET%^");
        say("%^BOLD%^%^CYAN%^"+(string)this_player()->query_cap_name()+" brings their hammer down on "+atk->query_cap_name()+"'s head, crushing its skull.%^RESET%^");
       
result= (random(40)+35);
       if(random(100)> 3) { 
          query_wielded()->query_current_attacker()->set_paralyzed(6);}
    }
}
int query_auto_load() { if (this_player()->query_level() > 38) return 1; }
