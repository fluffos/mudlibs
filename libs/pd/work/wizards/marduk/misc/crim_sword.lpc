#include <std.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"sword", "crimson sword"}));
set_name("sword");
set_short("%^RED%^C%^BLUE%^r%^RED%^i%^BLUE%^m%^RED%^s%^BLUE%^o%^RED%^n %^CYAN%^S%^RED%^w%^CYAN%^o%^RED%^r%^CYAN%^d");
set_long("Forged from the great gods themselves, this sword is the "
    "base of all %^RED%^evil.%^RESET%^  It is rumored that the one who wields "
    "the sword, holds the fate of all humanity in his hand.");
set_weight(16);
set_value(650);
set_wc(16);
set_ac(2);
set_type("blade");
set_hit( (: this_object(), "weapon_hit" :) );
set_hands(1);
set_wield("You feel the %^ORANGE%^p%^RED%^o%^ORANGE%^w%^RED%^e%^ORANGE%^r %^RESET%^of the %^YELLOW%^gods,%^RESET%^ and feel %^BLUE%^i%^YELLOW%^n%^BLUE%^v%^YELLOW%^i%^BLUE%^n%^YELLOW%^c%^BLUE%^i%^YELLOW%^b%^BLUE%^l%^YELLOW%^e%^BLUE%^.");
set_unwield("As you unwield the sword, you feel the absence of a great presence.");
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(102) > 75) {
write("A %^YELLOW%^bolt %^RESET%^of %^YELLOW%^lightning streaks %^RESET%^across the %^BLUE%^%^s%^CYAN%^k%^BLUE%^y%^CYAN%^, %^RESET%^and through your foe!");
say((string)this_player()->query_cap_name()+"'s sword %^ORANGE%^f%^YELLOW%^l%^ORANGE%^a%^YELLOW%^r%^ORANGE%^e%^YELLOW%^s %^RESET%^madly.
to drain energy from "+this_player()->query_possessive()+".");
result=(random(55+random(50)-random(50)))*((this_player()->query_level()/20)+1);
result=random(result)+1;
this_player()->add_hp(result);
return result;
}
return 0;
}
