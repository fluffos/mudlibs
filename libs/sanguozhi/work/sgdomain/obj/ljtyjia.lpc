//by ljty on Jan 10 1997 ljtyjia.c
// modified by fire on March 1 1998
#include <sanguo.h>
#include <mudlib.h>
#include <bodyslots.h>
#include <ansi.h>
inherit M_WEARABLE;
inherit M_GETTABLE;
inherit M_DAMAGE_SINK;
void setup()
{
::mudlib_setup();
set_unit("件");
set_id("ljtyjia", HIG+"玲珑细环甲"+NOR);
set_in_room_desc(HIG+"玲珑细环甲(ljtyjia)"+NOR);
set_gettable(1);
set_slot(TORSO);
set_wearmsg("$N穿上$o，整个屋里都映出一片 "+HIG+"绿色的光芒。"+NOR+"\n");
set_removemsg("$N脱下$o，"+HIG+"绿色的光芒"+NOR+"顿时消失了。\n");
set_attack_ability(0);
set_defence_power(250);
set_defence_ability(1000);
set_rongmao(10);
}
