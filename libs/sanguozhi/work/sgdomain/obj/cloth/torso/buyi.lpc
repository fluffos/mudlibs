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
    set_id("buyi", "布衣");
    add_id("cloth");
    set_in_room_desc("布衣(buyi)");
    set_long("一件平常的白布衣，虽然是粗布做的，倒也耐穿。");
    set_gettable(1);
    set_slot(TORSO);
    set_wearmsg("$N穿上一件普普通通的$o。 \n");
    set_removemsg("$N抖抖嗦嗦脱下一件$o。不会是穷得想去当吧？\n");
    set_attack_ability(-1);
    set_defence_power(1);
    set_defence_ability(-1);
    set_rongmao(0);
}
