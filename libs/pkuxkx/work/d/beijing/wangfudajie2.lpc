// Room: /d/beijing/wangfudajie.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"王府井大街"NOR);
	set("long",
CYN"这是繁华热闹的王府井大街，大街街面宽阔，车水马龙，川流不息，人群熙
熙攘攘，来来往往。街边上耍枪买艺、百货小吃，应有尽有，帝都风貌可见一斑
。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
                "south" : __DIR__"chongwenmen",
		"north" : __DIR__"wangfudajie",
		"west"  : __DIR__"aobai1",
]));

	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
