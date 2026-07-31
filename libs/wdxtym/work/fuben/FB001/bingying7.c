//by 秦始皇 qsh ednpc tools.
// bingying7.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","蒙古兵营");
	set("long","这里是蒙古兵营，管理员尚未设定本地详细描述。");
	set("exits", ([
		"north" : __DIR__"bingying6",
	]));
	set("fuben2", 1);
	set("objects", ([
	__DIR__"npc/bing":1,
	]));
	setup();
}

