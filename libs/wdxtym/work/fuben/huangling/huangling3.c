//by 秦始皇 qsh ednpc tools.
// huangling3.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","皇陵墓道");
	set("long","这里是皇陵墓道，管理员尚未设定本地详细描述。");
	set("exits", ([
		"north" : __DIR__"huangling4",
		"west" : __DIR__"huangling",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/ehun":5,	
	]));
	setup();
}

