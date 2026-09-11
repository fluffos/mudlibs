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
    set_id("tengjia", "藤甲");
    add_id("armor", "jia");
    set_in_room_desc("藤甲(tengjia)");
    set_long("一件藤甲，用油反复浸泡，晾晒了几十遍才制成的，有硬又滑，刀箭难入。");
    set_gettable(1);
    set_slot(ARMORS);
    set_wearmsg("$N穿上一件轻巧的藤甲$o。虽轻却刀箭难入。\n");
    set_removemsg("$N脱下一件$o。\n");
    set_attack_ability(-6);
    set_defence_power(40);
    set_defence_ability(-3);
    set_rongmao(0);
    set_value(1);
    set_currency_type("silver");
}
