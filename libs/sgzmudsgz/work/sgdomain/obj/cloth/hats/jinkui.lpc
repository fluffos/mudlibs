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
    set_unit("顶");
    set_id("jinkui", "金盔");
    add_id("kui");
    set_in_room_desc("金盔(jinkui)");
    set_long("一顶闪闪发亮的金盔。");
    set_gettable(1);
    set_slot(HEAD);
    set_wearmsg("$N戴上一顶$o。\n");
    set_removemsg("$N脱下一顶$o。\n");
    set_attack_ability(-5);
    set_defence_power(10);
    set_defence_ability(-3);
    set_rongmao(1);
    set_value(1);
    set_currency_type("gold");
}
