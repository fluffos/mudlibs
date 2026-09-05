// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "民居"+NOR);
	set("long", @LONG
这里是一座典型的畲族民房，一色的粉墙黛瓦，清秀隽永。
LONG
	);
        set("outdoors", "xitianmu");

	set("exits", ([
		//"southwest" : __DIR__"westgc",
		//"east" : __DIR__"xiaolu1",
		"south" : __DIR__"xiaolu1",
		//"north" : __DIR__"minju4",
	]));

	set("objects", ([
		__DIR__"npc/shemin" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}
