#include <std.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"dagger", "shadow dagger"}));
set_name("Shadow Dagger");
set_short ("%^BOLD%^%^BLUE%^Shadow Dagger%^RESET%^");
set_long("%^BOLD%^%^BLUE%^This is one bad ass dagger%^RESET%^");
set_weight(20);
set_value(100);
set_wc(20);
set_ac(1);
set_type("knife");
set_hands(1);
set_wield("The Beast Rages within you.");
set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 90) {
write("%^BOLD%^%^WHITE%^Your Claw slashes across your opponents face openin a wide cut!");
say(" "+this_player()->query_cap_name()+"'s %^BOLD%^%^WHITE%^Claw slashes his opponents face
spraying blood into "+this_player()->query_cap_name()+"'s face!"); 
result=(random(50))+((this_player()->query_level()));
atk->set_paralyzed(random(3));
return result;
}

if (this_player()->query_level() > 30) return 1;
}
