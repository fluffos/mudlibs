#include <servers.h>

inherit "/lib/shop_store";

void
reset_store()
{
    if (query_money() < 15000 + sizeof(users()) * 1000)
	set_money(15000 + sizeof(users()) * 1000);
}

void
create_store()
{
    int i;
    for (i = 2 + random(3); i; --i)
	move_object((object) WEAPON_SERVER -> make_random_weapon(15),
	  this_object());
    reset_store();
}

int
accept_object(object ob)
{
    // We dont accept torches, even though they are now weapons. - Germ
    if (!ob->is_weapon() || ob->id("torch") || ((int)ob->query_value() < 10)
      || ob -> query_thief_item()) return 0;
    return 1;
}
