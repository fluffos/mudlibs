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
    set_id("pixue", "皮靴");
    add_id("shoes", "xue");
    set_in_room_desc("皮靴(pixue)");
    set_long("一双皮靴。");
    set_gettable(1);
    set_slot(FEET);
    set_wearmsg("$N穿上一双$o。\n");
    set_removemsg("$N脱下一双$o。\n");
    set_attack_ability(-1);
    set_defence_power(3);
    set_defence_ability(-1);
    set_rongmao(0);
    set_value(1);
    set_currency_type("silver"); 
}
