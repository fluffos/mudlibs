// Room: /d/tangmen/qianliju.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "千里居");
	set("long", @LONG
    这是一间独立的竹屋，掩映在一片梅花中。屋旁清泉淙淙，鸟语花香，环境
极其幽雅。细看屋中各种物件，均为竹制，竹子经过特殊的处理，色泽淡黄，摸上去
手感很舒适。这里就是唐门当家唐老太太的居室。时不时有唐门弟子来向老太太请教
问题。
LONG
	);
	

	set("exits", ([
		
		
		"east" : __DIR__"huayuan12",
	]));
	set("objects", ([
		__DIR__"npc/tang" : 1,
	]));


	setup();
	replace_program(ROOM);
}

