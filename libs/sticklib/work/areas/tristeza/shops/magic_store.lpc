inherit "/lib/shop_store";
#include <areas.h>

void
reset_store()
{
    int i, am;
    object *inv;
    set_money(8000 + sizeof(users()) * 1000);
    inv = all_inventory(this_object());
    am = 0;
    if (inv) {
	for (i = sizeof(inv) - 1; i >= 0; i--)
	    if (inv[i]->id("restoration")) am++;
	// Was !inv[i]->... -+ Doomdark 12-mar-96 +-
	if (am < 3 || random(12) > am) move_object(clone_object(
		AREA_TRISTEZA+"obj/potion_restore"), this_object());
    }
    if (!present("icky green potion", this_object())) {
	move_object(clone_object(
	    AREA_TRISTEZA+"obj/potion_n_poison"), this_object());
    }
}

void
create_store()
{
    set_short("Store room of Ye Olde Magick Shoppe");
    reset_store();
}

int
accept_object(object ob)
{
    if (ob->is_weapon() || ob->query_thief_item()) return 0;
    if (ob->is_armour()) 
    {
	if (member(({ "ring", "amulet", "belt", "cloak", "mask" }),
	    ob->query_type()) == -1 )
	    return 0;
    }
    if (ob->is_drink()) {
	if (!ob->query_soft()) return 0;
    }
    return 1;
}
