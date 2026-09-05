#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY"御茶膳房"NOR);
	set("long",
HIC"这是外膳房。走入房内，只见门旁摆着三个装得满满的大水缸，烟熏
火燎的炉子上放着大茶壶，一个小太监坐在炉旁默默的烧火，身旁放着堆
干柴，几个年龄稍大的太监围在厨桌上忙碌的洗菜切肉，一边坐着个白白
胖胖的太监在指指点点，一付总管的模样。\n"NOR
	);
	set("kitchen", 1);
	set("exits", ([
        "west" : __DIR__"jianting",
	]));
	set("objects",([
	"/d/beijing/npc/wenyoudao":1,
	]));

	setup();
	replace_program(ROOM);
}
