// Room: /d/beijing/xuanwudajie.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"宣武门大街"NOR);
	set("long",
CYN"这是繁华热闹的宣武门大街，大街街面宽阔，车水马龙，川流不息，人群熙
熙攘攘，来来往往。街边上耍枪买艺、百货小吃，应有尽有，帝都风貌可见一斑。\n"NOR
	);
	set("exits", ([
		  "north" : __DIR__"xuanwumen",
		  "south" : __DIR__"xuanwudajie2",

]));

	set("outdoors", "beijing");


	setup();
	replace_program(ROOM);
}
