//By River@Sj

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "石门");
	set("long", @LONG
这里是石门，是西夏的采石场，当地没有别的物产，只有遍地的白玉石，
西夏王宫里的玉石地板就是用这里出产的白玉石铺成的。时常有大批的苦力被
官府征到这儿来，没日没夜的开采白玉石矿，许多人倒下后就没有再站起来。
北面有一座寺庙。
LONG );
	set("exits", ([
                "west" : __DIR__"gccheng",
                "south"     : __DIR__"hongsx",
		"north"     : __DIR__"wufosi",
	]));
	set("objects", ([
		__DIR__"npc/xixiabing" : 1,
		__DIR__"npc/caishiren" : 2,
	]));

	set("outdoors", "兰州");
	setup();
}
