#include <food_shop.h>

#include <room_defs.h>

#include "../DEFS.h"
#include <areas.h>
#include <criminal.h>
#include <gender.h>
#include <city_name.h>
#include <generic_items.h>

inherit "/basic/misc/emote";

#define ROOM_DOWN AREA_TRISTEZA "virtual/S7_7"

void
init_foods()
{
    /* ids, short, strength, weight, cost, long desc, eat msg, said msg */
    foods = ({

      ({ "cup", "coffee", "conquistador", "conquistador coffee" }),
      "Cup of Conquistador Coffee",
      -1, CITY_PATH + "obj/coffee", 50,
      "drink", 0, 0,

      ({ "bar of suffeli chocolate", "bar", "suffeli", "chocolate", }),
      "Bar of Suffeli Chocolate",
      -1, AREA_TRISTEZA + "finnclub/suffeli", 100,
      "candy", 0, 0,

      ({ "kossu", "koskenkorva", "pullo", "pullo kossua" }),
      "Pullo Kossua (a bottle of 'Koskenkorva')",
      -1, CITY_PATH + "finnclub/kossu", 650,
      "drink", 0, 0,

    });
}

void
reset_shop()
{
}

void
create_shop()
{
    set_short("The Floating Cafe");
    set_long(
      "You are in the hottest new club on " CITY_NAME ", the Floating Cafe \
above City Well. Through the great crystal windows you can watch \
the busy activity on the city. The bulletin board here is for \
less serious talk - poems, jokes etc. No whines on this board please. \
Type 'list' for menu. Watch out: emote is available too.");

    set_light_level(LT_DIM);
    set_wd(WD_INDOORS);
    set(NO_PK);

    add_object(({ GENERIC_BBOARD,
	({ "set_board", 50, 0, "fcafe_board", 0 }),
      }), 0, 1);

    add_permanent(GENERIC_BENCH);
    add_permanent(GENERIC_TRASHCAN);

    add_exit("down", ROOM_DOWN);
    add_command("emote", "emote_cmd");

    reset_shop();
}

int
shop_open()
{
    return 1;
}
