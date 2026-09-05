// Room: /d/beijing/kangqin/zhoulang9.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"走廊"NOR);
	set("long",
MAG"这是一条长长的走廊，雕栏画栋，华灯高悬，暗香浮游，装潢华贵而典雅。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"northeast" : __DIR__"zhoulang8",
 	 "south" : __DIR__"majiu",
]));

	setup();
	replace_program(ROOM);
}
