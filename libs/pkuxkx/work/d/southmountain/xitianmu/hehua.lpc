// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIM"荷花"+HIG+"塘"+NOR);
	set("long", @LONG
这里叫做荷花塘，是一处大水塘，夏天里就会开满荷花。
LONG
	);
        set("outdoors", "xitianmu");

	set("exits", ([
		"west" : __DIR__"houshan",
		//"southdown" : __DIR__"houshan",
		"northwest" : __DIR__"luoshi",
		//"out" : __DIR__"shanlus1",
	]));

	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}
