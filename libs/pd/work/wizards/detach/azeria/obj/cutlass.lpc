#include <std.h>
inherit WEAPON;
int weapon_hit();
create() {
::create();
set_id(({"cutlass", "satanic cutlass","cutlass"}));
set_name("Satanic Cutlass");
set_short("%^RED%^Sat%^CYAN%^an%^RED%^ic Cut%^CYAN%^la%^RED%^ss");
set_long("%^BOLD%^%^BLACK%^Satanic Cutlass is formed of a rare metal, it was given to the Satanic Warlord to slay the Arch-Angels, the blade shimmers with mystic powers.");
set("skill level", 75);
set_weight(66);
    set_curr_value("gold",150+random(40));
set_wc(15);
set_ac(2);
set_type("blade");
set_hands(1);
set_wield("%^BOLD%^%^BLACK%^Hate for Arch-Angels fills your head.");
set_unwield("%^BOLD%^%^WHITE%^Death to all Arch-Angels.");



set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 69) {
write("%^BOLD%^%^RED%^Your Cutlass rips your foe in half!");
say("%^RED%^Sat%^CYAN%^an%^RED%^ic Cut%^CYAN%^la%^RED%^ss rips its foe in half, spraying blood across the room!");
result=(random(75))+((this_player()->query_level()));
return result;


}
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 return 1;
}
