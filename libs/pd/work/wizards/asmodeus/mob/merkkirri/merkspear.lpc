#include <std.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"spear", "war spear", "merkkirri war spear"}));
set_name("war spear");
set_short("Merkkirri War Spear");
set_long("The spear is nearly seven feet long with a wooden pole and a steel head.  The head of the spear has been fashioned with a hook to rip into flesh as well as parry.");
set_weight(15);
set_curr_value("gold",85);
set_wc(9);
set_ac(2);
set_type("projectile");
set_hands(2);
set_wield("%^BOLD%^CYAN%^The weapon feels well balanced and you know you'll make good use of its hook.%^RESET%^");
set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 85) {
write("%^BOLD%^CYAN%^You hook into your opponent with your spear and rip its flesh %^RESET%^TERRIBLY%^BOLD%^CYAN%^ as you pull it free!%^RESET%^");
say((string)this_player()->query_cap_name()+"%^BOLD%^CYAN%^'s spear hooks into its target and causes a %^RESET%^TERRIBLE%^BOLD%^CYAN%^ wound as it is pulled free.%^RESET%^");
result=(random(20))+((this_player()->query_level()));
return result;
}
}
int query_auto_load() {return 1; }
