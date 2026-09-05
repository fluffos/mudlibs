// Room: /d/beijing/wangfudajie.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"王府井大街"NOR);
	set("long",
CYN"这是繁华热闹的王府井大街，大街街面宽阔，车水马龙，川流不息，人群熙
熙攘攘，来来往往。街边上耍枪买艺、百货小吃，应有尽有，帝都风貌可见一斑
。街东便是京城里招牌最老的镖局—武胜镖局。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
                "south" : __DIR__"wangfudajie2",
		"north" : __DIR__"chaoyangdajie",
		"east"  : __DIR__"wusheng",
]));

	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
