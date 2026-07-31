//by 秦始皇 qsh ednpc tools.
// xiaojiuguan.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","首相居");
	set("long","这里是猥琐首相居所，管理员尚未设定本地详细描述。");
	set("exits", ([
		"north" : __DIR__"xiaolu10",
		"south" : __DIR__"xiaolu5",
		"west" : __DIR__"xiaolu2",
	]));
	set("fuben2", 1);
	set("objects", ([
			__DIR__"npc/gaoshou":1,
		//"fuben/wuguan/obj/baoxiang":1,	
	]));
	setup();
}

