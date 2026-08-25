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
    set_id("longpao", HIY"龙袍"NOR);
    add_id("pao");
    set_in_room_desc(HIY"龙袍"NOR+"(longpao)");
    set_long("一件绣着九条龙的龙袍");
    set_gettable(1);
    set_slot(TORSO);
    set_wearmsg("$N穿上$o，气势笼罩了整个天空。\n");
    set_removemsg("$N脱下$o。\n");
    set_attack_ability(-1);
    set_defence_power(1);
    set_defence_ability(-1);
    set_rongmao(30);
    set_value(5000);
    set_currency_type("silver");
}
