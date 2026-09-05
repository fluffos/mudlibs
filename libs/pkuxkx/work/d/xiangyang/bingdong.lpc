#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", GRN"远古冰洞"NOR);
	set("long", @LONG
  这里是一座远古时代遗留下来的冰洞,四壁上的冰雪不知过了多少万年,
你站在里面觉得其寒透骨,冰壁上有一处泛着绿光,这恐怕就是人们说的玄冰.

LONG
	);

	set("exits", ([
		"out" : __DIR__"xuefeng2"          
	]));

	set("objects", ([
		__DIR__"npc/obj/xuanbing" : 1,
        ]));

	setup();
}

