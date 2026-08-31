//Gepetto

#include <std.h>
inherit WEAPON;

void create() {
::create();
set_name("sign");
set_short("a street sign");
set_long("The street sign is rather bulky but it'll do do blubgeon someone
with. You think you may also like to read the sign.");
set_id(({"sign"}));
set_mass(20);
set_value(0);
set_type("blunt");
set_hands(2);
set_ac(2);
}
int weapon_hit()
{
    int result;
    object atk;
    atk = (object)this_player()->query_current_attacker();
    if(random(102) > 85) {
       say((string)this_player()->query_cap_name()+
	  "'s street sign bangs on their opponents noggin' *PRANG!!!*"
	  +this_player()->query_possessive()+".");
    }
}
