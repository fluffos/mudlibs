// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", WHT+"山路"+NOR);
	set("long", @LONG
这里是西天目山西侧的一段山间小道，西面是一座畲寨。
LONG
	);
        set("outdoors", "xitianmu");

	set("exits", ([
		"westdown" : __DIR__"shezhai",
		"eastup" : __DIR__"shanluw6",
		//"northeast" : __DIR__"wall1",
		//"eastdown" : __DIR__"fengshu",
	]));

	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}
int valid_leave(object me,string dir)
{
	if (dir=="westdown"&&me->query_dex()<80)
	return notify_fail("这条路下山险绝，你还是不要送死了。\n");
	if (dir=="eastup"&&me->query_dex()<60)
	return notify_fail("这条路上山太困难了，你顿生进退两难之感。\n");
	return ::valid_leave(me,dir);
}