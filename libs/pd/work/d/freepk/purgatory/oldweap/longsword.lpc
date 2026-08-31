inherit "/std/weapon";
#include <purgatory.h>
 
create() {
    ::create();
   set_short("%^RESET%^%^ORANGE%^Bar%^BOLD%^%^YELLOW%^bar%^BOLD%^%^BLACK%^ic %^RESET%^%^ORANGE%^Longsword%^RESET%^");
   set_name("%^RESET%^%^ORANGE%^Bar%^BOLD%^%^YELLOW%^bar%^BOLD%^%^BLACK%^ic %^RESET%^%^ORANGE%^Longsword%^RESET%^");
   set_id( ({"sword", "longsword", "barbaric longsword"}) );
   set_long ("This longsword is crudely crafted, but in the right hands can become a very deadly weapon. One side of its blade has been serrated, the other side sharper than a razor.");
   set_weight(55+random(30));
   set_curr_value("gold", 50+random(70));
   set_wc(5+random(4));
   set_ac(2);
   set("skill level", 75+random(40));
   set_type("blade");
   //set_hit((: this_object(), "weapon_hit" :));

}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(100) < 10) {
        write("%^RESET%^%^ORANGE%^The longsword rips peices of "+atk->query_cap_name()+" free from its body.%^RESET%^");
        say("%^RESET%^%^ORANGE%^"+(string)this_player()->query_cap_name()+"'s longsword rips out peices of "+atk->query_cap_name()+".%^RESET%^");
       
result=(80+random(50))+((this_player()->query_level()));

    }
}
int query_auto_load() { if (this_player()->query_level() > 48+random(20)) return 1; }
