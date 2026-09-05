// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "寨中小路"+NOR);
	set("long", @LONG
这里是畲寨中一条小路，铺得并不平整，两侧都是一些商贩和店铺。
LONG
	);
        set("outdoors", "xitianmu");

	set("exits", ([
		"northwest" : __DIR__"westgc",
		"east" : __DIR__"xiaolu2",
		"west" : __DIR__"datie",
		"south" : __DIR__"jiuguan",
	]));

	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}
