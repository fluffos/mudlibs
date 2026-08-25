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
    set_id("jinjia", "金甲");
    add_id("armor","jia");
    set_in_room_desc("金甲(jinjia)");
    set_long("一件精心打造的金甲，只有身经百战的将军才有资格穿。");
    set_gettable(1);
    set_slot(ARMORS);
    set_wearmsg("$N披上一件$o，眼睛炯炯放光，真是仪表堂堂，威风凛凛。\n");
    set_removemsg("$N脱下一件$o。\n");
    set_attack_ability(-10);
    set_defence_power(50);
    set_defence_ability(-5);
    set_rongmao(1);
    set_value(1);
    set_currency_type("gold");
}
