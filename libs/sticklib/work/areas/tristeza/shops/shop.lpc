#include <shop.h>
#include <npc_defs.h>
#include <areas.h>
#include "../DEFS.h"

int
shop_open()
{
    if (!present("shopkeeper", this_object()))
    {
	notify_fail("The shopkeeper is not here.\n");
	return 0;
    }
    return 1;
}


void
create_shop()
{
    string name;
    set(NO_PK);	// Should be PK else how can keepers be defended?-Germ
    set(IN_CITY);
    set_store(AREA_TRISTEZA+"shops/shop_store");
    set_short("Common shop");
    set_long("You are in a common shop. You can buy and sell anything but\
 armours and weapons here. There is a plaque on the wall.");
    set_exits(([
	"east"	: AREA_TRISTEZA+"virtual/S6_6",
	"south"	: AREA_TRISTEZA+"virtual/S5_7"
      ]));
    // This is weird...doesn't work.
    name=(string) (NAMEGEN_C)->random_shkeeper_name();
    //  add_monster(AREA_TRISTEZA + "npc/guard_lieutenant",
    //    "Guard Lieutenant arrives.", 1);
    // add_monster(AREA_TRISTEZA+"npc/guard_captain", "Guard Captain arrives.", 1);
    add_monster( ({ AREA_TRISTEZA+"npc/shopkeeper",
	({ "set_name", name }),
	({ "set_gender", G_MALE }),
	({ "set_alignment", AL_GOOD }),
	({ "set_id", ({ lower_case(name), "shopkeeper",
	    "keeper", name+" the shopkeeper" }) }),
	({ "set_short", name+" the shopkeeper" }),
	({ "set_long", name+" is the keeper of the\
 Common Shop of "+CITY_NAME+"." }),
	({ "set_dead_ob", this_object() })
      }), "Shopkeeper arrives.", 1 );

    add_command("south", "do_not_flee");
    add_command("east", "do_not_flee");
}

status
do_not_flee()
{
    if (this_player()->id("shopkeeper"))
	return 1;
}

int
monster_died(mixed x)
{
    (AREA_TRISTEZA+"shops/shop_store")->set_money(
      (int)(AREA_TRISTEZA+"shops/shop_store")->query_money()+10000);
    return 0;
}

void
init_room()
{
    if (!random(10))(AREA_TRISTEZA+"shops/shop_store")->torch();
}
