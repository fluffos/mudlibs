#include <std.h>
inherit WEAPON;
int weapon_hit();
create() {
::create();
set_id(({"axe", "warlord axe","axe"}));
set_name("Warlord Axe");
set_short("%^BOLD%^%^WHITE%^War%^BLACK%^lo%^WHITE%^rd %^BLACK%^A%^WHITE%^x%^BLACK%^e");
set_long("%^BOLD%^%^WHITE%^This Axe was formed in the depths of hell, it was given to a warlord, who promised to kill all Arch-Angels.");
set("skill level", 75);
set_weight(20);
    set_curr_value("gold",150+random(40));
set_wc(14);
set_ac(2);
set_type("axe");
set_hands(1);
set_wield("%^BOLD%^%^WHITE%^Death to all Arch-Angels.");
set_unwield("%^BOLD%^%^WHITE%^You wipe the Arch-Angel blood from your axe..");



set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 69) {
write("%^BOLD%^%^WHITE%^Your axe Smash's into your opponent break everyone bone is his body!");
say("%^BOLD%^%^WHITE%^War%^BLACK%^lo%^WHITE%^rd %^BLACK%^A%^WHITE%^x%^BLACK%^e smash's into its opponent, your hear bones crack!");
result=(random(73))+((this_player()->query_level()));
return result;


}
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 return 1;
}
