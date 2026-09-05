//D:\xkx\d\liuxiu-shanzhuang\tiejiangpu.c铁匠铺
// labaz 2012/10/22
#include <ansi.h>
inherit ROOM;
#include "newbie_village.h"

void create()
{
	set("short", "铁匠铺");
	set("long", @LONG
这是一家简陋的打铁铺，中心摆着一个火炉，炉火把四周照得一片通红，你
一走进去就感到浑身火热。墙角堆满了已完工和未完工的菜刀、铁锤、铁棍、匕
首、盔甲等物。一位铁匠满头大汗挥舞着铁锤，专心致志地在打铁。
LONG
	);

	set("exits", ([
		"east" : __DIR__"jizhen-xiaodao2",
	]));
	set("objects", ([
		__DIR__"npc/laohu" : 1,
	]));

	setup();
}

void init()
{
	add_action("show_quest","quest");
}


int valid_leave(object me, string dir)
{
	if( present("wang tiejiang", me) )
		return notify_fail("你想拐带铁匠做什么？欺负老实人啊！\n");

	return ::valid_leave(me, dir);
}

