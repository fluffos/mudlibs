// Room: /d/changle/dating.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIY"大厅"NOR);
	set("long", @long
大厅中一股肃杀威严之气。厅堂极为宽大，能容下数十人之众。只见四周
桌上点着明晃晃的巨烛，正中空着一张虎皮交椅。不时有帮众经过这里，都是
屏息静气地低头走过。
long
	);

	set("exits", ([
                "north" : __DIR__"zoulang4",
                "out" : __DIR__"damen",
	]));

	set("objects", ([
		__DIR__"npc/chen": 1,
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "chen chongzhi" &&  dir != "north" ) return 0;
	return ::valid_leave(me, dir);
}
