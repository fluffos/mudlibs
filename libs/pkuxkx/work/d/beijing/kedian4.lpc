#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"西客房"NOR);
	set("long",
CYN"这里是西客房，一个掌柜和两个伙计躲在角落里瑟瑟发抖。\n"NOR
 );
	set("exits", ([
		"east" : __DIR__"kedian5",
	]));
	set("objects", ([
		"/d/beijing/npc/zhanggui":1,
		"/d/beijing/npc/huoji2":2,
	]));
//	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

