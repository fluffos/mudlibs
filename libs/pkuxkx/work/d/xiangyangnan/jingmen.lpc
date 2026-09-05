// Room: /wudang/guandao1.c
// llin 11.25.1997 

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", WHT"荆门"NOR);
	set("long",
"荆门是荆州的门户，往南不远就是荆州了，往北通往襄阳。\n"

	);
        set("outdoors", "xiangyangnan");

	set("exits", ([
		"north" : "/d/xiangyang/mroad1",
		"south" : __DIR__"guandao2",
	]));

	setup();
}

