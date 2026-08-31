#include <std.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"axe", "four bladed axe", "merkkirri axe"}));
set_name("four bladed axe");
set_short("%^BLUE%^Four Bladed Axe%^RESET%^");
set_long("This large axe is made of black steel and is topped with two intersecting blades forming an 'X' pattern.  The axe is quite heavy and menacing to behold.");
set_weight(20);
set_value(300);
set_wc(15); // i lowered the wc, a little too uch for that easy to get -- seeker
set_ac(1);
set_type("axe");
set_hands(2);
set_wield("You feel your %^RED%^pulse%^RESET%^ quicken as you wield the axe.");
set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 85) {
write("%^BOLD%^GREEN%^Your axe slams deeply into your opponent spraying %^BOLD%^RED%^blood%^RESET%^BOLD%^GREEN%^ everwhere!%^RESET%^");
say((string)this_player()->query_cap_name()+"%^BOLD%^GREEN%^'s axe slams deeply into its target spraying %^BOLD%^RED%^blood%^RESET%^BOLD%^GREEN%^ everywhere!%^RESET%^");
result=(random(25))+((this_player()->query_level()));
return result;
}
}
int query_auto_load() {return 1; }
