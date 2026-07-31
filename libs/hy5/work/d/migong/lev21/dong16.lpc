
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIM"混沌的迷宫"NOR);
	set("long", RED @LONG
这里是混沌的迷宫,似乎是用来避难的地方。然而地
上到处是一堆堆的骨骸与乾掉的血迹。更让人觉得气氛
显得十分的诡异。
LONG NOR);
set("magicroom",1);set("outdoors","migong");
set("magicset",1);

	set("exits", ([
		"southeast" : __DIR__"dong1"+(random(7)+3),
                "northwest" : __DIR__"dong17",
		"eastnorth" : __DIR__"dong1"+(random(7)+1),
                "westsouth" : __DIR__"dong51",
	]));
if (random(3)==0)
	set("exits", ([
		"eastwest" : __DIR__"dong1"+(random(5)+4),
                "southwest" : __DIR__"dong1"+(random(5)+3),
"south" : __DIR__"dong51",
	]));
if (random(3)==1)
	set("exits", ([
		"south" : __DIR__"dong1"+(random(5)+3),
                "north" : __DIR__"dong1"+(random(5)+3),
"north" : __DIR__"dong51",
	]));

	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
