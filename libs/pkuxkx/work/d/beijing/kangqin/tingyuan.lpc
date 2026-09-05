
// Room: /d/beijing/kangqin/tingyuan.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"庭院"NOR);
	set("long",
MAG"这是王府的前院，一道影壁将院子分成两半。东西方各有一
间厢房，那是仆人们住的地方。\n"NOR
	);
	set("exits", ([ /* sizeof() == 4 */
  	"south" : __DIR__"zhongmen",
  	"west" : __DIR__"xixiangfang",
  	"north" : __DIR__"door",
  	"east" : __DIR__"dongxiangfang",
]));
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
