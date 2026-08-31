#include <std.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"sword", "crimson sword"}));
set_name("sword");
    set_short("%^RED%^C%^BLUE%^r%^RED%^i%^BLUE%^m%^RED%^s%^BLUE%^o%^RED%^n %^CYAN%^S%^RED%^w%^CYAN%^o%^RED%^r%^CYAN%^d");
set_long("Forged from the great gods themselves, this sword is the "
    "base of all %^RED%^evil.%^RESET%^.");
set_weight(16);
set_value(600);
set_wc(15);
set_ac(1);
set_type("blade");
set_hit( (: this_object(), "weapon_hit" :) );
set_hands(1);
set_wield("Your mind is filled with a sudden rush of %^RED%^e%^BLUE%^v%^RED%^i%^BLUE%^l %^RESET%^and you feel the unexplained urge to %^RED%^k%^BLACK%^i%^RED%^l%^BLACK%^l.");
set_unwield("As you unwield the sword, your mind retreats to the %^BOLD%^%^WHITE%^p%^YELLOW%^e%^WHITE%^a%^YELLOW%^c%^WHITE%^e %^RESET%^it was at before.");
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(102) > 75) {
write("The sword %^RED%^fl%^ORANGE%^ar%^RED%^es%^RESET%^madly, and shoots a %^ORANGE%^fl%^RED%^a%^ORANGE%^me at your foe!");
say((string)this_player()->query_cap_name()+"'s sword %^ORANGE%^f%^YELLOW%^l%^ORANGE%^a%^YELLOW%^r%^ORANGE%^e%^YELLOW%^s %^RESET%^madly.
"+this_player()->query_possessive()+".");
result=(random(5+random(5)-random(5)))*((this_player()->query_level()/5)+1);
result=random(result)+1;
this_player()->add_hp(result);
return result;
}
return 0;
}
int query_auto_load() { if (this_player()->query_level() > 19) return 1; }
