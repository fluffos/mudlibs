#include <std.h>
inherit WEAPON;

int weapon_hit(object atk);
create() {
::create();
set_id(({"axe", "four bladed axe", "merkkirri axe"}));
set_name("four bladed axe");
set_short("%^BLUE%^Four Bladed Axe%^RESET%^");
set_long("This large axe is made of black steel and is topped with two intersecting blades forming an 'X' pattern.  The axe is quite heavy and menacing to behold.");
set_weight(20);
set_curr_value("gold",100);
set_wc(10);
set_ac(1);
set_hands(2);
set_type("axe");
set_wield("You feel your %^RED%^pulse%^RESET%^ quicken as you wield the axe.");
set_hit((:weapon_hit:));
}

int weapon_hit(object atk)
{
int result;
if(random(100) > 90) {
write("%^BOLD%^GREEN%^Your axe slams deeply into your opponent spraying %^BOLD%^RED%^blood%^RESET%^BOLD%^GREEN%^ everwhere!%^RESET%^");
say((string)this_player()->query_cap_name()+"%^BOLD%^GREEN%^'s axe slams deeply into its target spraying %^BOLD%^RED%^blood%^RESET%^BOLD%^GREEN%^ everywhere!%^RESET%^");
result=(random(15))+((this_player()->query_level()/2));
return result;
}
}
int query_auto_load() {
  if(this_player()->query_level() < 18) return 0;
  return 1;
}
