#include <std.h>
inherit WEAPON;
int weapon_hit(object atk);
create() {
::create();
set_id(({"cutlass", "forbidden cutlass","sword"}));
set_name("Forbidden Cutlass");
set_short("%^GREEN%^For%^WHITE%^b%^BOLD%^%^WHITE%^i%^RESET%^%^GREEN%^dden Cut%^WHITE%^l%^BOLD%^%^WHITE%^a%^RESET%^%^GREEN%^ss%^RESET%^");
set_long("%^GREEN%^This cutlass is formed from the Anicent Wolf Pack. It is 8 foot long, made of a greenish-silver metal.");
set_weight(20);
    set_curr_value("gold",80+random(40));
set_wc(10);
set_ac(1);
set_type("blade");
set_hands(1);
set_wield("%^GREEN%^The hilt forms to fit your hand.%^RESET%^");
set_unwield("%^BOLD%^%^BLACK%^You feel the need to hold onto the cutlass.%^RESET%^");



set_hit((:weapon_hit:));
}
int weapon_hit(object atk)
{
int result;
if(random(100) > 93) {
write("%^GREEN%^The forbidden cutlass sh%^WHITE%^i%^BOLD%^%^WHITE%^m%^RESET%^%^WHITE%^m%^GREEN%^ers, two blades sh%^ORANGE%^o%^GREEN%^ot from the cutlass, and you spin s%^WHITE%^l%^BOLD%^%^WHITE%^a%^RESET%^%^WHITE%^s%^GREEN%^hi%^WHITE%^n%^GREEN%^g three blades across your foe's neck and chest!!%^RESET%^");
say((string)"%^GREEN%^"+this_player()->query_cap_name()+"'s %^GREEN%^cutlass shimmers, and slashes across its foe's neck and chest!%^RESET%^");
result=(random(20))+((this_player()->query_level())/2);
if(random(100) > 75) {
write("%^GREEN%^Your cutlass slashes into your opponent's face, and they are paralyzed from the wound!%^RESET%^");
say("%^GREEN%^The forbidden cutlass slashes into its foe's face!%^RESET%^");
atk->set_paralyzed(random(3));
return result;
}
}
}
