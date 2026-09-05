// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "西广场"+NOR);
	set("long", @LONG
这里是畲寨的西广场，零零散散坐着几个老人。东面地势渐高，是一座祭坛。
LONG
	);
        set("outdoors", "xitianmu");

	set("exits", ([
		"out" : __DIR__"shezhai2",
		"northeast" : __DIR__"xiaolu4",
		"southeast" : __DIR__"xiaolu3",
		"eastup" : __DIR__"jitan",
	]));

	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}
