//by 秦始皇 qsh ednpc tools.
// xiaolu10.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","关外小路");
	set("long","这里是关外小路，管理员尚未设定本地详细描述。");
	set("exits", ([
		"east" : __DIR__"xiaolu11",
		"south" : __DIR__"xiaojiuguan",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/mitan":3+random(2),
	]));
	setup();
}

