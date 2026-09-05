// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", WHT+"畲寨大门"+NOR);
	set("long", @LONG
这里是一座畲族的营寨，不算太大，但也聚集了几百口人。
LONG
	);
        set("outdoors", "xitianmu");

	set("exits", ([
		"eastup" : __DIR__"shanluw5",
		"northeast" : __DIR__"shanluw4",
		"enter" : "/d/southmountain/shezhai/eastgc",
		//"eastdown" : __DIR__"fengshu",
	]));

	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		"/d/southmountain/shezhai/npc/shebing" : 2,
        ]));
	setup();
}
int valid_leave(object me,string dir)
{
	if (dir=="enter"&&!userp(me)) return notify_fail("");
	if (dir=="eastup"&&me->query_dex()<60)
	return notify_fail("这条路上山太困难了，你顿生进退两难之感。\n");
	return ::valid_leave(me,dir);
}