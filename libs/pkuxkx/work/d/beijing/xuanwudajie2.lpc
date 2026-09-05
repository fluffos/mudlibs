
// Room: /d/beijing/west/xuanwudajie2.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"宣武门大街"NOR);
	set("long",
CYN"这是繁华热闹的宣武门大街，大街街面宽阔，车水马龙，
川流不息，人群熙熙攘攘，来来往往。街边上耍枪买艺、百货
小吃，应有尽有，帝都风貌可见一斑。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"caishikou",
  "north" : __DIR__"xuanwudajie",
]));

	setup();
	replace_program(ROOM);
}
