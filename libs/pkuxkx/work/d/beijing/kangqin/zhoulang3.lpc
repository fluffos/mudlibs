// Room: /d/beijing/kangqin/zhoulang3.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"走廊"NOR);
	set("long",
MAG"这是一条长长的走廊，雕栏画栋，华灯高悬，暗香浮游，装潢华贵而典雅。\n"NOR
	);
	set("exits", ([ /* sizeof() == 2 */
  	"north" : __DIR__"zhoulang1",
 	 "west" : __DIR__"tianjing",
]));

	setup();
	replace_program(ROOM);
}
