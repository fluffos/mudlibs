//by 秦始皇 qsh ednpc tools.
// junying.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"蒙古军营"NOR);
	set("long","这里是蒙古军营，管理员尚未设定本地详细描述。");
	set("exits", ([
		"east" : __DIR__"bingying3",
		"north" : __DIR__"bingying2",
	]));
	set("fuben2", 1);
	set("objects", ([
	__DIR__"npc/tongling":1,	
   // "fuben/wuguan/obj/baoxiang2":1,	
	]));
	setup();
}

