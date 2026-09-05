#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"神机营广场"NOR);
	set("long",
HIC"暂缺\n"NOR
	);

	set("exits", ([
//		"south" : __DIR__"shangshanjian",
		"east" : __DIR__"shenjiying",
	]));
  set("objects", ([
               __DIR__"npc/zhangyong" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
