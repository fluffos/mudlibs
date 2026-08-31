#include <std.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"mace", "obsidian mace"}));
set_name("mace");
set_short("an obsidian mace");
set_long("A deadly mace with a knobbed head made of pure obsidian.  It is extremely powerful and extremely manacing.");
set_weight(14);
set_value(300);
set("skill level", 140);
set_wc(16);
set_ac(1);
set_type("blunt");
set_hands(1);
set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 93) {
write("The head of your mace slams deeply into your opponent!%^RESET%^");
say((string)"The head of "+this_player()->query_cap_name()+"'s mace slams deeply into "+this_player()->query_current_attacker()->query_cap_name()+"!%^RESET%^");
result=(random(25))+((this_player()->query_level()));
this_player()->add_sp(result)/2;
return result;
}
}
int query_auto_load() {
if(this_player()->query_level() < 35) return 0;
return 1; }
