//by 秦始皇 qsh ednpc tools.
// huangling4.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","皇陵墓道");
	set("long","这里是皇陵墓道，管理员尚未设定本地详细描述。");
	set("exits", ([
		"north" : __DIR__"huangling6",
		"west" : __DIR__"huangling5",
		"south" : __DIR__"huangling3",
	]));
	set("fuben2", 1);
	set("objects", ([
			__DIR__"npc/ehun":5,
	]));
	setup();
}

