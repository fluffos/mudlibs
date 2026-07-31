//by 秦始皇 qsh ednpc tools.
// bingying9.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","蒙古兵营");
	set("long","这里是蒙古兵营，管理员尚未设定本地详细描述。");
	set("exits", ([
		"south" : __DIR__"bingying11",
		"north" : __DIR__"bingying10",
		"west" : __DIR__"qianshao2",
	]));
	set("fuben2", 1);
	set("objects", ([
	__DIR__"npc/bing":2,
	]));
	setup();
}

