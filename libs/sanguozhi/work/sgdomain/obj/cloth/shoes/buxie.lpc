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
    set_unit("双");
    set_id("buxie", "布鞋");
    add_id("shoes", "xie");
    set_in_room_desc("布鞋(buxie)");
    set_long("一双普普通通的布鞋。");
    set_gettable(1);
    set_slot(FEET);
    set_wearmsg("$N穿上一双$o。\n");
    set_removemsg("$N脱下一双$o，随手磕掉鞋底的泥土。\n");
    set_attack_ability(-1);
    set_defence_power(1);
    set_defence_ability(-1);
    set_rongmao(0);
}
