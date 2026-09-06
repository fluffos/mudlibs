#include <weapon.h>

#define REMOVE_STRING "Just 'unwield' the stick to get rid of it."

void
create_weapon()
{
    set_value(0);
    set_name("pointed stick");
    set_id(({ "stick", "pointed stick" }));
    set_short("Pointed stick");
    set_long("POINTED STICK?!?!? FRUITS AIN'T GOOD ENOUGH FOR YA??? This is\
 probably the worst weapon around, although it's still better than bare\
 hands. Type 'remove pointed stick' or 'remove pointed' to get rid of it.");
    set_wc(5);
    set_weight(1);
}

status
drop(status silent)
{
    if (query_verb() == "quit") return 0;
    if (!silent) this_player()->tell_me(
	  REMOVE_STRING);
    return -1;
}

status
unwield_me(object who, status silent)
{
    mixed x;
    if (x = ::unwield_me(who, silent))
    {
	if (environment()) environment()->tell_me(
	      "There's a small puff of logic as the pointed stick disappears!");
	destruct(this_object());
    }
    return x;
}
