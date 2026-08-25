//maxie.c 麻鞋 by row
#include <sanguo.h>
#include <ansi.h>
#include <mudlib.h>
#include <bodyslots.h>
inherit M_WEARABLE;
inherit M_GETTABLE;
inherit M_DAMAGE_SINK;
void setup()
{
::mudlib_setup();
set_unit("双");
set_id("ma xie", YEL+"麻鞋"+NOR);
add_id("shoes","xie");
set_in_room_desc(YEL+"麻鞋(ma xie)"+NOR);
set_long("一双用麻绳编成的鞋子，穿起来有点扎脚。");
set_wearmsg("$N穿上一双"+YEL+"麻鞋"+NOR+"。\n");
set_removemsg("$N除下一双"+YEL+"麻鞋"+NOR+"。\n");
set_gettable(1);
set_slot(FEET);
}