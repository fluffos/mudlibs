#include <std.h>
inherit WEAPON;

void create() {
    ::create();
    set_hit((:this_object(), "weapon_hit":));
    set_name("sign");
    set_short("a street sign");
    set_long("The street sign is rather bulky but it'll do to blubgeon someone with. "
             "You think you may also like to read the sign.");
    set_id(({"sign", "street sign"}));
    set_mass(7);
    set_value(1);
    set_type("blunt");
    set_hands(1);
    set_wc(7);
    set_ac(1);

}
int weapon_hit()
{
    int res;
    object atk;
    atk = (object)environment()->query_current_attacker();
    if(random(100) > 30) {
	write ("%^BOLD%^You smack your opponent in the head.%^RESET%^");
	say((string)this_player()->query_cap_name()+"'s street sign bangs on their opponents noggin! %^RED%^*PRANG!!!*%^RESET%^");
	res=(2);
	return res;
	return 0;
    }
}


