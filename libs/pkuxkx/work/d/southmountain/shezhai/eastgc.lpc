// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "东广场"+NOR);
	set("long", @LONG
这里是畲寨的东广场，零零散散坐着几个老人。西面地势渐高，是一座祭坛。
LONG
	);
        set("outdoors", "shezhai");

	set("exits", ([
		"out" : "/d/southmountain/xitianmu/shezhai",
		"southwest" : __DIR__"xiaolu2",
		"northwest" : __DIR__"xiaolu1",
		"westup" : __DIR__"jitan",
	]));

	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}
