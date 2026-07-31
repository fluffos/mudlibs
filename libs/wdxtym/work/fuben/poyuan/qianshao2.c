//by 秦始皇 qsh ednpc tools.
// qianshao2.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"蒙古前哨"NOR);
	set("long","这里是蒙古前哨，管理员尚未设定本地详细描述。");
	set("exits", ([
		"east" : __DIR__"bingying9",
		"north" : __DIR__"bingying8",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/duizhang":1,
 // "fuben/wuguan/obj/baoxiang":1,			
	]));
	setup();
}

