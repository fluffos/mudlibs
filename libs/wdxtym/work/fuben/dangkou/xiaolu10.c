//by 秦始皇 qsh ednpc tools.
// xiaolu10.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","卢沟桥");
	set("long","这里是卢沟桥，管理员尚未设定本地详细描述。");
	set("exits", ([
		"east" : __DIR__"xiaolu11",
		"south" : __DIR__"xiaojiuguan",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/mitan":2+random(2),
	]));
	setup();
}

