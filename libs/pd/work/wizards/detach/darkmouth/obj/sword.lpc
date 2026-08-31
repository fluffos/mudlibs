#include <std.h>
inherit WEAPON;
int weapon_hit();
create() {
::create();
set_id(({"", "dark cutlass","cutlass"}));
set_name("cutlass");
set_short("%^BOLD%^%^BLACK%^D%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^r%^RESET%^%^ORANGE%^k%^BOLD%^%^BLACK%^ C%^RESET%^%^ORANGE%^u%^BOLD%^%^BLACK%^t%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^s%^RESET%^");
set_long("%^BOLD%^%^BLACK%^This Cutlass seems to be a normal cutlass, found around the caverns.%^RESET%^");
set_weight(22);
set_curr_value("gold",90+random(40));
set_wc(9);
set_ac(1);
set_type("blade");
set_hands(1);


set_hit((:this_object(),"weapon_hit":));
}
int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 90) {
write("%^RESET%^%^ORANGE%^Your Cutlass Slices and Hacks its Foe!%^RESET%^");
say("%^RESET%^%^ORANGE%^Dark Cutlass Slices and Hacks its Foe!%^RESET%^");
result=(random(20))+((this_player()->query_level()/2));
return result;


}
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 return 1;
}
