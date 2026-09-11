#include <mudlib.h>
#include <bodyslots.h>
#include <ansi.h>
inherit M_WEARABLE;
inherit M_GETTABLE;
inherit M_DAMAGE_SINK;
inherit M_VALUE;
void setup()
{
    ::mudlib_setup();
    set_unit("件");
    set_id("tiejia", "铁甲");
    add_id("armor", "jia");
    set_in_room_desc("铁甲(tiejia)");
    set_long("一件铁甲，甲片由镔铁打造，稍许有些沉重。");
    set_gettable(1);
    set_slot(ARMORS);
    set_wearmsg("$N批上一件$o，豪迈之气顿生。\n");
    set_removemsg("$N脱下$o，觉得轻松多了。\n");
    set_attack_ability(-10);
    set_defence_power(30);
    set_defence_ability(-10);
    set_rongmao(0);
    set_value(1);
    set_currency_type("silver");
}
