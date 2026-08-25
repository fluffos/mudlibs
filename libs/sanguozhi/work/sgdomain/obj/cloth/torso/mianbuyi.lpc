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
        set_id("mianbuyi","棉布衣");
        add_id("mian", "cloth");
        set_in_room_desc("棉布衣(buyi)");
        set_long("一件棉做的衣服，穿起来较舒服而保暖。");
        set_gettable(1);
        set_slot(ARMORS);
        set_wearmsg("$N穿上一件棉布衣。\n");
        set_removemsg("$N脱去一件棉布衣。\n");
        set_attack_ability(-2);
        set_defence_power(0);
        set_defence_ability(-2);
        set_rongmao(0);
}
