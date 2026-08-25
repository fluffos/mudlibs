
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
set_id("choupao", "绸袍");
add_id("cloth");
set_in_room_desc("绸袍(choupao)");
set_long("一件做工精良的绸袍。");
set_gettable(1);
set_slot(TORSO);
set_wearmsg("$N穿上一件$o，俨然出身大户人家，顿时风光起来。\n");
set_removemsg("$N脱下$o，富贵之气顿失，看起来又活像个穷小子。\n");
set_attack_ability(-1);                          
set_defence_power(1);
set_defence_ability(-1);
set_rongmao(0);
set_value(1);
set_currency_type("silver");
}                                               