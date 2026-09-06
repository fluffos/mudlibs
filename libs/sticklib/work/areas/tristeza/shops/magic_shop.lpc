#include <shop.h>
#include <npc_defs.h>
#include <areas.h>
#include <city_name.h>

int
shop_open()
{
    if (!present("shopkeeper", this_object()) )
    {
	notify_fail("The shopkeeper is not here.\n");
	return 0;
    }
    return 1;
}

void
create_shop()
{
    set(NO_PK);
    set_store(AREA_TRISTEZA+"shops/magic_store");
    set_short("Ye Olde Magick Shoppe");
    set_long("You are in Ye Olde Magick Shoppe of " CITY_NAME ". This mystic\
 place is lit with black candles. All kinds of strange magical trinkets and\
 components fill the counter, shelves, chests, cupboards and cabinets of the\
 shop. There's a list of potions on the wall.");
    set_exits(([ "north" : AREA_TRISTEZA+"virtual/S2_7" ]));
    set_light_level(LT_DIM);
    set(IN_CITY);
    add_item(({ "list" }), "Ye Olde Magick Potions:\n\
 Brown\t\t\tStrength Restoration\n\
 Blue\t\t\tDexterity Restoration\n\
 Green\t\t\tConstitution Restoration\n\
 Red\t\t\tIntelligence Restoration\n\
 Brilliant White\tComplete Restoration\n\
 Icky Green\t\tPoison Neutralization");
    //  add_monster(AREA_TRISTEZA + "npc/guard_lieutenant",
    //    "Guard Lieutenant arrives.", 1);
    // add_monster(AREA_TRISTEZA+"npc/guard_captain", "Guard Captain arrives.", 1);
    add_monster( ({ AREA_TRISTEZA+"npc/shopkeeper",
	({ "set_name", "blind old woman" }),
	({ "set_id", ({ "shopkeeper", "keeper", "blind",
	    "woman", "old" }) }),
	({ "set_gender", G_FEMALE }),
	({ "set_short", "Blind old woman" }),
	({ "set_long", "This mysterious old woman (known as\
 \"Ye Olde Blinde Woman\") is the keeper of the magic shop." }),
	({ "set_dead_ob", this_object() })
      }), "Blind old woman hobbles in.", 1 );
}

int
monster_died(mixed hilipati)
{
    (AREA_TRISTEZA+"shops/magic_store")->set_money(
      ((int)(AREA_TRISTEZA+"shops/magic_store")->query_money())+10000);
    return 0;
}
