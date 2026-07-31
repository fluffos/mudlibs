//by 秦始皇 qsh ednpc tools.
// chasi.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"天皇居"NOR);
	set("long","这里是天皇居住所，管理员尚未设定本地详细描述。");
	set("exits", ([
		"east" : __DIR__"xiaolu7",
	]));
	set("fuben2", 1);
	set("objects", ([
		__DIR__"npc/shouling":1,
		//"fuben/wuguan/obj/baoxiang2":1,	
	]));
	setup();
}

