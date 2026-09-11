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
    set_id("hechang", "鹤氅");
    add_id("he chang");
    set_in_room_desc("鹤氅(hechang)");
    set_long("一件宽大的鹤氅，穿起来颇有仙风道骨。");
    set_gettable(1);
    set_slot(TORSO);
    set_wearmsg("$N披上$o，看上去仙风道骨，颇有隐士风范。\n");
    set_removemsg("$N脱下一件$o。\n");
    set_attack_ability(0);
    set_defence_power(1);
    set_defence_ability(0);
    set_rongmao(1);
    set_value(1);
    set_currency_type("silver");
}
