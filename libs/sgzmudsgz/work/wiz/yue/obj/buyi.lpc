//by fire on Jan 10 1997 
#include <sanguo.h>
#include <mudlib.h>
#include <bodyslots.h>
#include <ansi.h>
inherit M_VALUE;
inherit M_WEARABLE;
inherit M_GETTABLE;
inherit M_DAMAGE_SINK;
void setup()
{
::mudlib_setup();
set_unit("件");
set_id("buyi", "布衣");
add_id("buyi","linen","cloth");
set_in_room_desc("布衣(cloth)");
set_long("一件破布衣，上面打满了补丁。");
set_gettable(1);
set_slot(TORSO);
set_wearmsg("$N穿上一件$o。\n");
set_removemsg("$N脱下一件$o。\n");
    set_currency_type("silver");
    set_value(3);
}
