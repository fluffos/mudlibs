// Room: /d/beijing/kangqin/garden2.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"小花园"NOR);
	set("long",
MAG"这是一个小花园，虽然花儿不太多，却十分幽雅清洁，显是平日
有人修整打扫。花园东边是一间佛堂。\n"NOR
	);
	set("exits", ([ /* sizeof() == 3 */
 	 "south" : __DIR__"shufang",
 	 "west" : __DIR__"zhoulang7",
  	 "east" : __DIR__"fotang",
]));

	setup();
	replace_program(ROOM);
}
