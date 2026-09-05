// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "祭坛"+NOR);
	set("long", @LONG
这里是畲寨祭拜祖先的祭坛，平时并不让外人进入。
LONG
	);
        set("outdoors", "xitianmu");

	set("exits", ([
		"westdown" : __DIR__"westgc",
		"eastdown" : __DIR__"eastgc",
	]));

	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	set("valid_startroom", 1);
	setup();
}
