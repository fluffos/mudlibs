//by 秦始皇 qsh ednpc tools.
// huangling.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","皇陵墓道");
	set("long","这里是皇陵墓道，管理员尚未设定本地详细描述。");
	set("exits", ([
		"east" : __DIR__"huangling3",
		"south" : __DIR__"huangling2",
		"west" : __DIR__"enter",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/ehun":5,
	]));
	setup();
}

