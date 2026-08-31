#include <std.h>
inherit WEAPON;
int weapon_hit();
create() {
::create();
set_id(({"slayer", "dragon slayer","sword"}));
set_name("Dragon Slayer");
set_short("%^BOLD%^%^BLACK%^Dragon %^WHITE%^Slayer%^RESET%^");
set_long("%^BOLD%^%^WHITE%^This sword has been passed down from "
"drow to drow for ages, on the handle is the name of the person "
"that holds this sword in the chain at the moment, it reads "
"Meroini, General of the Drow Army.");
set("skill level", 200);
set_weight(25);
set_value(300);
set_wc(20);
set_ac(2);
set_type("blade");
set_hands(1);
set_wield("%^BOLD%^%^BLACK%^You feel Ancient Powers rush into your body.");
set_unwield("%^BOLD%^%^BLACK%^The powers seem to vanish.");



set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 69) {
write("%^BOLD%^%^BLUE%^Your Blade slices through your foe with ease!");
say("%^BOLD%^%^BLACK%^Dragon %^WHITE%^Slayer %^RESET%^%^ORANGE%^slices through its foe with ease!");
result=(random(100))+((this_player()->query_level()));
return result;


}
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 return 1;
}

