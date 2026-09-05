// Room: /d/beijing/zijin/lijingxuan.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY"丽景轩"NOR);
	set("long",
HIC"这是一间华丽别致的房间。但是不经常有人来，只有几个太监在
打扫卫生。\n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
  	"south" : __DIR__"chuxiugong",
]));

	setup();
	replace_program(ROOM);
}
