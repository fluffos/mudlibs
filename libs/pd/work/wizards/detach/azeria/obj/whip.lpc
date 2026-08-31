#include <std.h>
inherit WEAPON;
int weapon_hit();
create() {
::create();
set_id(({"whip", "bone whip","whip"}));
set_name("Bone Whip");
set_short("%^BOLD%^%^BLACK%^B%^RESET%^on%^BOLD%^%^BLACK%^e W%^RESET%^%^hi%^BOLD%^%^BLACK%^p");
set_long("%^BOLD%^%^WHITE%^This Whip was formed from the bones of a Arch-Angel.");
set("skill level", 75);
set_weight(20);
    set_curr_value("gold",150+random(40));
set_wc(10);
set_ac(2);
set_type("flail");
set_hands(1);
set_wield("%^BOLD%^%^WHITE%^Angelic Screams echo through the room.");
set_unwield("%^BOLD%^%^WHITE%^The Screams vanish.");



set_hit((:this_object(),"weapon_hit":));
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(100) > 69) {
write("%^BOLD%^%^WHITE%^Your whip tangles around your opponent!");
say("%^BOLD%^%^BLACK%^B%^RESET%^on%^BOLD%^%^BLACK%^e W%^RESET%^%^hi%^BOLD%^%^BLACK%^p tangles around its opponent!");
result=(random(45))+((this_player()->query_level()));
return result;


}
}

int query_auto_load()
{                                  
 if (wizardp(this_player())) return 1;
 return 1;
}
