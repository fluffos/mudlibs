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
    set_id("guanjin", "纶巾");
    add_id("hat");
    set_in_room_desc("纶巾(guanjin)");
    set_long("一顶用丝带做的头巾。");
    set_gettable(1);
    set_slot(HEAD);
    set_wearmsg("$N戴上一顶$o。\n");
    set_removemsg("$N脱下一顶$o。\n");
    set_attack_ability(0);
    set_defence_power(1);
    set_defence_ability(0);
    set_rongmao(1);
    set_value(1);
    set_currency_type("silver"); 
}
