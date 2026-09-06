#include <generic_items.h>

inherit "/lib/shop_store";

void
torch()
{
    if (!present("torch", this_object()))
    {
	move_object(clone_object(GENERIC_TORCH), this_object());
	move_object(clone_object(GENERIC_TORCH), this_object());
    }
    if(!present("darkness", this_object()))
    {
	move_object(clone_object(GENERIC_DARK_TORCH), this_object());
	move_object(clone_object(GENERIC_DARK_TORCH), this_object());
    }
}

void
reset_store()
{
    set_money(15000 + sizeof(users()) * 1000);
    torch();
}

void
create_store()
{
    set_money(40000);
}

int
accept_object(object ob)
{
    // Torches are now weapons, but we still want to buy/sell them here. - Germ
    if ( ( ob->is_weapon()&&!ob->id("torch")) || ob -> is_armour()
      || ((int) ob -> query_value() < 20) || ob -> query_thief_item())
	return 0;
    return 1;
}
