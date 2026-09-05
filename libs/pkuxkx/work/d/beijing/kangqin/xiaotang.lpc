// Room: /d/beijing/kangqin/xiaotang.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"小堂"NOR);
	set("long",
MAG"这里既阴暗又潮湿，行廊边搭了一个灶台，里面煮着
白菜猪肉。南面是一间牢房，从那里不时传来镣铐拖地的
声音。\n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
  	"north" : __DIR__"shiwu",
  	"south" : __DIR__"laofang",
]));

	setup();
	replace_program(ROOM);
}
