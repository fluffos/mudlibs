//by 秦始皇 qsh ednpc tools.
// shishi3.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"石室"NOR);
	set("long","这里是石室，管理员尚未设定本地详细描述。");
	set("exits", ([
		"west" : __DIR__"huangling11",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/lihun":5,	
	]));
	setup();
}

