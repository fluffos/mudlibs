// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "店铺"+NOR);
	set("long", @LONG
这里是一座店铺，老板从事收购矿石生意，懒洋洋地坐在椅子上。
LONG
	);
        //set("outdoors", "xitianmu");

	set("exits", ([
		//"northwest" : __DIR__"westgc",
		"west" : __DIR__"xiaolu2",
		//"west" : __DIR__"datie",
		//"south" : __DIR__"jiuguan",
	]));

	set("objects", ([
		__DIR__"npc/kuanglaoban" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}
