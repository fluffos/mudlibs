#include <std.h>
#include <purgatory.h>
inherit WEAPON;
int weapon_hit(object atk);

create() {
    ::create();
   set_short("%^RESET%^%^ORANGE%^Bar%^BOLD%^%^YELLOW%^bar%^BOLD%^%^BLACK%^ic %^RESET%^%^ORANGE%^Longsword%^RESET%^");
   set_name("%^RESET%^%^ORANGE%^Bar%^BOLD%^%^YELLOW%^bar%^BOLD%^%^BLACK%^ic %^RESET%^%^ORANGE%^Longsword%^RESET%^");
   set_id( ({"sword", "longsword", "barbaric longsword"}) );
   set_long ("This longsword is crudely crafted, but in the right hands can become a very deadly weapon. One side of its blade has been serrated, the other side sharper than a razor.");
   set_weight(19);
   set_curr_value("gold", 200);
   set_wc(5+random(4));
   set_ac(2);
   set("skill level", 120);
   set_type("blade");
   set_hit((: weapon_hit :));

}
int weapon_hit(object atk)
{
    int result;
    if(random(100) < 10) {
        write("%^RESET%^%^ORANGE%^The longsword rips peices of "+atk->query_cap_name()+" free from its body.%^RESET%^");
        say("%^RESET%^%^ORANGE%^"+(string)this_player()->query_cap_name()+"'s longsword rips out peices of "+atk->query_cap_name()+".%^RESET%^");
       
result=(random(80))+((this_player()->query_level()));

    }
}
int query_auto_load() { if (this_player()->query_level() > 65) return 1; }
