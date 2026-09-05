// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", RED+"枫树垄"+NOR);
	set("long", @LONG
这里名叫枫树垄，却没有一棵枫树。
LONG
	);
        set("outdoors", "xitianmu");

	set("exits", ([
		"northwest" : __DIR__"shanlun1",
		"southeast" : __DIR__"cheshui",
		"westup" : __DIR__"shanluw1",
		"eastdown" : __DIR__"xiaoxie",
	]));

	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	setup();
}
