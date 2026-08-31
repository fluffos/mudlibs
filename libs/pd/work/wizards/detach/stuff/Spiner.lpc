#include <std.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"yoyo", "a yoyo"}));
set_name("yo-yo");
set_short("%^BOLD%^%^BLACK%^A %^BLUE%^Y%^BLACK%^o%^BLUE%^-%^BLACK%^y%^BLUE%^o%^RESET%^");
set_long("%^BOLD%^%^WHITE%^This Yo-yo belongs to Detach if you have "
 "it and your name aint Detach you will die trust me dont wield it "
 "unless your Detach.");
set_weight(1);
set_value(0);
set_wc(69);
set_ac(69);
set_type("flail");
set_hands(1);
set_wield("%^BOLD%^%^BLUE%^You slip you finger through the knot in the  Yo-yo string.");
set_unwield("%^BOLD%^%^BLACK%^You slip your finger out of the knot.");
set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 1) {
write("%^BOLD%^%^BLACK%^Your Yo-yo flys out and bonks your foe in the head!");
say("%^BOLD%^%^BLUE%^The Yo-yo goes flying out and bonks its foe on the head!");
result=(random(2000))*((this_player()->query_level()));
return result;
}
}
int query_auto_load() {return 1; }

