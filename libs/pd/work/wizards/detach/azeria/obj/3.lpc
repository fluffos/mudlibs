#include <std.h>
inherit WEAPON;
int weapon_hit();
create() {
::create();
set_id(({"axe", "war axe","axe"}));
set_name("War Axe");
set_short("%^BOLD%^%^WHITE%^Wa%^BLACK%^r %^BLACK%^A%^WHITE%^xe%^RESET%^");
set_long("This Axe is one of the great axes left from the battle of "
"the Hellion, this battle was over the land of Azeria.");
set("skill level", 75);
set_weight(19);
    set_curr_value("gold",150+random(40));
set_wc(9);
set_ac(2);
set_type("axe");
set_hands(1);
set_wield("%^BOLD%^%^WHITE%^The powers of war surge into you.");
set_unwield("%^BOLD%^%^BLUE%^The powers seem to vanish.");



set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 69) {
write("%^YELLOW%^Your Axe chop's into your foe's Skull!");
say("%^BOLD%^%^WHITE%^Wa%^BLACK%^r %^BLACK%^A%^WHITE%^xe Chop's into its Foe's Skull!");
result=(random(50))+((this_player()->query_level()));
return result;


}
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 return 1;
}
