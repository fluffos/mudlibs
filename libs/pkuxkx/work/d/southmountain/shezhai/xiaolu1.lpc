// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "寨中小路"+NOR);
	set("long", @LONG
这里是畲寨中一条小路，铺得并不平整，两侧都是些民居。
LONG
	);
        set("outdoors", "xitianmu");

	set("exits", ([
		"southeast" : __DIR__"eastgc",
		"west" : __DIR__"xiaolu4",
		"east" : __DIR__"minju1",
		"north" : __DIR__"minju2",
	]));

	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}
