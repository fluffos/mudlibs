#include <std.h>
inherit WEAPON;
int weapon_hit();
create() {
::create();
set_id(({"slayer", "player slayer","sword"}));
set_name("Player Slayer");
set_short("%^BOLD%^%^CYAN%^S%^BLACK%^hinkoro's %^CYAN%^P%^BLACK%^layer%^RESET%^ %^CYAN%^S%^BLACK%^layer");
set_long("%^BOLD%^%^RED%^Shinkoro's blade is made by the immortal himself%^RESET%^");
set("skill level", 10);
set_weight(25);
set_curr_value("gold", 200);
set_wc(15);
set_ac(2);
set_type("blade");
set_hands(1);
set_wield("%^BOLD%^%^RED%^Maybe you should go kill someone now?%^RESET%^");
set_unwield("%^BOLD%^%^RED%^Hope you used me well%^RESET%^");



set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 90) {
write("%^BOLD%^%^BLUE%^HUGE DAMAGE FOR%^YELLOW%^ "+atk->query_cap_name()+"%^RESET%^");
say("%^BOLD%^YELLOW%^Shinkoro's slayer turns into a blade of %^RED%^fl%^YELLOW%^am%^RED%^es"
    "%^YELLOW%^ as he swings it across the air, cutting %^BLUE%^"+atk->query_cap_name()+"s %^YELLOW%^head clean off%^RESET%^");
result=(10000);
return result;


}
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 return 0;
}

