#include <std.h>
inherit WEAPON;

int weapon_hit();
create() {
::create();
set_id(({"sword", "the sword"}));
set_name("sword");
set_short("%^BOLD%^%^WHITE%^The %^BOLD%^%^BLUE%^Sword%^RESET%^.");
set_long("%^BOLD%^%^WHITE%^ THis Sword is amde by a %^BOLD%^%^BLUE%^ "
         "Great %^bold%^%^WHITE%^Man from a far land.");
set_weight(20);
set_value(-69);
set_wc(9);
set_ac(2);
set_type("blade");
set_hit( (: this_object(), "weapon_hit" :) );
set_hands(1);
set_wield("%^BOLD%^%^WHITE%^Your Hands Seem to hit the floor.");
}

int weapon_hit()
{
int result;
object atk;
atk = (object)this_player()->query_current_attacker();
if(random(102) > 75) {
write("%^BOLD%^%^BLACK%^Y%^BLUE%^o%^BLACK%^u%^BLUE%^r%^BLACK%^S%^BLUE%^w%^BLACK%^o%^BLUE%^r%^BLACK%^d%^BLUE%^ S%^BLACK%^m%^BLUE%^a%^BLACK%^s%^BLUE%^h%^BLACK%^e%^BLUE%^s %^BLACK%^ Y%^BLUE%^o%^BLACK%^u%^BLUE%^r %^BLACK%^F%^BLUE%^o%^BLACK%^e.");
say((string)this_player()->query_cap_name ()+"'s Sword%^BOLD%^%^BLUE%^Strikes and slash's madly.
"+this_player()->query_possessive()+".");
result=(random(55+random(50)-random(50)))*((this_player()->query_level()/20)+1);

result=random(result)+1;
this_player()->add_hp(result);
return result;
}
return 0;
}
