
#include <sanguo.h>
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
set_id("kaijia", "细铠甲");
add_id("cloth");
set_in_room_desc("细铠甲(kaijia)");
set_long("一件细铠甲，坚固但轻巧，穿在衣服里也看不出，用于防身最好。");
set_gettable(1);
set_slot(ARMORS);
set_wearmsg("$N穿上$o，妥妥贴贴 ，正好合身。\n");
set_removemsg("$N脱下一件$o。\n");
set_attack_ability(-4);                           
set_defence_power(20);
set_defence_ability(-2);
set_rongmao(0);
set_value(1);
set_currency_type("gold");
}                                               